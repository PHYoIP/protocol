/*
author          Oliver Blaser
date            31.01.2026
copyright       MIT - Copyright (c) 2026 Oliver Blaser
*/

#ifndef IG_PHYOIP_PROTOCOL_BITS_MACROS_H
#define IG_PHYOIP_PROTOCOL_BITS_MACROS_H



#ifdef _MSC_VER

#define PHYOIP_ATTR_PACKED
#define PHYOIP_PACK_PUSH() __pragma(pack(push, 1))
#define PHYOIP_PACK_POP()  __pragma(pack(pop))

#else // assuming GCC or compatible

#define PHYOIP_ATTR_PACKED __attribute__((packed))
#define PHYOIP_PACK_PUSH()
#define PHYOIP_PACK_POP()

#endif // _MSC_VER



#endif // IG_PHYOIP_PROTOCOL_BITS_MACROS_H
