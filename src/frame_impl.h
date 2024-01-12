// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_FRAME_IMPL_H_
#define _ID3LIB_FRAME_IMPL_H_

#include <vector>
#ifndef HAVE_BITSET
#include "id3/id3lib_bitset"
#else
#include <bitset>
#endif
#include "id3/id3lib_frame.h"
#include "header_frame.h"

class ID3_FrameImpl
{
    typedef std::bitset<ID3FN_LASTFIELDID> Bitset;
    typedef std::vector<ID3_Field *> Fields;
public:
    typedef Fields::iterator iterator;
    typedef Fields::const_iterator const_iterator;
public:
    ID3_FrameImpl (ID3_FrameID id = ID3FID_NOFRAME);
    ID3_FrameImpl (const ID3_FrameHeader &);
    ID3_FrameImpl (const ID3_Frame &);

    /// Destructor.
    virtual ~ID3_FrameImpl();

    void        Clear();

    bool        SetID (ID3_FrameID id);
    ID3_FrameID GetID() const
    {
        return _hdr.GetFrameID();
    }

    ID3_Field  *GetField (ID3_FieldID name) const;

    size_t      NumFields() const;

    const char *GetDescription() const;
    static const char *GetDescription (ID3_FrameID);

    const char *GetTextID() const
    {
        return _hdr.GetTextID();
    }

    ID3_FrameImpl  &operator= (const ID3_Frame &);
    bool        HasChanged() const;
    bool        Parse (ID3_Reader &);
    void        Render (ID3_Writer &) const;
    size_t      Size();
    bool        Contains (ID3_FieldID fld) const
    {
        return _bitset.test (fld);
    }
    bool        SetSpec (ID3_V2Spec);
    ID3_V2Spec  GetSpec() const;

    /** Sets the compression flag within the frame.  When the compression flag is
     ** is set, compression will be attempted.  However, the frame might not
     ** actually be compressed after it is rendered if the "compressed" data is
     ** no smaller than the "uncompressed" data.
     **/
    bool        SetCompression (bool b)
    {
        return _hdr.SetCompression (b);
    }
    /** Returns whether or not the compression flag is set.  After parsing a tag,
     ** this will indicate whether or not the frame was compressed.  After
     ** rendering a tag, however, it does not actually indicate if the frame is
     ** compressed rendering.  It only indicates whether or not compression was
     ** attempted.  A frame will not be compressed, even whent the compression
     ** flag is set, if the "compressed" data is no smaller than the
     ** "uncompressed" data.
     **/
    bool        GetCompression() const
    {
        return _hdr.GetCompression();
    }
    size_t      GetDataSize() const
    {
        return _hdr.GetDataSize();
    }

    bool SetEncryptionID (uchar id)
    {
        bool changed = id != _encryption_id;
        _encryption_id = id;
        _changed = _changed || changed;
        _hdr.SetEncryption (true);
        return changed;
    }
    uchar GetEncryptionID() const
    {
        return _encryption_id;
    }
    bool SetGroupingID (uchar id)
    {
        bool changed = id != _grouping_id;
        _grouping_id = id;
        _changed = _changed || changed;
        _hdr.SetGrouping (true);
        return changed;
    }
    uchar GetGroupingID() const
    {
        return _grouping_id;
    }

    iterator         begin()
    {
        return _fields.begin();
    }
    iterator         end()
    {
        return _fields.end();
    }
    const_iterator   begin() const
    {
        return _fields.begin();
    }
    const_iterator   end()   const
    {
        return _fields.end();
    }

protected:
    bool        _SetID (ID3_FrameID);
    bool        _ClearFields();
    void        _InitFields();
    void        _InitFieldBits();
    void        _UpdateFieldDeps();

private:
    mutable bool        _changed;    // frame changed since last parse/render?
    Bitset      _bitset;             // which fields are present?
    Fields      _fields;
    ID3_FrameHeader _hdr;            //
    uchar       _encryption_id;      // encryption id
    uchar       _grouping_id;        // grouping id
}
;

#endif /* _ID3LIB_FRAME_IMPL_H_ */
