/*
author          Oliver Blaser
date            16.06.2025
copyright
*/

#ifndef IG_PHYOIP_PROTOCOL_DISCOP_H
#define IG_PHYOIP_PROTOCOL_DISCOP_H

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup grp_protocol_discop
 * @{
 */



/**
 * @brief Server discovery protocol header.
 */
struct phyoip_discophdr
{
    uint8_t hsize;  //!< header size in bytes
    uint16_t dsize; //!< data size in bytes
    uint8_t type;
} __attribute__((packed));

//! \name Type
/// @{
#define PHYOIP_DISCOP_SEEK (1)
#define PHYOIP_DISCOP_INFO (2) //!< server info
/// @}



/**
 * @brief Server info data.
 *
 * Also contains `phyoip_cmppi` at `hsize + pioffs`.
 */
struct phyoip_discopinfo
{
    uint16_t port;   //!< port on which the server is listening for TCP connections
    uint16_t pioffs; //!< peer info offset in bytes
} __attribute__((packed));



/*! @} */

#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_DISCOP_H
