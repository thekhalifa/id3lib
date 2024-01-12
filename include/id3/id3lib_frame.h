// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_FRAME_H_
#define _ID3LIB_FRAME_H_

#include "id3/globals.h" //has <stdlib.h> "id3/sized_types.h"

class ID3_Field;
class ID3_FrameImpl;
class ID3_Reader;
class ID3_Writer;

class ID3_CPP_EXPORT ID3_Frame
{
    ID3_FrameImpl *_impl;
public:

    class Iterator
    {
    public:
        virtual ID3_Field       *GetNext()       = 0;
    };

    class ConstIterator
    {
    public:
        virtual const ID3_Field *GetNext()       = 0;
    };

public:
    ID3_Frame (ID3_FrameID id = ID3FID_NOFRAME);
    ID3_Frame (const ID3_Frame &);

    virtual ~ID3_Frame();

    void        Clear();

    bool        SetID (ID3_FrameID id);
    ID3_FrameID GetID() const;

    ID3_Field  *GetField (ID3_FieldID name) const;

    size_t      NumFields() const;

    const char *GetDescription() const;
    static const char *GetDescription (ID3_FrameID);

    const char *GetTextID() const;

    ID3_Frame  &operator= (const ID3_Frame &);
    bool        HasChanged() const;
    bool        Parse (ID3_Reader &);
    void        Render (ID3_Writer &) const;
    size_t      Size();
    bool        Contains (ID3_FieldID fld) const;
    bool        SetSpec (ID3_V2Spec);
    ID3_V2Spec  GetSpec() const;

    bool        SetCompression (bool b);
    bool        GetCompression() const;
    size_t      GetDataSize() const;

    bool        SetEncryptionID (uchar id);
    uchar       GetEncryptionID() const;

    bool        SetGroupingID (uchar id);
    uchar       GetGroupingID() const;

    Iterator  *CreateIterator();
    ConstIterator *CreateIterator() const;

    // Deprecated
    ID3_Field  &Field (ID3_FieldID name) const;
    //ID3_Field*  GetFieldNum(size_t) const;
};

#endif /* _ID3LIB_FRAME_H_ */

