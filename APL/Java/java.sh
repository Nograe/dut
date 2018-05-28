#!/bin/bash

if [[ $# -lt 1 ]]
then
	echo "Usage: jcc <fichier> [args]"
	exit
fi

javac "$1.java";
echo "Compilation de $1 terminée";
if [[ $# -eq 6 ]]
then
	java "$1" $2 $3 $4 $5 $6;
elif [[ $# -eq 5 ]]
then
	java "$1" $2 $3 $4 $5;
elif [[ $# -eq 4 ]]
then
	java "$1" $2 $3 $4;
elif [[ $# -eq 3 ]]
then
	java "$1" $2 $3;
elif [[ $# -eq 2 ]]
then
	java "$1" $2;
else
	java "$1";
fi
