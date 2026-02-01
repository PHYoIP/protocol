# PHYoIP Protocol

Specification and C headers for the TCP and UDP application protocols.



## Topology
```mermaid
flowchart TD
    SRV -- eg --> GW(GW)
    GW -- in --> SRV

    SRV -- eg --> SNF(sniffer)
    SRV -- in --> SNF

    SRV((Server)) -- in --> RW(RW)
    RW -- eg --> SRV

    SRV -- eg --> ROE(ROE)
    SRV -- in --> ROI(ROI)

    WOE(WOE) -- eg --> SRV
    WOI(WOI) -- in --> SRV
```
| abbr. | Description                                                |
|:-----:|:-----------------------------------------------------------|
|  eg   | egress packages (i.e. from PC program to external device)  |
|  in   | ingress packages (i.e. from external device to PC program) |
|  GW   | gateway client                                             |
|  RW   | read/write client                                          |
|  RO*  | read-only client                                           |
|  WO*  | write-only client                                          |

Client types `PHYOIP_CT_...` are defined in [_phyoip/protocol/cmp.h_](./include/phyoip/protocol/cmp.h).

## Connection Establishment
```mermaid
sequenceDiagram
    participant S as Server
    participant C as Client
    C ->>+ S: PHYOIP_CMP_REGISTER
    S ->>- C: PHYOIP_CMP_ACK
    Note over S,C: normal operation, e.g.:
    S -->> C: PHYOIP_PROTO_UART
    C -->> S: PHYOIP_PROTO_UART
```

## Connection Termination
A connection can be terminated by either the server or the client.
```mermaid
sequenceDiagram
    participant I as Initiator
    participant P as Peer
    I ->> P: PHYOIP_CMP_DELIST
```
