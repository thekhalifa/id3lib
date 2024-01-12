// SPDX-License-Identifier: LGPL-3.0-only

#include "id3/globals.h" //has <stdlib.h> "id3/sized_types.h"

#if defined HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef _cplusplus
extern "C"
{
#endif

    const char *const  ID3LIB_NAME           = _ID3LIB_NAME;
    const char *const  ID3LIB_VERSION        = _ID3LIB_VERSION;
    const char *const  ID3LIB_FULL_NAME      = _ID3LIB_FULLNAME;
    const int          ID3LIB_MAJOR_VERSION  = _ID3LIB_MAJOR_VERSION;
    const int          ID3LIB_MINOR_VERSION  = _ID3LIB_MINOR_VERSION;
    const int          ID3LIB_PATCH_VERSION  = _ID3LIB_PATCH_VERSION;
    const int          ID3LIB_INTERFACE_AGE  = _ID3LIB_INTERFACE_AGE;
    const int          ID3LIB_BINARY_AGE     = _ID3LIB_BINARY_AGE;

#ifdef _cplusplus
}
#endif

