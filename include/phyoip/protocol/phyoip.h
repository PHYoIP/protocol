/*
author          Oliver Blaser
date            15.06.2025
copyright
*/

#ifndef IG_PHYOIP_PROTOCOL_PHYOIP_H
#define IG_PHYOIP_PROTOCOL_PHYOIP_H

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif



#define PHYOIP_PROTOCOL_VERSION_MAJ (1)
#define PHYOIP_PROTOCOL_VERSION_MIN (0)



#define PHYOIP_HDR_IDENTIFIER_SIZE (11) // FF FF FF FF 50 48 59 6F 49 50 00

/**
 * @brief PHYoIP protocol header.
 */
struct phyoiphdr
{
    char identifier[PHYOIP_HDR_IDENTIFIER_SIZE];
    uint8_t vermaj; //!< PHYoIP protocol version major
    uint8_t vermin; //!< PHYoIP protocol version minor
    uint8_t proto;  //!< protocol
    uint8_t hsize;  //!< header size in bytes
} __attribute__((packed));

//! \name Packet Type
/// @{
#define PHYOIP_PROTO_CMP  (0x01) //!< control message protocol
#define PHYOIP_PROTO_SPI  (0x02)
#define PHYOIP_PROTO_UART (0x0A)
#define PHYOIP_PROTO_I2C  (0x0C)
/// @}



#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_PHYOIP_H
