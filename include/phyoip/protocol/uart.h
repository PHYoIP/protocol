/*
author          Oliver Blaser
date            16.06.2025
copyright       MIT - Copyright (c) 2026 Oliver Blaser
*/

#ifndef IG_PHYOIP_PROTOCOL_UART_H
#define IG_PHYOIP_PROTOCOL_UART_H

#include <stdint.h>

#include "bits/endian.h"


#ifdef __cplusplus
extern "C" {
#endif

/*! \addtogroup grp_protocol_uart
 * @{
 */



/**
 * @brief UART protocol header.
 */
struct phyoip_uarthdr
{
    uint8_t hsize;  //!< header size in bytes
    uint16_t dsize; //!< data size in bytes

    int64_t timestamp; //!< 64bit `time_t` timestamp of when the packet was received on the PHY interface, or created by a client respectively

    /**
     * Adds higher resolution to `timestamp`.
     *
     * _optional_ May be zero or have a lower resolution than nanoseconds, depending on the platform.
     *
     * See <tt><a href="https://man7.org/linux/man-pages/man3/timespec.3type.html" target="_blank">struct timespec</a></tt>.
     */
    int32_t nsec;

// flags
#if PHYOIP_BIG_ENDIAN
    unsigned int ___res  :7;
    unsigned int ingress :1;
#elif PHYOIP_LITTLE_ENDIAN
    unsigned int ingress :1;
    unsigned int ___res  :7;
#else
#error "unknown endianness"
    // Doxygen also will end up here
    unsigned int ___res  :7; //!< bit 1..7 reserved for future use
    unsigned int ingress :1; //!< **bit 0** ingress/nEgress bit
#endif

} __attribute__((packed));



/*! @} */

#ifdef __cplusplus
}
#endif

#endif // IG_PHYOIP_PROTOCOL_I2C_H
