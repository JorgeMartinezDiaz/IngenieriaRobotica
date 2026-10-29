#!/bin/sh

if[ $# -lt 1 ] || (( $# > 3)); then
	echo "Error: número de argumentos incorrecto"
	exit 1
fi

file="$1"

if [$# -eq 1 ]; them
	echo "INFORME DE CONEXIONES"
	echo "Fichero: $file"
	echo "Fecha: $(date +%F)"
	echo "================="
	echo "Total conexiones: $(wc -l < "$file")"
	echo "Usuarios distintos: $(awk '{print $1}' "$file" | sort -u | wc -l)"
        echo "Servicios distintos: $(awk '{print $3}' "$file" | sort -u | wc -l)"
	echo "Duración media: $(awk '{print $3}' "$file" | sort -u | tr '\n' ' ')"
	echo "Lista de usuarios distintos: $(awk '{print $1}' "$file" | sort -u | tr '\n' ' ')"
    	echo
    	echo "Lista de servicios distintos: $(awk '{print $3}' "$file" | sort -u | tr '\n' ' ')"
    	echo
    	echo "## CONEXIONES POR SSH DEL USUARIO ADMIN"
   	echo "----------------------------"
    	echo "Numero de conexiones: $(awk '$1=="admin" && $3=="ssh" {c++} END {print c+0}' "$file")"
    	echo "========================================"
    	exit 0
fi
if[ "$2" = "-f" ] && [$# -eq 2 ]; then
	{
		echo "usuario ip_origen servicio fecha hora duracion grupo"
		awk '{
			if ($7=="student")$7="Estudante";
			else if ($7=="professor")$7="Profesor";
			else if ($7=="administrator")$7="Administrador";
			print
		}' "$file"
	} > conexiones.txt
	exit 0
fi
if["$2" = "-u"] && [$# -eq 3]; then
	awk -v user="$3" '$1==user {print NR ": " $0; c++} END {print "total conexiones: " c+0}' "$file"
	exit 0
fi

echo "Error: opción no valida o  mal formada"
exit 1
