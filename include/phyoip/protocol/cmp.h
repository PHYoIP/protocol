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
 * <b>Extension Envelope</b>
 *
 * Data must start with a `phyoip_xenvhdr`, which might be expanded by the extension protocol by increasing the `hsize` field.
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
 * \b Description [optional]
 * Null terminated arbitary description.
 */
struct phyoip_cmppi
{
    uint8_t phytype;   //!< physical interface type, see \ref section_protocol_cmp_phytype
    uint16_t nameoffs; //!< name offset
    uint16_t veroffs;  //!< version string offset
    uint16_t descoffs; //!< [optional] null or description offset
} __attribute__((packed));



/**
 * @brief Register data.
 */
struct phyoip_cmpreg
{
    uint8_t phytype;  //!< physical interface type, see \ref section_protocol_cmp_phytype
    uint16_t clitype; //!< client type
} __attribute__((packed));

//! \name Physical Interface Type
//! \section section_protocol_cmp_phytype Physical Interface Type
/// @{
#define PHYOIP_PHY_UART (1) //!< any UART alike interface (UART, RS-232 only with Rx/Tx, RS-422, RS-485, ...)
// #define PHYOIP_PHY_I2C  (2)      reserved until it's defined
// #define PHYOIP_PHY_SPI  (3)      reserved until it's defined
/// @}

//! \name Client Type
/// @{
// #define PHYOIP_CT_RES0  (0x0000 | PHYOIP_CTROLE_) // reserved as an invalid fallback if only PHYOIP_CTROLE_x is used by an implementation
#define PHYOIP_CT_GC    (0x0001 | PHYOIP_CTROLE_SLAVE)                        //!< gateway client (reads from egress, writes to ingress)
#define PHYOIP_CT_ROEC  (0x0002 | PHYOIP_CTROLE_SLAVE)                        //!< read only client (reads from egress)
#define PHYOIP_CT_ROIC  (0x0003 | PHYOIP_CTROLE_MASTER)                       //!< read only client (reads from ingress)
#define PHYOIP_CT_WOEC  (0x0004 | PHYOIP_CTROLE_MASTER)                       //!< write only client (writes to egress)
#define PHYOIP_CT_WOIC  (0x0005 | PHYOIP_CTROLE_SLAVE)                        //!< write only client (writes to ingress)
#define PHYOIP_CT_RWC   (0x0006 | PHYOIP_CTROLE_MASTER)                       //!< read/write client (reads from ingress, writes to egress)
#define PHYOIP_CT_SNIFF (0x0007 | PHYOIP_CTROLE_MASTER | PHYOIP_CTROLE_SLAVE) //!< sniffer client (reads from ingress and egress)

#define PHYOIP_CTMASK        (0x00FF)
#define PHYOIP_CTROLE_MASK   (0xFF00)
#define PHYOIP_CTROLE_MASTER (0x8000)
#define PHYOIP_CTROLE_SLAVE  (0x4000)
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
    uint8_t hsize;     //!< header size in bytes
    uint16_t dsize;    //!< data size in bytes
    uint8_t optoffs;   //!< offset in bytes of the optional extension header fields, zero if none exist
    uint16_t supplier; //!< \ref section_protocol_cmp_extsup
} __attribute__((packed));


//! \name Extension Supplier
//! \section section_protocol_cmp_extsup Extension Supplier
//!
//! A supplier is a vendor or source of a client or server implementation.
//!
/// @{
#define PHYOIP_XSUPPLIER_PHYOIP (1)
#define PHYOIP_XSUPPLIER_PRVMIN (0x2710) //!< first private/unregistered supplier code (10'000)
#define PHYOIP_XSUPPLIER_PRVMAX (0x9C3F) //!< last private/unregistered supplier code (39'999)
/// @}



/*! @} */

#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_CMP_H
