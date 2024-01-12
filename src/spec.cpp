// SPDX-License-Identifier: LGPL-3.0-only

#if defined HAVE_CONFIG_H
#include <config.h>
#endif

#include "spec.h"

ID3_V2Spec ID3_VerRevToV2Spec (uchar ver, uchar rev)
{
    ID3_V2Spec spec = ID3V2_UNKNOWN;

    if (2 == ver) {
        if (0 == rev) {
            spec = ID3V2_2_0;
        } else if (1 == rev) {
            spec = ID3V2_2_1;
        }
    } else if (3 == ver) {
        if (0 == rev) {
            spec = ID3V2_3_0;
        }
    } else if (4 == ver) {
        if (0 == rev) {
            spec = ID3V2_4_0;
        }
    }

    return spec;
}

uchar ID3_V2SpecToVer (ID3_V2Spec spec)
{
    uchar ver = 0;

    switch (spec) {
    case ID3V2_2_0:
    case ID3V2_2_1:
        ver = 2;
        break;

    case ID3V2_3_0:
        ver = 3;
        break;

    case ID3V2_4_0:
        ver = 4;
        break;

    default:
        break;
    }

    return ver;
}

uchar ID3_V2SpecToRev (ID3_V2Spec spec)
{
    uchar rev = 0;

    switch (spec) {
    case ID3V2_4_0:
        rev = 0;
        break;

    case ID3V2_3_0:
        rev = 0;
        break;

    case ID3V2_2_1:
        rev = 1;
        break;

    case ID3V2_2_0:
        rev = 0;
        break;

    default:
        break;
    }

    return rev;
}

