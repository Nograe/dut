#!/bin/bash

if [[ $# -lt 1 ]]
then
	echo "Il manque le nom du fichier."
	exit
fi

javac "ex$1.java";
echo "Compilation de ex$1 terminée";
java "ex$1";