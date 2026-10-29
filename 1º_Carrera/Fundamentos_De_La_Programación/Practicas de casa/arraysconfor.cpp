#include <iostream>
#include<cmath>

int main(){
int tamaño;
std::cout<<"Defina el tamaño del array: ";
std::cin>>tamaño;
int array[tamaño];
int cont = 1;
for(int i = 0; i<tamaño; i++){
    array[i]=cont;
    cont++;
}
std::cout<<"El array es: \n";
for(int i = 0; i < tamaño; i++ ){
    std::cout<<array[i]<<"\t";    
}
    return 0;
}