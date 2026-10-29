#include<iostream>
#include<cmath>

int main(){
float a=5;
float b=1;
float c=2;
if(a!=0){
    float ecuacion1 =(b*b-4*a*c);
if(ecuacion1>0){
    std::cout<<"el resultado es "<<(-b+sqrt(ecuacion1))/(2*a);
    std::cout<<"el resultado es "<<(-b-sqrt(ecuacion1))/(2*a);
}
else{
    std::cout<<"\nRaiz Imaginaria";
}
}
else
std::cout<<"La ecuacion no se puede resolver.\n";
return 0;
}