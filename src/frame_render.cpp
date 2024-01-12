// SPDX-License-Identifier: LGPL-3.0-only

#if defined HAVE_CONFIG_H
#include <config.h>
#endif



//#include <string.h>
#include <memory.h>
#include <zlib.h>

#include "tag.h"
#include "frame_impl.h"
#include "id3/io_decorators.h" //has "readers.h" "io_helpers.h" "utils.h"
#include "io_strings.h"
#include "io_helpers.h"

using namespace dami;

namespace
{
    void renderFields (ID3_Writer &writer, const ID3_FrameImpl &frame)
    {
        ID3_TextEnc enc = ID3TE_ASCII;

        for (ID3_FrameImpl::const_iterator fi = frame.begin(); fi != frame.end(); ++fi) {
            ID3_Field *fld = *fi;

            if (fld != NULL && fld->InScope (frame.GetSpec())) {
                if (fld->GetID() == ID3FN_TEXTENC) {
                    enc = static_cast<ID3_TextEnc> (fld->Get());
                    ID3D_NOTICE ("id3::v2::renderFields(): found encoding = " << enc);
                } else {
                    fld->SetEncoding (enc);
                }

                fld->Render (writer);
            }
        }
    }
}

void ID3_FrameImpl::Render (ID3_Writer &writer) const
{
    // Return immediately if we have no fields, which (usually) means we're
    // trying to render a frame which has been Cleared or hasn't been initialized
    if (!this->NumFields()) {
        return;
    }

    ID3_FrameHeader hdr;

    const size_t hdr_size = hdr.Size();

    // 1.  Write out the field data to the buffer, with the assumption that
    //     we won't be decompressing, since this is the usual behavior
    String flds;
    io::StringWriter fldWriter (flds);
    size_t origSize = 0;

    if (!this->GetCompression()) {
        renderFields (fldWriter, *this);
        origSize = flds.size();
        ID3D_NOTICE ("ID3_FrameImpl::Render(): uncompressed fields");
    } else {
        io::CompressedWriter cr (fldWriter);
        renderFields (cr, *this);
        cr.flush();
        origSize = cr.getOrigSize();
        ID3D_NOTICE ("ID3_FrameImpl::Render(): compressed fields, orig size = " <<
                     origSize);
    }

    size_t fldSize = flds.size();
    ID3D_NOTICE ("ID3_FrameImpl::Render(): field size = " << fldSize);
// No need to not write empty frames, why would we not? They can be used to fill up padding space
// which is even recommended in the id3 spec.
//  if (fldSize == 0)
//  {
//    ID3D_WARNING ( "ID3_FrameImpl::Render(): no field data" );
//    return;
//  }

    // determine which flags need to be set
    uchar eID = this->GetEncryptionID(), gID = this->GetGroupingID();
    ID3_FrameID fid = this->GetID();

    if (fid == ID3FID_NOFRAME) {
        const char *tid = this->GetTextID();
        hdr.SetUnknownFrame (tid);
    } else {
        hdr.SetFrameID (fid);
    }

    hdr.SetEncryption (eID > 0);
    hdr.SetGrouping (gID > 0);
    hdr.SetCompression (origSize > fldSize);
    hdr.SetDataSize (fldSize + ( (hdr.GetCompression() ? 4 : 0) +
                                 (hdr.GetEncryption()  ? 1 : 0) +
                                 (hdr.GetGrouping()    ? 1 : 0)));

    // write out the header
    hdr.Render (writer);

    if (fldSize != 0) {
        // No-man's land!  Not part of the header, not part of the data
        if (hdr.GetCompression()) {
            io::writeBENumber (writer, origSize, sizeof (uint32));
            ID3D_NOTICE ("ID3_FrameImpl::Render(): frame is compressed, wrote origSize = " << origSize);
        }

        if (hdr.GetEncryption()) {
            writer.writeChar (eID);
            ID3D_NOTICE ("ID3_FrameImpl::Render(): frame is compressed, encryption id = " << eID);
        }

        if (hdr.GetGrouping()) {
            writer.writeChar (gID);
            ID3D_NOTICE ("ID3_FrameImpl::Render(): frame is compressed, grouping id = " << gID);
        }

        // Write the field data
        writer.writeChars (flds.data(), fldSize);
    }

    _changed = false;
}

