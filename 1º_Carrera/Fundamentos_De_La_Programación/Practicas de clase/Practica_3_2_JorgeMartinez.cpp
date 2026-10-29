#include<iostream>
#include<cmath>
//Este programa es una calculadora científica, creada por Jorge Martínez Díaz.
//Prototipo funciones operaciones.

float suma(float, float);
float resta(float, float);
float multiplicacion(float, float);
float division(float, float);
float raiz(float);
float potencia(float, int);
float seno(float);
float coseno(float);
float tangente(float);
float senohiperbolico(float);
float cosenohiperbolico(float);
float tangentehiperbolica(float);
float logaritmo(float);
float decimal(float);

//Función principal.

int main(){

int opcion;
std::cout<<"\t***CALCULADORA CIENTÍFICA***\n";
std::cout<<"\t----------------------------\n";
std::cout<<"Menú de operaciones:\n";
std::cout<<"1-> SUMAR.\n";
std::cout<<"2-> RESTAR.\n";
std::cout<<"3-> MULTIPLICAR.\n";
std::cout<<"4-> DIVIDIR.\n";
std::cout<<"5-> RAIZ CUADRADA.\n";
std::cout<<"6-> POTENCIA.\n";
std::cout<<"7-> FUNCIÓN TRIGONOMÉTRICA.\n";
std::cout<<"8-> FUNCIÓN HIPERBÓLICA.\n";
std::cout<<"9-> LOGARITMO.\n";
std::cout<<"-----------------\n";
std::cout<<"Operación a realizar: ";
std::cin>>opcion;
if(opcion>0){
    switch (opcion){
        case 1:{
            float sumando, sumando1, resultado = 0;
            std::cout<<"\nIntroduzca el valor del primer sumando: ";
            std::cin>>sumando;
            std::cout<<"\nIntroduzca el valor del segundo sumando: ";
            std::cin>>sumando1;
            resultado = suma(sumando, sumando1);
            std::cout<<"\nEl valor de la suma es "<<resultado<<"\n";
        break;
        }
        case 2:{
            float num, num1, resultado2 = 0;
            std::cout<<"\nIntroduzca el valor del primer número: ";
            std::cin>>num;
            std::cout<<"\nIntroduzca el valor del segundo número: ";
            std::cin>>num1;
            resultado2 = resta(num, num1);
            std::cout<<"\nEl valor de la diferencia es "<<resultado2<<"\n";
        break;
        }
        case 3:{
            float producto, producto1, resultado3 = 0;
            std::cout<<"\nIntroduzca el valor del primer producto: ";
            std::cin>>producto;
            std::cout<<"\nIntroduzca el valor del segundo producto: ";
            std::cin>>producto1;
            resultado3 = multiplicacion(producto, producto1);
            std::cout<<"\nEl valor del producto es "<<resultado3<<"\n";
        break;
        }
        case 4:{
                float dividendo, divisor, resultado4 = 0;
                std::cout<<"\nIntroduzca el valor del dividendo: ";
                std::cin>>dividendo;
                std::cout<<"\nIntroduzca el valor del divisor: ";
                std::cin>>divisor;
                if(divisor!=0){
                resultado4 = division(dividendo, divisor);
                std::cout<<"\nEl valor de la división es "<<resultado4<<"\n";
                }
                else
                std::cout<<"Error. No se puede dividir por 0.\n";
        break;
        }
        case 5:{
            float num2, resultado5 = 0;
            std::cout<<"\nIntroduzca el valor del número: ";
            std::cin>>num2;
            if(num2 >= 0){
            resultado5 = raiz(num2);
            std::cout<<"\nEl valor de la raiz cuadrada es "<<resultado5<<"\n";
            }
            else{
            std::cout<<"Error. No se puede realizar la raiz cuadrada de un número negativo.\n";
            }
        break;
        }
        case 6:{
            float num3, exponente, resultado6 = 0;
            std::cout<<"\nIntroduzca el valor del número: ";
            std::cin>>num3;
            std::cout<<"\nIntroduzca el valor del exponente: ";          
            std::cin>>exponente;
            resultado6 = potencia(num3, exponente);
            std::cout<<"\nEl valor de la potencia es "<<resultado6<<"\n";
        break;
        }
        case 7:{
            float num4, opcion1, resultado7 = 0;
            std::cout<<"Introduzca el valor en grados: ";
            std::cin>>num4;
            std::cout<<"\nMenú de opciones:\n";
            std::cout<<"1-> Seno.\n";
            std::cout<<"2-> Coseno.\n";
            std::cout<<"3-> Tangente.\n";
            std::cout<<"\nElija el tipo de función trigonométrica que deseé calcular: ";
            std::cin>>opcion1;
            if(opcion1 == 1){
                resultado7 = seno(num4);
                std::cout<<"\nEl valor del seno es "<<resultado7<<"\n";
            }
            else if(opcion1 == 2){
                resultado7 = coseno(num4);
                std::cout<<"\nEl valor del coseno es "<<resultado7<<"\n";
            }
            else if(opcion1 == 3){
                resultado7 = tangente(num4);
                std::cout<<"\nEl valor de la tangente es "<<resultado7<<"\n";
            }
            else{
                std::cout<<"\nError. Opción erronea.\n";
            }
        break;
        }
        case 8:{
            float num5, opcion1, resultado8 = 0;
            std::cout<<"Introduzca el valor en grados: ";
            std::cin>>num5;
            std::cout<<"\nMenú de opciones:\n";
            std::cout<<"1-> Seno hiperbólico.\n";
            std::cout<<"2-> Coseno hiperbólico.\n";
            std::cout<<"3-> Tangente hiperbólica.\n";
            std::cout<<"\nElija el tipo de función hiperbólica que deseé calcular: ";
            std::cin>>opcion1;
            if(opcion1 == 1){
                resultado8 = senohiperbolico(num5);
                std::cout<<"\nEl valor del seno hiperbólico es "<<resultado8<<"\n";
            }
            else if(opcion1 == 2){
                resultado8 = cosenohiperbolico(num5);
                std::cout<<"\nEl valor del coseno hiperbólico es "<<resultado8<<"\n";
            }
            else if(opcion1 == 3){
                resultado8 = tangentehiperbolica(num5);
                std::cout<<"\nEl valor de la tangente hiperbólica es "<<resultado8<<"\n";
            }
            else{
                std::cout<<"\nError. Opción erronea.\n";
            }
        break;
        }
        case 9:{
                float num6, resultado9, opcion1 = 0;
                std::cout<<"Introduzca el valor del número: \n";
                std::cin>>num6;
                if(num6>0){
                std::cout<<"Menú para calculos\n";
                std::cout<<"1->Logaritmo natural.\n";
                std::cout<<"2->Logaritmo decimal.\n";
                std::cout<<"Elija el tipo de logaritmo que quiere: ";
                std::cin>>opcion1;
                    if(opcion1 ==1 ){
                    resultado9 = logaritmo(num6);
                    std::cout<<"\nEl valor del logaritmo natural es "<<resultado9<<"\n";
                    }
                    else if(opcion1 == 2){
                    resultado9 = decimal(num6);
                    std::cout<<"\nEl valor del logaritmo decimal es "<<resultado9<<"\n";
                    }
                    else{
                    std::cout<<"Error. Opción introducida no valida.\n";
                    }
                }
                else
                std::cout<<"Error. No se puede calcualr el logaritmo de un numero igual o inferior a 0.\n";
        break;
        }
    }
}
else {
std::cout<<"Entrada no valida.\n";
}
return 0;
}

