/*
author          Oliver Blaser
date            16.06.2025
copyright       MIT - Copyright (c) 2026 Oliver Blaser
*/

#ifndef IG_PHYOIP_PROTOCOL_DISCOP_H
#define IG_PHYOIP_PROTOCOL_DISCOP_H

#include <stdint.h>

#include "bits/macros.h"


#ifdef __cplusplus
extern "C" {
#endif

PHYOIP_PACK_PUSH();

/*! \addtogroup grp_protocol_discop
 * @{
 */



/**
 * @brief Server discovery protocol header.
 */
struct phyoip_discophdr
{
    uint8_t hsize;  ///< header size in bytes
    uint16_t dsize; ///< data size in bytes
    uint8_t type;
} PHYOIP_ATTR_PACKED;

//! \name Type
/// @{
#define PHYOIP_DISCOP_SEEK (1)
#define PHYOIP_DISCOP_INFO (2) ///< server info
/// @}



/**
 * @brief Server info data.
 *
 * Also contains `phyoip_cmppi` at `hsize + pioffs`.
 */
struct phyoip_discopinfo
{
    uint16_t port;   ///< port on which the server is listening for TCP connections
    uint16_t pioffs; ///< peer info offset in bytes
} PHYOIP_ATTR_PACKED;



/*! @} */

PHYOIP_PACK_POP();

#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_DISCOP_H
