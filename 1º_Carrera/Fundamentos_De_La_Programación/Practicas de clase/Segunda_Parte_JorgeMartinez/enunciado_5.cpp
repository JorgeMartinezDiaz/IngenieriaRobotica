#include<iostream>
#include<cmath>

int main(){
float a;
float b;
float c;
std::cout<<"Calculadora de ecuaciones de segundo grado.\n";
std::cout<<"Introduca el término de grado dos:\n";
std::cin>>a;
std::cout<<"Introduca el término de grado uno:\n";
std::cin>>b;
std::cout<<"Introduca el término independiente:\n";
std::cin>>c;
std::cout<<"La ecuación introducida es: "<<a<<"x²+("<<b<<"x)+("<<c<<")=0\n"; 
if(a!=0){
    float ecuacion1 =(b*b-4*a*c);
if(ecuacion1>0){
    std::cout<<"El resultado es x1= "<<(-b+sqrt(ecuacion1))/(2*a)<<"\n";
    std::cout<<"El resultado es x2= "<<(-b-sqrt(ecuacion1))/(2*a)<<"\n";
}
else{
    std::cout<<"\nRaiz Imaginaria.\n";
}
}
else
std::cout<<"La ecuacion no se puede resolver.\n";
return 0;
}