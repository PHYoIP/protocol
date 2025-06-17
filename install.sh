
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


# TODO is this working? Does it create parent dirs?
install -m 644 "./include/phyoip/protocol/bits/*.h" "$includePath/phyoip/protocol/bits"
install -m 644 "./include/phyoip/protocol/cmp.h" "$includePath/phyoip/protocol"
install -m 644 "./include/phyoip/protocol/phyoip.h" "$includePath/phyoip/protocol"
install -m 644 "./include/phyoip/protocol/uart.h" "$includePath/phyoip/protocol"


echo "done"
