#include <iostream>
#include <cmath>

int main(){
    int num1, num2, opcion;
    std::cout<<"\t\n***CALCULADORA***\n\t";
    std::cout<<"\t\n***Opcion 1: RESTAR***\n\t";
    std::cout<<"\t\n***Opcion 2: SUMAR***\n\t";
    std::cout<<"\t\n***Opcion 3: MULTIPLICAR***\n\t";
    std::cout<<"\t\nElija una opcion;\n";
    std::cin>>opcion;
    if(opcion<=3 && opcion>=1){
    switch(opcion){
        case 1:
            std::cout<<"\nIntroduzca el primer numero:\t\n";
            std::cin>>num1;
            std::cout<<"\nIntroduzca el segundo numero:\t\n";
            std::cin>>num2;
            std::cout<<"\nLa diferencia es: "<<num1-num2<<"\t\n";
            break;
        case 2:
            std::cout<<"\nIntroduzca el primer numero:\t\n";
            std::cin>>num1;
            std::cout<<"\nIntroduzca el segundo numero:\t\n";
            std::cin>>num2;
            std::cout<<"\nLa suma es: "<<num1+num2<<"\t\n";
            break;
        case 3:
            std::cout<<"\nIntroduzca el primer numero:\t\n";
            std::cin>>num1;
            std::cout<<"\nIntroduzca el segundo numero:\t\n";
            std::cin>>num2;
            std::cout<<"\nEl producto es: "<<num1*num2<<"\t\n";
            break;
    }
}
else 
std::cout<<"\nOpcion erronea.";
    return 0;
}