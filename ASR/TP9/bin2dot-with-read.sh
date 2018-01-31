#!/bin/bash

if [[ $# -lt 2 ]]
    then
    echo "Usage: $0 <src_file> <dest_file>"
    exit
fi
if [[ -f $2 ]]
    then
    echo -n "$2 exists. Overwrite? Yes/No --> "
    read answer
    if [ $answer != "Yes" ] && [ $answer != "yes" ]
        then
        exit
    fi
    cp /dev/null $2
fi
while read addr
do
    #echo "addr: $addr"
    x=$(expr substr $addr 1 8)
    y=$(expr substr $addr 9 8)
    z=$(expr substr $addr 17 8)
    t=$(expr substr $addr 25 8)
    addr_dot=$((9#$x)).$((9#$y)).$((9#$z)).$((9#$t))
    echo $addr_dot >> $2
done < $1
exit