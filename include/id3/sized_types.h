// SPDX-License-Identifier: LGPL-3.0-only

/**
 ** This file defines size-specific typedefs based on the macros defined in
 ** limits.h
 **/

#ifndef _SIZED_TYPES_H_
#define _SIZED_TYPES_H_

#include <limits.h>

/* define our datatypes */

/* Define 8-bit types */
#if UCHAR_MAX == 0xff

typedef unsigned char   uint8;
typedef signed char      int8;

#else
#error This machine has no 8-bit type; report compiler, and the contents of your limits.h to the persons in the AUTHORS file
#endif /* UCHAR_MAX == 0xff */

/* Define 16-bit types */
#if UINT_MAX == 0xffff

typedef unsigned int    uint16;
typedef int              int16;

#elif USHRT_MAX == 0xffff

typedef unsigned short  uint16;
typedef short            int16;

#else
#error This machine has no 16-bit type; report compiler, and the contents of your limits.h to the persons in the AUTHORS file
#endif /* UINT_MAX == 0xffff */

/* Define 32-bit types */
#if UINT_MAX == 0xfffffffful

typedef unsigned int    uint32;
typedef int              int32;

#elif ULONG_MAX == 0xfffffffful

typedef unsigned long   uint32;
typedef long             int32;

#elif USHRT_MAX == 0xfffffffful

typedef unsigned short  uint32;
typedef short            int32;

#else
#error This machine has no 32-bit type; report compiler, and the contents of your limits.h to the persons in the AUTHORS file
#endif /* UINT_MAX == 0xfffffffful */

#endif /* _SIZED_TYPES_H_ */

