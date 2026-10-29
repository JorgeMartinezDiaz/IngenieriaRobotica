#!/bin/bash

if [ "$#" -ne 2 ]; then
	echo "Error. Número de argumentos invalido."
	exit 2
fi

usuario_local="$(whoami)"
usuario="$1"
carpeta="$2"
ruta="$HOME/$carpeta"

if [ "$usuario" != "$usario_local" ]; then
	echo "Los usuarios no coinciden"
	exit 2
fi 

if [ -e "$ruta" ] && [ ! -d "$ruta" ]; then
	echo "La ruta existe pero no es un directorio"
	exit 2
fi

if [ ! -d "$ruta" ]; then
	mkdir "$ruta"
fi

echo "Sesión iniciada con el usuario $usuario." > "$ruta/sesion.log"
chmod 666 "$ruta/sesion.log"
