// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_FIELD_DEF_H_
#define _ID3LIB_FIELD_DEF_H_

#include "id3/globals.h" //has <stdlib.h> "id3/sized_types.h"

struct ID3_FieldDef {
    ID3_FieldID   _id;
    ID3_FieldType _type;
    size_t        _fixed_size;
    ID3_V2Spec    _spec_begin;
    ID3_V2Spec    _spec_end;
    flags_t       _flags;
    ID3_FieldID   _linked_field;
    static const ID3_FieldDef *DEFAULT;
};

#endif

