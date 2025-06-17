/*
author          Oliver Blaser
date            15.06.2025
copyright
*/

#ifndef IG_PHYOIP_PROTOCOL_SPI_H
#define IG_PHYOIP_PROTOCOL_SPI_H

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif
#if 0 // tbd, just some ideas

/*! \addtogroup grp_protocol_spi
 * @{
 */



/**
 * @brief SPI protocol header.
 */
struct phyoip_spihdr
{
    uint8_t hsize;  //!< header size in bytes
    uint16_t dsize; //!< data size in bytes
    uint8_t sidx;   //!< slave index (to determine nCS pin)
} __attribute__((packed));



/*! @} */

#endif
#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_SPI_H
