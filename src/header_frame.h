// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_HEADER_FRAME_H_
#define _ID3LIB_HEADER_FRAME_H_

#include "header.h"
#include "field.h"

struct ID3_FrameDef;

class ID3_FrameHeader : public ID3_Header
{
public:

    enum {
        TAGALTER    = 1 << 15,
        FILEALTER   = 1 << 14,
        READONLY    = 1 << 13,
        COMPRESSION = 1 <<  7,
        ENCRYPTION  = 1 <<  6,
        GROUPING    = 1 <<  5
    };

    ID3_FrameHeader() : _frame_def (NULL), _dyn_frame_def (false) { ; }
    virtual ~ID3_FrameHeader()
    {
        this->Clear();
    }

    /* */ size_t        Size() const;
    /* */ bool          Parse (ID3_Reader &);
    /* */ void          Render (ID3_Writer &) const;
    /* */ bool          SetFrameID (ID3_FrameID id);
    /* */ ID3_FrameID   GetFrameID() const;
    const char         *GetTextID() const;
    const ID3_FrameDef *GetFrameDef() const;
    /* */ bool          Clear();
    ID3_FrameHeader    &operator= (const ID3_FrameHeader &);

    bool SetCompression (bool b)
    {
        return this->SetFlags (COMPRESSION, b);
    }
    bool SetEncryption (bool b)
    {
        return this->SetFlags (ENCRYPTION, b);
    }
    bool SetGrouping (bool b)
    {
        return this->SetFlags (GROUPING, b);
    }

    bool GetCompression() const
    {
        return _flags.test (COMPRESSION);
    }
    bool GetEncryption() const
    {
        return _flags.test (ENCRYPTION);
    }
    bool GetGrouping() const
    {
        return _flags.test (GROUPING);
    }
    bool GetReadOnly() const
    {
        return _flags.test (READONLY);
    }
    void                SetUnknownFrame (const char *);

protected:
    bool                SetFlags (uint16 f, bool b)
    {
        bool changed = _flags.set (f, b);
        _changed = _changed || changed;
        return changed;
    }
// following is moved to public due to bug unknownframes corrupting a tag
//  void                SetUnknownFrame(const char*);

private:
    ID3_FrameDef       *_frame_def;
    bool                _dyn_frame_def;
}
;

#endif /* _ID3LIB_HEADER_FRAME_ */
