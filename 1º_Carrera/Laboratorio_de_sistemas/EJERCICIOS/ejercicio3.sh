#!/bin/bash

echo "PERMISOS USUARIO GRUPO TAMAÑO FECHA Y HORA NOMBRE"

ls -l | sed -n '/^-/{s/[0-9][0-9]*/ /;p;}' | awk '

{
print $1, $2, $3, $4, $5, $6, $7, $8
suma += $4
}
END{
print " "
print "Tamaño total: "suma
}'
