// SPDX-License-Identifier: LGPL-3.0-only

#include "header.h"

#if defined HAVE_CONFIG_H
#include <config.h>
#endif

bool ID3_Header::SetSpec (ID3_V2Spec spec)
{
    static ID3_Header::Info _spec_info[] = {
        // Warning, EXT SIZE are minimum sizes, they can be bigger
        // SIZEOF SIZEOF SIZEOF IS EXT EXT  EXPERIM
        // FRID   FRSZ   FRFL   HEADER SIZE BIT
        {  3,     3,     0,     false, 0,   false }, // ID3V2_2_0
        {  3,     3,     0,     true,  8,   true  }, // ID3V2_2_1
        {  4,     4,     2,     false, 10,  false }, // ID3V2_3_0
        {  4,     4,     2,     false, 6,   false }  // ID3V2_4_0
    };

    bool changed = false;

    if (spec < ID3V2_EARLIEST || spec > ID3V2_LATEST) {
        changed = _spec != ID3V2_UNKNOWN;
        _spec = ID3V2_UNKNOWN;
        _info = NULL;
    } else {
        changed = _spec != spec;
        _spec = spec;
        _info = &_spec_info[_spec - ID3V2_EARLIEST];
    }

    _changed = _changed || changed;
    return changed;
}

