/*
author          Oliver Blaser
date            15.06.2025
copyright
*/

#ifndef IG_PHYOIP_PROTOCOL_CMP_H
#define IG_PHYOIP_PROTOCOL_CMP_H

#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup grp_protocol_cmp
 * @{
 */



/**
 * @brief Control message protocol header.
 */
struct phyoip_cmphdr
{
    uint8_t hsize;  //!< header size in bytes
    uint16_t dsize; //!< data size in bytes
    uint8_t type;   //!< message type
} __attribute__((packed));

//! \name Message Type
/// @{
#define PHYOIP_CMP_REQPEERINFO (1)
#define PHYOIP_CMP_PEERINFO    (2)
#define PHYOIP_CMP_REG         (3) //!< register client
#define PHYOIP_CMP_ACK         (4) //!< register (not) acknowledge

/**
 * extension envelope
 *
 * Data must start with a `phyoip_xenvhdr` which might be expanded by the extension protocol.
 *
 * Might be used for implementation specific communications (e.g. client authentication).
 */
#define PHYOIP_CMP_XENV (5)
/// @}



/**
 * @brief Peer info data.
 *
 * \b Name
 * Null terminated name of the server/client implementation, names starting with `PHYoIP` are reserved for the official
 * implementations.
 *
 * \b Version
 * Null terminated semver string of the implementation.
 *
 * \b Description
 * Null terminated arbitary description.
 */
struct phyoip_cmppi
{
    uint8_t phytype;   //!< physical interface type
    uint16_t nameoffs; //!< name offset
    uint16_t veroffs;  //!< version string offset
    uint16_t descoffs; //!< description offset
} __attribute__((packed));



/**
 * @brief Register data.
 */
struct phyoip_cmpreg
{
    uint8_t phytype;  //!< physical interface type
    uint16_t clitype; //!< client type
} __attribute__((packed));

//! \name Physical Interface Type
/// @{
#define PHYOIP_PHY_UART (1) //!< UART (or RS-232 only with Rx/Tx, RS-422, RS-485, ...)
// #define PHYOIP_PHY_I2C  (2)
// #define PHYOIP_PHY_SPI  (3)
/// @}

//! \name Client Type
/// @{
#define PHYOIP_CT_GC    (0x0001 | ___PHYOIP_CT_SLAVE)                       //!< gateway client (reads from egress, writes to ingress)
#define PHYOIP_CT_SC    (0x0002 | ___PHYOIP_CT_MASTER | ___PHYOIP_CT_SLAVE) //!< sniffer client (reads from ingress and egress)
#define PHYOIP_CT_ROC_E (0x0003 | ___PHYOIP_CT_SLAVE)                       //!< read only client (reads from egress)
#define PHYOIP_CT_ROC_I (0x0004 | ___PHYOIP_CT_MASTER)                      //!< read only client (reads from ingress)
#define PHYOIP_CT_WOC_E (0x0005 | ___PHYOIP_CT_MASTER)                      //!< write only client (writes to egress)
#define PHYOIP_CT_WOC_I (0x0006 | ___PHYOIP_CT_SLAVE)                       //!< write only client (writes to ingress)
#define PHYOIP_CT_RWC   (0x0007 | ___PHYOIP_CT_MASTER)                      //!< read/write client (reads from ingress, writes to egress)

#define ___PHYOIP_CT_ROLE_MASK   (0xFF00)
#define ___PHYOIP_CT_ROLE_MASTER (0x8000)
#define ___PHYOIP_CT_ROLE_SLAVE  (0x4000)
/// @}



/**
 * @brief Acknowledge data.
 */
struct phyoip_cmpack
{
    uint8_t status;
} __attribute__((packed));

//! \name Acknowledge Status
/// @{
#define PHYOIP_ACK_OK    (0)
#define PHYOIP_ACK_ERROR (1)
// maybe some more granular server errors (rejected, retry, ...)
/// @}



/**
 * @brief Extension envelope header.
 */
struct phyoip_xenvhdr
{
    uint8_t hsize;  //!< header size in bytes
    uint16_t dsize; //!< data size in bytes
} __attribute__((packed));



/*! @} */

#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_CMP_H
