// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_FRAME_DEF_H_
#define _ID3LIB_FRAME_DEF_H_

#include "id3/globals.h" //has <stdlib.h> "id3/sized_types.h"

struct ID3_FieldDef;

// Structure used for defining how frames are defined internally.
struct ID3_FrameDef {
    ID3_FrameID   eID;
    char          sShortTextID[3 + 1];
    char          sLongTextID[4 + 1];
    bool          bTagDiscard;
    bool          bFileDiscard;
    const ID3_FieldDef *aeFieldDefs;
    const char   *sDescription;
};

#endif
