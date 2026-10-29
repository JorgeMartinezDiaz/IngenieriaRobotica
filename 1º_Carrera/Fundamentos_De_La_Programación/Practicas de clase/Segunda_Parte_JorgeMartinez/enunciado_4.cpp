#include<iostream>
#include<cmath>

int main(){
float num1;
float num2;
float num3;
std::cout<<"Introduzca el primer número:\n";
std::cin>>num1;
std::cout<<"Introduzca el segundo número:\n";
std::cin>>num2;
std::cout<<"Introduzca el tercer número:\n";
std::cin>>num3;
if(num1>num2 && num1>num3 && num2>num3){
    std::cout<<num1<<", "<<num2<<", "<<num3<<"\n";
}
else
if(num2>num1 && num2>num3 && num1>num3){
    std::cout<<num2<<", "<<num1<<", "<<num3<<"\n";
}
else
if(num3>num1 && num3>num2 && num2>num1){
    std::cout<<num3<<", "<<num2<<", "<<num1<<"\n";
}
else
if(num1>num3 && num1>num2 && num3>num2){
    std::cout<<num1<<", "<<num3<<", "<<num2<<"\n";
}
else
if(num2>num1 && num2>num3 && num3>num1){
    std::cout<<num2<<", "<<num3<<", "<<num1<<"\n";
}
else
if(num3>num1 && num3>num2 && num1>num2){
    std::cout<<num3<<", "<<num1<<", "<<num2<<"\n";
}
return 0;
}