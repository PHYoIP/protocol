/*
author          Oliver Blaser
date            15.06.2025
copyright       MIT - Copyright (c) 2026 Oliver Blaser
*/

#ifndef IG_PHYOIP_PROTOCOL_SPI_H
#define IG_PHYOIP_PROTOCOL_SPI_H

#include <stdint.h>

#include "bits/macros.h"


#ifdef __cplusplus
extern "C" {
#endif

___PHYOIP_PACK_PUSH();

#if 0 // tbd, just some ideas

/*! \addtogroup grp_protocol_spi
 * @{
 */



/**
 * @brief SPI protocol header.
 */
struct phyoip_spihdr
{
    uint8_t hsize;  ///< header size in bytes
    uint16_t dsize; ///< data size in bytes
    uint8_t sidx;   ///< slave index (to determine nCS pin)
} ___PHYOIP_ATTR_PACKED;



/*! @} */

#endif

___PHYOIP_PACK_POP();

#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_SPI_H
