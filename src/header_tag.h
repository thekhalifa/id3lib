// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_HEADER_TAG_H_
#define _ID3LIB_HEADER_TAG_H_

#include "header.h"

class ID3_TagHeader : public ID3_Header
{
public:

    enum {
        HEADER_FLAG_UNSYNC       = 1 << 7,
        HEADER_FLAG_EXTENDED     = 1 << 6,
        HEADER_FLAG_EXPERIMENTAL = 1 << 5,
        HEADER_FLAG_FOOTER       = 1 << 4
    };

    enum {
        EXT_HEADER_FLAG_BIT1  = 1 << 7,
        EXT_HEADER_FLAG_BIT2  = 1 << 6,
        EXT_HEADER_FLAG_BIT3  = 1 << 5,
        EXT_HEADER_FLAG_BIT4  = 1 << 4
    };

    ID3_TagHeader() : ID3_Header() { ; }
    virtual ~ID3_TagHeader() { ; }
    ID3_TagHeader (const ID3_TagHeader &rhs) : ID3_Header()
    {
        *this = rhs;
    }

    bool   SetSpec (ID3_V2Spec);
    size_t Size() const;
    void Render (ID3_Writer &) const;
    bool Parse (ID3_Reader &);
    void ParseExtended (ID3_Reader &);
    ID3_TagHeader &operator= (const ID3_TagHeader &hdr)
    {
        this->ID3_Header::operator= (hdr);
        return *this;
    }

    bool SetUnsync (bool b)
    {
        bool changed = _flags.set (HEADER_FLAG_UNSYNC, b);
        _changed = _changed || changed;
        return changed;
    }
    bool GetUnsync() const
    {
        return _flags.test (HEADER_FLAG_UNSYNC);
    }
    bool SetExtended (bool b)
    {
        bool changed = _flags.set (HEADER_FLAG_EXTENDED, b);
        _changed = _changed || changed;
        return changed;
    }
    bool GetExtended() const
    {
        return _flags.test (HEADER_FLAG_EXTENDED);
    }
    bool SetExperimental (bool b)
    {
        bool changed = _flags.set (HEADER_FLAG_EXPERIMENTAL, b);
        _changed = _changed || changed;
        return changed;
    }
    bool GetExperimental() const
    {
        return _flags.test (HEADER_FLAG_EXPERIMENTAL);
    }
    bool SetFooter (bool b)
    {
        bool changed = _flags.set (HEADER_FLAG_FOOTER, b);
        _changed = _changed || changed;
        return changed;
    }
    bool GetFooter() const
    {
        return _flags.test (HEADER_FLAG_FOOTER);
    }

    // id3v2 tag header signature:  $49 44 33 MM mm GG ss ss ss ss
    // MM = major version (will never be 0xFF)
    // mm = minor version (will never be 0xFF)
    // ff = flags byte
    // ss = size bytes (less than $80)
    static const char *const ID;
    enum {
        ID_SIZE        = 3,
        MAJOR_OFFSET   = 3,
        MINOR_OFFSET   = 4,
        FLAGS_OFFSET   = 5,
        SIZE_OFFSET    = 6,
        SIZE           = 10 // does not include extented headers
    };

};

#endif /* _ID3LIB_HEADER_TAG_H_ */
