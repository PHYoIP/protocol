
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


install -m 644 "./include/phyoip/protocol/*.h" "$includePath/phyoip/protocol" # TODO is this working? Does it create parent dirs?


echo "done"
