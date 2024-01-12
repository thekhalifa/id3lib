// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_SPEC_H_
#define _ID3LIB_SPEC_H_

#include "id3/globals.h" //has <stdlib.h> "id3/sized_types.h"

ID3_V2Spec ID3_VerRevToV2Spec (uchar ver, uchar rev);
uchar      ID3_V2SpecToVer (ID3_V2Spec spec);
uchar      ID3_V2SpecToRev (ID3_V2Spec spec);

#endif /* _ID3LIB_SPEC_H_ */

