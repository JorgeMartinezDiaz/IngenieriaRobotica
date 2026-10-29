#!/bin/sh

if [ "$#" -ne 1 ]; then
	echo "Error: Numero de argumentos invalido"
	exit 2
fi

if [ ! -f "$1" ]; then
 	echo "Error: El archivo no existe o no es regular."
	exit 2
fi
fichero="$1"

#-- Calculo del promedio
{
echo "Promedio de ventas por producto"
echo "-------------------------------\n"

awk 'NR>1{
	suma=0
	for(i=2;i<=7;i++){
		suma += $i
	}

	printf "%s %f\n", $1, suma/6
}' "$fichero"

#-- Mostrar mes con mayor numero de ventas
#Aqui instauramos el puntero del producto mas vendido.
awk 'NR==2{
	MAX=$2 #Primer producto de la 1 linea de productos(linea 2)
	producto=$1
	mes="Mes1"
}
#Aqui empieza la comparación.
NR>1{
	for (i=2;i<=7;i++){
		if ( $i > MAX ){
			MAX=$i
			producto=$1
			mes="Mes"(i-1)
		}
	}
}
END{
	print "\nProducto: "producto
	print "Mes: "mes
	print "Unidades: " MAX
}' "$fichero"

#-- Ultimo apartado: Filtrar con grep.
echo "\nFiltrado con grep:\n"
grep -E '^(Drone|Robot).*5$' "$fichero"
} > topventas.txt
