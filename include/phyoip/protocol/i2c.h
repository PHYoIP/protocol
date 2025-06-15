/*
author          Oliver Blaser
date            15.06.2025
copyright
*/

#ifndef IG_PHYOIP_PROTOCOL_I2C_H
#define IG_PHYOIP_PROTOCOL_I2C_H

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif



#if 0 // tbd, some ideas

#include <bits/endian.h> // TODO make portable and move up to other includes

#define PHYOIP_I2C_HDR_SIZE (1)

/**
 * @brief I2C protocol header.
 */
struct phyoip_i2chdr
{
    uint8_t addr; //!< I2C device address

// flags
#if __BYTE_ORDER == __LITTLE_ENDIAN // TODO make portable
    unsigned int read   :1;
    unsigned int ___res :7;
#elif __BYTE_ORDER == __BIG_ENDIAN  // TODO make portable
    unsigned int ___res :7;
    unsigned int read   :1;
#else
#error "unknown endianness"
    // Doxygen also will end up here
    unsigned int read   :1; //!< **bit 0** read/nWrite bit
    unsigned int ___res :7; //!< bit 1..7 reserved for future use
#endif

    uint8_t hsize;  //!< header size in bytes
    uint16_t dsize; //!< data size in bytes

} __attribute__((packed));

#endif



#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_I2C_H
