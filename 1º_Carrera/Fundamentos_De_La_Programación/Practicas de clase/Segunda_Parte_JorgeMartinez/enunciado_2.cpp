#include <iostream>
#include <cmath>

int main()
{
int año, dia, mes;
std::cout<<"Este programa indica si el año es bisiesto o no.\n";
std::cout<<"Introduzca el dia en el que estamos: \n";
std::cin>>dia;
std::cout<<"Introduzca el mes en el que estamos: \n";
std::cin>>mes;
std::cout<<"Por último, introduzca el año en el que estamos: \n";
std::cin>>año;
int fecha = año-2000;
if((fecha % 4 )== 0){
std::cout<<"El año "<<año<<" es bisiesto.";
}
else
{
std::cout<<"El año "<<año<<" no es bisiesto.";
}
return 0;
}