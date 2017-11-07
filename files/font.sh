#!/bin/sh

echo "Deplacement des polices dans le dossier \"/usr/share/fonts\" ..."
cp -R font/* /usr/share/fonts
echo "Actualisation des polices ..."
fc-cache -f -v