#!/bin/bash

if [[ $# -lt 2 ]]
then
    echo "Usage: $0 <num_arg1> <num_arg2>"
    exit
fi
for ((i = $1; i <= $2; i++))
do
    for ((j = $1; j <= $2; j++))
    do
	echo -n "$((i*j))  "
    done
    echo -e "\n"
done
exit