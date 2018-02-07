#!/bin/bash

if [[ $# -lt 1 ]]
then
	echo "Il manque le nom du fichier."
	exit
fi

javac "ex$1.java";
echo "Compilation de ex$1 terminée";
if [[ $# -eq 2 ]]
then
	java "ex$1" $2;
	exit
else
	java "ex$1";
fi
