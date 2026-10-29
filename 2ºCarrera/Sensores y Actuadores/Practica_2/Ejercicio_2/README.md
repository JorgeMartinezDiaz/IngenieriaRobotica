# Ejercicio 2 - Control de intensidad de colores

**Alumnos:** Jorge Martínez Díaz y David Valiño Iglesias.  
**Fecha:** 07/10/2026  

## Descripción y funcionamiento:  

En este ejercicio hemos modificado el programa del ejercicio 1 para poder controlar la intensidad de cada uno de los tres colores del LED RGB.  

Para ello, hemos cambiado la función **setColor()** para que reciba tres valores entre **0** y **255**, correspondientes a la intensidad de los colores rojo, verde y azul. Para controlar estas intensidades utilizamos **analogWrite()**, que permite utilizar PWM.  
Como el LED RGB utilizado es de ánodo común, la lógica está invertida, por lo que utilizamos **255 - intensidad** en cada canal.

Finalmente, hemos probado diferentes combinaciones para obtener colores como naranja, amarillo, cian, magenta, rosa y blanco.  

## Particularidades:  
Ha sido un ejercicio relativamente sencillo, solo había que darse cuenta de utilizar **analogWrite()** en vez de **digitalWrite()**.  

## Esquemático:

![Esquema del circuito](Esquematico_P2(1).png)

## Enlace video:  

https://youtube.com/shorts/y3_YkjayGlk?feature=share