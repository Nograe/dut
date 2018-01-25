#!/bin/bash
#<my_seq.sh> <num_arg>

if [[ $# -lt 1 ]]
then
    echo "Usage: $0 <num_arg>"
    exit
fi
for ((i = 1; i <= $1; i++))
do
    echo $i
done
exit