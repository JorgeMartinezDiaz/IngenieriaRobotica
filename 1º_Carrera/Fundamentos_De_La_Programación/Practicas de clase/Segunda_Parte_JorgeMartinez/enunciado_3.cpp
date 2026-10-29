#include <iostream>
#include <cmath>

int main()
{
float num1;
float num2;
float num3;
std::cout<<"Introduzca el primer numero:\n";
std::cin>>num1;
std::cout<<"Introduzca el segundo número:\n";
std::cin>>num2;
std::cout<<"Por último, introduzca el tercer número:\n";
std::cin>>num3;
if(num1<0){
std::cout<<"La suma de los tres números es: "<<num1+num2+num3<<"\n";
}
else
{
std::cout<<"El producto de los tres números es: "<<num1*num2*num3<<"\n";
}
return 0;
}