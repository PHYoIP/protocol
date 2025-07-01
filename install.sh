
# author        Oliver Blaser
# date          15.06.2025
# copyright


prefix="/usr/local"

if [ -z "$1" ]; then
    echo "prefix=${prefix}"
else
    prefix="$1"
fi


binPath="${prefix}/bin"
includePath="${prefix}/include"

protocolIncludePath="${includePath}/phyoip/protocol"



rm -rf "${protocolIncludePath}"

install -m 644 -D -t "${protocolIncludePath}/bits" "./include/phyoip/protocol/bits/endian.h"
install -m 644 -D -t "${protocolIncludePath}/bits" "./include/phyoip/protocol/bits/protocol-version.h"

install -m 644 -D -t "${protocolIncludePath}" "./include/phyoip/protocol/cmp.h"
install -m 644 -D -t "${protocolIncludePath}" "./include/phyoip/protocol/discop.h"
install -m 644 -D -t "${protocolIncludePath}" "./include/phyoip/protocol/phyoip.h"
install -m 644 -D -t "${protocolIncludePath}" "./include/phyoip/protocol/uart.h"
