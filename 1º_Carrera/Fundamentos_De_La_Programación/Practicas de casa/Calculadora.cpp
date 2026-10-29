#include<iostream>
#include<cmath>
#include<thread>
#include<chrono>
#include<cstdlib>


//Este programa es una calculadora cientifica capaz de calcular todo lo que el usuario introduzca.
int main(){

int opcion;
double num1, num2;

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
        std::string operacion = "suma";
        system("clear");
        std::cout<<"La opción escogida es "<<operacion<<".\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
    }
    else if(opcion==2){
        std::string operacion = "restar";
        system("clear");
        std::cout<<"La opción escogida es "<<operacion<<".\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
    }
    else if(opcion==3){
        std::string operacion = "multiplicar";
        system("clear");
        std::cout<<"La opción escogida es "<<operacion<<".\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
    }
    else if(opcion==4){
        std::string operacion = "dividir";
        system("clear");
        std::cout<<"La opción escogida es "<<operacion<<".\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
    }
    else{
        std::string operacion = "raiz cuadrada";
        system("clear");
        std::cout<<"La opción escogida es "<<operacion<<".\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        system("clear");
    }
    switch(opcion){
    case 1:{
        std::cout<<"\t\t\t--MENU SUMA--\n";
        std::cout<<"A continuación introduzca los dos números que quiera sumar.\n";
        std::cout<<"\nIntroduzca el primer número: ";
        std::cin>>num1;
        std::cout<<"Introduzca el segundo número: ";
        std::cin>>num2;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout<<"La suma de los dos números introducidos es "<<num1+num2<<"\n";
        std::cout<<"**Saliendo de la calculadora**\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("clear");
        std::cout<<"\t\tOFF\n";
        break;
        }
    case 2:{
        std::cout<<"\t\t\t--MENU RESTA--\n";
        std::cout<<"A continuación introduzca los dos números que quiera restar.\n";
        std::cout<<"\nIntroduzca el primer número: ";
        std::cin>>num1;
        std::cout<<"Introduzca el segundo número: ";
        std::cin>>num2;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout<<"La diferencia de los dos números introducidos es "<<num1-num2<<"\n";
        std::cout<<"**Saliendo de la calculadora**\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("clear");
        std::cout<<"\t\tOFF\n";
        break;
        }
    case 3:{
         std::cout<<"\t\t\t--MENU MULTIPLICACION--\n";       
        std::cout<<"A continuación introduzca los dos números que quiera multiplicar.\n";
        std::cout<<"\nIntroduzca el primer número: ";
        std::cin>>num1;
        std::cout<<"Introduzca el segundo número: ";
        std::cin>>num2;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout<<"El producto de los dos números introducidos es "<<num1*num2<<"\n";
        std::cout<<"**Saliendo de la calculadora**\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("clear");
        std::cout<<"\t\tOFF\n";
        break;
        }
    case 4:{
        std::cout<<"\t\t\t--MENU DIVISION--\n";
        std::cout<<"A continuación introduzca los dos números que quiera dividir.\n";
        std::cout<<"\nIntroduzca el primer número: ";
        std::cin>>num1;
        std::cout<<"Introduzca el segundo número: ";
        std::cin>>num2;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        std::cout<<"La división de los dos números introducidos es "<<num1/num2<<"\n";
        std::cout<<"**Saliendo de la calculadora**\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("clear");
        std::cout<<"\t\tOFF\n";
        break;
        }
    case 5:{
        std::cout<<"\t\t\t--MENU RAIZ CUADRADA--\n";
        std::cout<<"A continuación introduzca el número al que quiera hacerle la raiz cuadrada.\n";
        std::cout<<"\nIntroduzca el número: ";
        std::cin>>num1;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        system("clear");
        if(num1>=0){
        std::cout<<"La raiz cuadrada del número introducido es "<<sqrt(num1)<<"\n";
        std::cout<<"**Saliendo de la calculadora**\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("clear");
        std::cout<<"\t\tOFF\n";
        }
        else{
        std::cout<<"Número introducido negativo. Raiz imaginaria.\n";
        std::cout<<"**Saliendo de la calculadora**\n";
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("clear");
        std::cout<<"\t\tOFF\n";
        break;
        }
        default:
        std::cout<<"Opcion erronea.";
    }
    }   
}
else{
std::this_thread::sleep_for(std::chrono::seconds(1));
system("clear");
std::cout<<"**OPCION ERRONEA**\n";
std::cout<<"**Saliendo de la calculadora**\n";
std::this_thread::sleep_for(std::chrono::seconds(1));
system("clear");
std::cout<<"\t\tOFF\n";
}
return 0;
}