//Funciones de operaciones calculadora.
float suma(float num, float num2){
    float resultado;
    resultado= num + num2;
    return resultado; 
}
float resta(float num, float num2){
    float resultado;
    resultado = num - num2;
    return resultado;
}
float multiplicacion(float num, float num2){
    float resultado;
    resultado = num * num2;
    return resultado;
}
float division(float num, float num2){
    float resultado;
    resultado = num/num2;
    return resultado;
}
float raiz(float num){
    float resultado;
    resultado = sqrt(num);
    return resultado;
}
float potencia(float num, int exponente){
    float resultado;
    resultado = pow(num, exponente);
    return resultado;
}
float seno(float num){
    float resultado;
    resultado = sin((num * M_PI)/180);
    return resultado;
}
float coseno(float num){
    float resultado;
    resultado = cos((num * M_PI)/180);
    return resultado;
}
float tangente(float num){
    float resultado;
    resultado = tan((num * M_PI)/180);
    return resultado;
}
float senohiperbolico(float num){
    float resultado;
    resultado = sinh((num * M_PI)/180);
    return resultado;
}
float cosenohiperbolico(float num){
    float resultado;
    resultado = cosh((num * M_PI)/180);
    return resultado;
}
float tangentehiperbolica(float num){
    float resultado;
    resultado = tanh((num * M_PI)/180);
    return resultado;
}
float logaritmo(float num){
    float resultado;
    resultado = log(num);
    return resultado;
}
float decimal(float num){
    float resultado;
    resultado = log10(num);
    return resultado;
}
