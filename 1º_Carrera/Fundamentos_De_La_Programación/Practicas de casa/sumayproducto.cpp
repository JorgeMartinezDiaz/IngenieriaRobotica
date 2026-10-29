#include <iostream>
#include<cmath>

int main(){
int suma = 0;
int prod = 1;
for(int i = 2; i<=30; i += 2){
    std::cout<< i << "\t";
    suma += i;
}
std::cout<<"La suma es "<<suma<<"\n";
//Producto
for(int i = 1; i <=15; i +=2 ){
    std::cout<< i << "\t";
    prod += i;    
}
std::cout<<"El producto es "<<prod<<"\n";
    return 0;
}