#include<iostream>
#include<cmath>

//prototipo funciones del area.

int area(float);
int area2(float, float, float);
int area3(float, float);
int area4(float, float);
int area5(float, float);
int area6(float);
//prototipo funciones del volumen.

int volumen1(float);
int volumen2(float, float, float);
int volumen3(float, float);
int volumen4(float, float);
int volumen5(float, float);
int volumen6(float);

//Función principal.

int main(){

int opcion, opcion2;
std::cout<<"***MENU DE OPERACIONES***\n";
std::cout<<"1-> Area.\n";
std::cout<<"2-> volumen.\n";
std::cout<<"----------------\n";
std::cout<<"Que va a querer realizar: ";
std::cin>>opcion;
if(opcion>0){
    if(opcion==1){
        std::cout<<"\nHa elegido calcular el area.\n";
        std::cout<<"----------------\n";
        std::cout<<"Menu de figuras:\n";
        std::cout<<"----------------\n";
        std::cout<<"1-> CUBO.\n";
        std::cout<<"2-> PRISMA.\n";
        std::cout<<"3-> PIRAMIDE.\n";
        std::cout<<"4-> CILINDRO.\n";
        std::cout<<"5-> CONO.\n";
        std::cout<<"6-> ESFERA.\n";
        std::cout<<"----------------\n";
        std::cout<<"Pulse el número de la figura que quiera calcular su area: ";
        std::cin>>opcion2;
            switch (opcion2){
            case 1:{
                float lado, resultado =0;
                std::cout<<"\nIntroduzca el valor del lado de su cubo: ";
                std::cin>>lado;
                resultado = area(lado);
                std::cout<<"\nEl valor del area de su cubo es de "<<resultado<<"\n";
            break;
            }
            case 2:{
                float lado1, lado2, h, resultado2 = 0;
                std::cout<<"\nIntroduzca el valor del lado mayor de su base rectangular: ";
                std::cin>>lado1;
                std::cout<<"\nIntroduzca el valor del lado menor de su base rectangular: ";
                std::cin>>lado2;
                std::cout<<"\nPor último, introduzca el valor de la altura de se prisma: ";
                std::cin>>h;
                resultado2 = area2(lado1, lado2, h);
                std::cout<<"\nEl resultado del area de su prisma es: "<<resultado2<<"\n";
            break;
            }
            case 3:{
                float lado3, apotema, resultado3 = 0;
                std::cout<<"\nIntroduzca el valor del lado de su base cuadrada: ";
                std::cin>>lado3;
                std::cout<<"\nPor último, introduzca el valor de la del apotema de se piramide: ";
                std::cin>>apotema;
                resultado3 = area3(lado3, apotema);
                std::cout<<"\nEl resultado del area de su piramide es: "<<resultado3<<"\n";
            break;
            }
            case 4:{
                float r, h1, resultado4 = 0;
                std::cout<<"\nIntroduzca el valor del radio de su cilindro: ";
                std::cin>>r;
                std::cout<<"\nIntroduzca el valor de la altura de su cilindro: ";
                std::cin>>h1;
                resultado4 = area4(r, h1);
                std::cout<<"\nEl resultado del area de su cilindro es: "<<resultado4<<"\n";
            break;
            }
            case 5:{
                float r1, g, resultado5 = 0;
                std::cout<<"\nIntroduzca el valor del radio de su cono: ";
                std::cin>>r1;
                std::cout<<"\nIntroduzca el valor de la generatriz de su cono: ";
                std::cin>>g;
                resultado5 = area5(r1, g);
                std::cout<<"\nEl resultado del area de su cono es: "<<resultado5<<"\n";
            break;
            }
            case 6:{
                float r2, resultado6 = 0;
                std::cout<<"\nIntroduzca el valor del radio de su esfera: ";
                std::cin>>r2;
                resultado6 = area6(r2);
                std::cout<<"\nEl resultado del area de su esfera es: "<<resultado6<<"\n";
            break;
            }
            }
    }
    else if(opcion==2){
        std::cout<<"\nHa elegido calcular el volumen.\n";
        std::cout<<"----------------\n";
        std::cout<<"Menu de figuras:\n";
        std::cout<<"----------------\n";
        std::cout<<"1-> CUBO.\n";
        std::cout<<"2-> PRISMA.\n";
        std::cout<<"3-> PIRAMIDE.\n";
        std::cout<<"4-> CILINDRO.\n";
        std::cout<<"5-> CONO.\n";
        std::cout<<"6-> ESFERA.\n";
        std::cout<<"----------------\n";
        std::cout<<"Pulse el número de la figura que quiera calcular su volumen: ";
        std::cin>>opcion2;
            switch(opcion2){
                case 1:{
                    float lado, resultado = 0;
                    std::cout<<"\nIntroduzca el valor del lado de su cubo: ";
                    std::cin>>lado;
                    resultado = volumen1(lado);
                    std::cout<<"\nEl resultodo del volumen de su cubo es: "<<resultado<<"\n";
                break;
                }
                case 2:{
                    float lado1, lado2, h, resultado2 = 0;
                    std::cout<<"\nIntroduzca el valor del lado mayor de su base rectangular: ";
                    std::cin>>lado1;
                    std::cout<<"\nIntroduzca el valor del lado menor de su base rectangular: ";
                    std::cin>>lado2;
                    std::cout<<"\nPor último, introduzca el valor de la altura de su prisma: ";
                    std::cin>>h;
                    resultado2 = volumen2(lado1, lado2, h);
                    std::cout<<"\nEl resultado del volumen de su prisma es: "<<resultado2<<"\n";
                break;
                }
                case 3:{
                    float lado1, h1, resultado3 = 0;
                    std::cout<<"\nIntroduzca el valor del lado de su base: ";
                    std::cin>>lado1;
                    std::cout<<"\nPor último, introduzca el valor de la altura de su piramide: ";
                    std::cin>>h1;
                    resultado3 = volumen3(lado1, h1);
                    std::cout<<"\nEl resultado del volumen de su piramide es: "<<resultado3<<"\n";
                break;
                }
                case 4:{
                    float r, h2, resultado4 = 0;
                    std::cout<<"\nIntroduzca el valor del radio de su cilindro: ";
                    std::cin>>r;
                    std::cout<<"\nPor último, introduzca el valor de la altura de su cilindro: ";
                    std::cin>>h2;
                    resultado4 = volumen4(r, h2);
                    std::cout<<"\nEl resultado del volumen de su cilindro es: "<<resultado4<<"\n";
                break;
                }
                case 5:{
                    float r1, h3, resultado5 = 0;
                    std::cout<<"\nIntroduzca el valor del radio de su cono: ";
                    std::cin>>r1;
                    std::cout<<"\nPor último, introduzca el valor de la altura de su cono: ";
                    std::cin>>h3;
                    resultado5 = volumen5(r1, h3);
                    std::cout<<"\nEl resultado del volumen de su cono es: "<<resultado5<<"\n";
                break;
                }
                case 6:{
                    float r2, resultado6 = 0;
                    std::cout<<"\nIntroduzca el valor del radio de su esfera: ";
                    std::cin>>r2;
                    resultado6 = volumen6(r2);
                    std::cout<<"\nEl resultado del volumen de su esfera es: "<<resultado6<<"\n";
                break;
                }
                }
    }

}
else 
std::cout<<"Entrada no valida.\n";
    return 0;
}

