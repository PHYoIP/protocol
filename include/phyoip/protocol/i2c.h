/*
author          Oliver Blaser
date            15.06.2025
copyright
*/

#ifndef IG_PHYOIP_PROTOCOL_I2C_H
#define IG_PHYOIP_PROTOCOL_I2C_H

#include <stdint.h>

#include "bits/endian.h"


#ifdef __cplusplus
extern "C" {
#endif
#if 0 // tbd, just some ideas

/*! \addtogroup grp_protocol_i2c
 * @{
 */



/**
 * @brief I2C protocol header.
 */
struct phyoip_i2chdr
{
    uint8_t hsize;  //!< header size in bytes
    uint16_t dsize; //!< data size in bytes

    uint8_t addr; //!< I2C device address

// flags
#if PHYOIP_BIG_ENDIAN
    unsigned int ___res :7;
    unsigned int read   :1;
#elif PHYOIP_LITTLE_ENDIAN
    unsigned int read   :1;
    unsigned int ___res :7;
#else
#error "unknown endianness"
    // Doxygen also will end up here
    unsigned int ___res :7; //!< bit 1..7 reserved for future use
    unsigned int read   :1; //!< **bit 0** read/nWrite bit
#endif

} __attribute__((packed));



/*! @} */

#endif
#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_I2C_H
