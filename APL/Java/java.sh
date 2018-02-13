#!/bin/bash

if [[ $# -lt 1 ]]
then
	echo "Il manque le nom du fichier."
	exit
fi

javac "ex$1.java";
echo "Compilation de ex$1 terminée";
if [[ $# -eq 6 ]]
then
	java "ex$1" $2 $3 $4 $5 $6;
elif [[ $# -eq 5 ]]
then
	java "ex$1" $2 $3 $4 $5;
elif [[ $# -eq 4 ]]
then
	java "ex$1" $2 $3 $4;
elif [[ $# -eq 3 ]]
then
	java "ex$1" $2 $3;
elif [[ $# -eq 2 ]]
then
	java "ex$1" $2;
else
	java "ex$1";
fi