//Funciones de area.

int area(float lado){
    float resultado;
    resultado= lado * lado;
    return resultado; 
}
int area2(float lado1, float lado2, float h){
    float resultado;
    resultado = (2*lado1*lado2)+((lado1+lado1+lado2+lado2)*h);
    return resultado;
}
int area3(float lado, float apotema){
    float resultado;
    resultado = (lado*lado)+((4*lado*apotema))/2;
    return resultado;
}
int area4(float r, float h){
    float resultado;
    resultado = 2*3.1415*r*(r+h);
    return resultado;
}
int area5(float r, float g){
    float resultado;
    resultado = 3.1415*r*(r+g);
    return resultado;
}
int area6(float r){
    float resultado;
    resultado = 3.1415*r*r*4;
    return resultado;
}
//Funciones de volumenenes.

int volumen1(float lado){
    float resultado;
    resultado = lado*lado*lado;
    return resultado;
}
int volumen2(float lado1, float lado2, float h){
    float resultado;
    resultado = lado1 * lado2 * h;
    return resultado;
}
int volumen3(float lado1, float h){
    float resultado;
    resultado = (lado1*lado1*h)/3;
    return resultado;
}
int volumen4(float r, float h){
    float resultado;
    resultado = 3.1415*r*r*h;
    return resultado;
}
int volumen5(float r, float h){
    float resultado;
    resultado = (3.1415*r*r*h)/3;
    return resultado;
}
int volumen6(float r){
    float resultado;
    resultado = (3.1415*r*r*r*4)/3;
    return resultado;
}