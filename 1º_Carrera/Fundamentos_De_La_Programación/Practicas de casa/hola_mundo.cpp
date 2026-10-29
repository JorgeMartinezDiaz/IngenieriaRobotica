#include<iostream>
#include<cmath>
#include<thread>
#include<chrono>
#include<cstdlib>


//Este programa es una calculadora cientifica capaz de calcular todo lo que el usuario introduzca.
int main(){

int opcion;
double num1, num2, num3;
char operacion;
std::cout<<"***CALCULADORA***\n";
std::this_thread::sleep_for(std::chrono::seconds(1));
system("clear");
std::cout<<"Menu de operaciones:\n";
std::cout<<"1-> SUMAR.\n";
std::cout<<"2-> RESTAR.\n";
std::cout<<"3-> MULTIPLICAR.\n";
std::cout<<"4-> DIVIDIR.\n";
std::cout<<"5-> RAIZ CUADRADA.\n\n";
std::cout<<"Operación a realizar: ";
std::cin>>opcion;
if(opcion<=5 && opcion>=1){
    if(opcion==1){
         operacion = "suma";
    }
    else if(opcion==2){
         operacion = "restar";
    }
    else if(opcion==3){
         operacion = "multiplicar";
    }
    else if(opcion==4){
         operacion = "dividir";
    }
    else{
         operacion = "raiz cuadrada";
    }
system("clear");
std::cout<<"La opción escogida es "<<operacion<<".\n";
std::this_thread::sleep_for(std::chrono::seconds(2));
system("clear");
    switch(opcion){
    case 1:{
        std::cout<<"Ha elegido sumar. A continuación introduzca los dos números que quiera sumar.\n";
        std::cout<<"Introduzca el primer número: ";
        std::cin>>num1;
        std::cout<<"\nIntroduzca el segundo número: ";
        std::cin>>num2;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout<<"La suma de los dos números introducidos es "<<num1+num2;
        break;
        }
    case 2:{
        std::cout<<"Ha elegido restar. A continuación introduzca los dos números que quiera restar.\n";
        std::cout<<"Introduzca el primer número: ";
        std::cin>>num1;
        std::cout<<"\nIntroduzca el segundo número: ";
        std::cin>>num2;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout<<"La diferencia de los dos números introducidos es "<<num1-num2;
        break;
        }
    case 3:{
        std::cout<<"Ha elegido multiplicar. A continuación introduzca los dos números que quiera multiplicar.\n";
        std::cout<<"Introduzca el primer número: ";
        std::cin>>num1;
        std::cout<<"\nIntroduzca el segundo número: ";
        std::cin>>num2;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout<<"El producto de los dos números introducidos es "<<num1*num2;
        break;
        }
        case 4:{
        std::cout<<"Ha elegido dividir. A continuación introduzca los dos números que quiera dividir.\n";
        std::cout<<"Introduzca el primer número: ";
        std::cin>>num1;
        std::cout<<"\nIntroduzca el segundo número: ";
        std::cin>>num2;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout<<"La división de los dos números introducidos es "<<num1/num2;
        break;
        }
        case 5:{
        std::cout<<"Ha elegido raiz cuadrada. A continuación introduzca el número al que quiera hacerle la raiz cuadrada.\n";
        std::cout<<"Introduzca el número: ";
        std::cin>>num1;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        if(num1>=0){
        std::cout<<"La raiz cuadrada del número introducido es "<<sqrt(num1);
        }
        else
        std::cout<<"Número introducido negativo. Raiz imaginaria.";
        break;
        }
    }
}
else
std::this_thread::sleep_for(std::chrono::seconds(2));
system("clear");
std::cout<<"**OPCION ERRONEA**\n";
std::cout<<"**Saliendo de la calculadora**\n"
std::this_thread::sleep_for(std::chrono::seconds(1));
system("clear");
std::cout<<"\t\tOFF\n";
return 0;
}