# Ejercicio 1 - Control digital de colores

**Alumnos:** Jorge Martínez Díaz y David Valiño Iglesias.  
**Fecha:** 07/10/2026  

## Descripción

En este ejercicio hemos programado un LED RGB para controlar sus tres colores mediante Arduino. Hemos creado la función **setColor()**, que permite controlar los canales rojo, verde y azul mediante una única llamada. Cada canal puede estar encendido (*1*) o apagado (*0*).
Como el LED RGB utilizado es de ánodo común, la lógica está invertida: los colores se encienden mediante *LOW* y se apagan mediante *HIGH*.

## Funcionamiento

El programa muestra de forma secuencial los siguientes estados:

1. LED apagado
2. Rojo
3. Verde
4. Azul
5. Cian

Cada estado permanece durante un segundo y después se pasa al siguiente. Al terminar la secuencia, vuelve a comenzar.

## Esquemático:

![Esquema del circuito](Esquematico_P2(2).png)


## Enlace video:

https://youtube.com/shorts/RoaIGxWIhIE?feature=share