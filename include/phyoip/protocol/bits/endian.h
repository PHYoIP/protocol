/*
author          Oliver Blaser
date            16.06.2025
copyright
*/

#ifndef IG_PHYOIP_PROTOCOL_BITS_ENDIAN_H
#define IG_PHYOIP_PROTOCOL_BITS_ENDIAN_H

#ifndef _MSC_VER
#include <endian.h>
#endif


#ifdef __cplusplus
extern "C" {
#endif



//======================================================================================================================
// pre checks, warning

#ifndef _MSC_VER

#ifdef PHYOIP_BIG_ENDIAN
#warning "PHYOIP_BIG_ENDIAN is already defined"
#define ___PHYOIP_BIG_ENDIAN_was_defined (1)
#endif

#ifdef PHYOIP_LITTLE_ENDIAN
#warning "PHYOIP_LITTLE_ENDIAN is already defined"
#define ___PHYOIP_LITTLE_ENDIAN_was_defined (1)
#endif

#endif // _MSC_VER



//======================================================================================================================
// detect and define

#ifdef _MSC_VER

#if (defined(_M_PPC))
#define PHYOIP_BIG_ENDIAN (1)
#endif

#if (defined(_M_IX86) || defined(_M_X64) || defined(_M_AMD64) || defined(_M_ARM) || defined(_M_ARM64))
#define PHYOIP_LITTLE_ENDIAN (1)
#endif

#else //_MSC_VER

#if ((defined(__BYTE_ORDER) && (__BYTE_ORDER == __BIG_ENDIAN)) || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __BIG_ENDIAN__)) || defined(__ARMEB__) || \
     defined(__AARCH64EB__) || defined(__THUMBEB__) || defined(_MIPSEB) || defined(__MIPSEB) || defined(__MIPSEB__))
#define PHYOIP_BIG_ENDIAN (1)
#endif

#if ((defined(__BYTE_ORDER) && (__BYTE_ORDER == __LITTLE_ENDIAN)) || (defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __LITTLE_ENDIAN__)) || \
     defined(__ARMEL__) || defined(__AARCH64EL__) || defined(__THUMBEL__) || defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__))
#define PHYOIP_LITTLE_ENDIAN (1)
#endif

#endif //_MSC_VER



//======================================================================================================================
// post checks

#if ((PHYOIP_BIG_ENDIAN && ___PHYOIP_LITTLE_ENDIAN_was_defined) || (PHYOIP_LITTLE_ENDIAN && ___PHYOIP_BIG_ENDIAN_was_defined) || \
     (PHYOIP_BIG_ENDIAN && PHYOIP_LITTLE_ENDIAN))
#error "fatal error, please (if possible) investigate and open an issue"
#endif

#undef ___PHYOIP_BIG_ENDIAN_was_defined
#undef ___PHYOIP_LITTLE_ENDIAN_was_defined

#if (!PHYOIP_BIG_ENDIAN && !PHYOIP_LITTLE_ENDIAN)
#error "unknown endianness"
#endif



#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_BITS_ENDIAN_H
