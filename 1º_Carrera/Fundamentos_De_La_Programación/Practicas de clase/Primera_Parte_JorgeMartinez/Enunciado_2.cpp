#include <iostream>
#include <cmath>

int main()
{
int fecha;
std::cout<<"Introduzca el año en el que estamos:\n";
std::cin>>fecha;
int año = fecha-2000;
if((año % 4 )== 0){
std::cout<<"El año es bisiesto.";
}
else
{
std::cout<<"El año no es bisiesto.";

}
return 0;
}