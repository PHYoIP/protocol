/*
author          Oliver Blaser
date            15.06.2025
copyright       MIT - Copyright (c) 2026 Oliver Blaser
*/

#ifndef IG_PHYOIP_PROTOCOL_I2C_H
#define IG_PHYOIP_PROTOCOL_I2C_H

#include <stdint.h>

#include "bits/endian.h"
#include "bits/macros.h"


#ifdef __cplusplus
extern "C" {
#endif

PHYOIP_PACK_PUSH();

#if 0 // tbd, just some ideas

/*! \addtogroup grp_protocol_i2c
 * @{
 */



/**
 * @brief I2C protocol header.
 */
struct phyoip_i2chdr
{
    uint8_t hsize;  ///< header size in bytes
    uint16_t dsize; ///< data size in bytes

    uint8_t addr; ///< I2C device address

// flags
#if PHYOIP_BIG_ENDIAN
    uint8_t ___res :7;
    uint8_t read   :1;
#elif PHYOIP_LITTLE_ENDIAN
    uint8_t read   :1;
    uint8_t ___res :7;
#else
#error "unknown endianness"
    uint8_t ___res :7; ///< bit 1..7 reserved for future use
    uint8_t read   :1; ///< **bit 0** read/nWrite bit
#endif

} PHYOIP_ATTR_PACKED;



/*! @} */

#endif

PHYOIP_PACK_POP();

#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_I2C_H
