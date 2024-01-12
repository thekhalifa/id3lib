// SPDX-License-Identifier: LGPL-3.0-only

#ifndef _ID3LIB_UTILS_H_
#define _ID3LIB_UTILS_H_

#if defined HAVE_CONFIG_H
#include <config.h>
#endif

#include "id3/id3lib_streams.h"
#include "id3/globals.h" //has <stdlib.h> "id3/sized_types.h"
#include "id3/id3lib_strings.h"

namespace dami
{
#ifdef  MAXPATHLEN
#  define ID3_PATH_LENGTH   (MAXPATHLEN + 1)
#elif   defined (PATH_MAX)
#  define ID3_PATH_LENGTH   (PATH_MAX + 1)
#else   /* !MAXPATHLEN */
#  define ID3_PATH_LENGTH   (2048 + 1)
#endif  /* !MAXPATHLEN && !PATH_MAX */

#ifndef min
    template<typename T>
    const T &min (const T &a, const T &b)
    {
        return (a < b) ? a : b;
    }
#endif

#ifndef max
    template<typename T>
    const T &max (const T &a, const T &b)
    {
        return (b < a) ? a : b;
    }
#endif

#ifndef mid
    template<typename T>
    const T &mid (const T &lo, const T &mid, const T &hi)
    {
        return max (lo, min (mid, hi));
    }
#endif

#ifndef abs
    template<typename T>
    T abs (const T &a)
    {
        return (a < T (0)) ? -a : a;
    }
#endif

    size_t ID3_C_EXPORT renderNumber (uchar *buffer, uint32 val, size_t size = sizeof (uint32));
    String ID3_C_EXPORT renderNumber (uint32 val, size_t size = sizeof (uint32));

    String ID3_C_EXPORT toString (uint32 val);
    WString ID3_C_EXPORT toWString (const unicode_t[], size_t);

    size_t ID3_C_EXPORT ucslen (const unicode_t *unicode);
    String ID3_C_EXPORT convert (String data, ID3_TextEnc, ID3_TextEnc);

    // file utils
    size_t ID3_C_EXPORT getFileSize (fstream &);
    size_t ID3_C_EXPORT getFileSize (ifstream &);
    size_t ID3_C_EXPORT getFileSize (ofstream &);
    ID3_Err ID3_C_EXPORT createFile (String, fstream &);
    ID3_Err ID3_C_EXPORT openWritableFile (String, fstream &);
    ID3_Err ID3_C_EXPORT openWritableFile (String, ofstream &);
    ID3_Err ID3_C_EXPORT openReadableFile (String, fstream &);
    ID3_Err ID3_C_EXPORT openReadableFile (String, ifstream &);

};

#endif /* _ID3LIB_UTILS_H_ */

