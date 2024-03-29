// SPDX-License-Identifier: LGPL-3.0-only

#if defined HAVE_CONFIG_H
#include <config.h>
#endif

//#include <string.h>
#include "tag.h"
#include "frame_impl.h"
#include "field_impl.h"
#include "frame_def.h"
#include "field_def.h"

ID3_FrameImpl::ID3_FrameImpl (ID3_FrameID id)
    : _changed (false),
      _bitset(),
      _fields(),
      _encryption_id ('\0'),
      _grouping_id ('\0')
{
    this->SetSpec (ID3V2_LATEST);
    this->SetID (id);
}

ID3_FrameImpl::ID3_FrameImpl (const ID3_FrameHeader &hdr)
    : _changed (false),
      _bitset(),
      _fields(),
      _hdr (hdr),
      _encryption_id ('\0'),
      _grouping_id ('\0')
{
    this->_InitFields();
}

ID3_FrameImpl::ID3_FrameImpl (const ID3_Frame &frame)
    : _changed (false),
      _bitset(),
      _fields(),
      _encryption_id ('\0'),
      _grouping_id ('\0')
{
    *this = frame;
}

ID3_FrameImpl::~ID3_FrameImpl()
{
    Clear();
}

bool ID3_FrameImpl::_ClearFields()
{
    for (iterator fi = _fields.begin(); fi != _fields.end(); ++fi) {
        delete (ID3_FieldImpl *) *fi;
    }

    _fields.clear();
    _bitset.reset();

    _changed = true;
    return true;
}

void ID3_FrameImpl::Clear()
{
    this->_ClearFields();
    _hdr.Clear();
    _encryption_id   = '\0';
    _grouping_id     = '\0';
}

void ID3_FrameImpl::_InitFields()
{
    const ID3_FrameDef *info = _hdr.GetFrameDef();

    if (NULL == info) {
        // log this
        ID3_Field *fld = new ID3_FieldImpl (ID3_FieldDef::DEFAULT[0]);
        _fields.push_back (fld);
        _bitset.set (fld->GetID());
    } else {

        for (size_t i = 0; info->aeFieldDefs[i]._id != ID3FN_NOFIELD; ++i) {
            ID3_Field *fld = new ID3_FieldImpl (info->aeFieldDefs[i]);
            _fields.push_back (fld);
            _bitset.set (fld->GetID());
        }

        _changed = true;
    }
}

bool ID3_FrameImpl::SetID (ID3_FrameID id)
{
    bool changed = (this->GetID() != id);

    if (changed) {
        this->_SetID (id);
        _changed = true;
    }

    return changed;
}

bool ID3_FrameImpl::_SetID (ID3_FrameID id)
{
    bool changed = this->_ClearFields();
    changed = _hdr.SetFrameID (id) || changed;
    this->_InitFields();
    return changed;
}

bool ID3_FrameImpl::SetSpec (ID3_V2Spec spec)
{
    return _hdr.SetSpec (spec);
}

ID3_V2Spec ID3_FrameImpl::GetSpec() const
{
    return _hdr.GetSpec();
}

ID3_Field *ID3_FrameImpl::GetField (ID3_FieldID fieldName) const
{
    ID3_Field *field = NULL;

    if (this->Contains (fieldName)) {
        for (const_iterator fi = _fields.begin(); fi != _fields.end(); ++fi) {
            if ( (*fi)->GetID() == fieldName) {
                field = *fi;
                break;
            }
        }
    }

    return field;
}

size_t ID3_FrameImpl::NumFields() const
{
    return _fields.size();
}

size_t ID3_FrameImpl::Size()
{
    size_t bytesUsed = _hdr.Size();

    if (this->GetEncryptionID()) {
        bytesUsed++;
    }

    if (this->GetGroupingID()) {
        bytesUsed++;
    }

    ID3_TextEnc enc = ID3TE_ASCII;

    for (iterator fi = _fields.begin(); fi != _fields.end(); ++fi) {
        if (*fi && (*fi)->InScope (this->GetSpec())) {
            if ( (*fi)->GetID() == ID3FN_TEXTENC) {
                enc = (ID3_TextEnc) (*fi)->Get();
            } else {
                (*fi)->SetEncoding (enc);
            }

            bytesUsed += (*fi)->BinSize();
        }
    }

    return bytesUsed;
}


bool ID3_FrameImpl::HasChanged() const
{
    bool changed = _changed;

    for (const_iterator fi = _fields.begin(); fi != _fields.end(); ++fi) {
        if (*fi && (*fi)->InScope (this->GetSpec())) {
            changed = (*fi)->HasChanged();
        }
    }

    return changed;
}

ID3_FrameImpl &
ID3_FrameImpl::operator= (const ID3_Frame &rFrame)
{
    ID3_FrameID eID = rFrame.GetID();
    this->SetID (eID);
    ID3_Frame::ConstIterator *ri = rFrame.CreateIterator();
    iterator li = this->begin();

    while (li != this->end()) {
        ID3_Field *thisFld = *li++;
        const ID3_Field *thatFld = ri->GetNext();

        if (thisFld != NULL && thatFld != NULL) {
            *thisFld = *thatFld;
        }
    }

    delete ri;
    this->SetEncryptionID (rFrame.GetEncryptionID());
    this->SetGroupingID (rFrame.GetGroupingID());
    this->SetCompression (rFrame.GetCompression());
    this->SetSpec (rFrame.GetSpec());
    _changed = false;

    return *this;
}

const char *ID3_FrameImpl::GetDescription (ID3_FrameID id)
{
    ID3_FrameDef *myFrameDef = ID3_FindFrameDef (id);

    if (myFrameDef != NULL) {
        return myFrameDef->sDescription;
    }

    return NULL;
}

const char *ID3_FrameImpl::GetDescription() const
{
    const ID3_FrameDef *def = _hdr.GetFrameDef();

    if (def) {
        return def->sDescription;
    }

    return NULL;
}

