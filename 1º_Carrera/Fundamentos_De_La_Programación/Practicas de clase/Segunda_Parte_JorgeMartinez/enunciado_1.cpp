#include <iostream>
#include <cmath>

int main()
{
int num1;
std::cout<<"Introduzca un número y le calcularé su raíz cuadrada:\n";
std::cin>>num1;
if(num1 >= 0){
std::cout<<"La raiz cuadrada de su numero es: "<< sqrt(num1)<<"\n";
}
else
{
std::cout<<"Raiz imaginaria.\n\t";
}
return 0;
}