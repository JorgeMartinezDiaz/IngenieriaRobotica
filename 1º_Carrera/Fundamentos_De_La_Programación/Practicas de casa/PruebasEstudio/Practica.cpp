#include<iostream>
#include<cmath>

int main(){

int orden, op1;
bool salida = true;

while(orden != 2 && orden != 3){ 
    std::cout<<"Introduzca el tamaño de la matriz 2 o 3.\n";
    std::cin>>orden;
}
std::cout<<"El orden de tu matriz es: "<<orden<<"\n";

double matriz[orden][orden];

int cont=1;

do{
std::cout<<"=============================\n";
std::cout<<"Introduzca la opción:\n";
std::cout<<"1-Llenar la matriz auto\n";
std::cout<<"2-Llenar la matriz a mano\n";
std::cout<<"3-Crear matriz identidad\n";
std::cout<<"4-Modificar la matriz\n";
std::cout<<"5-Visualizando la matriz\n";
std::cout<<"6-Salir.\n";
std::cout<<"Que opción escoger: ";
std::cin>>op1;
}while(!salida);
switch(op1){
    case 1:
    std::cout<<"Llenando la auto matriz.\n";
        for(int i=0; i<orden;i++){
            for(int j=0; j<orden; j++){
                matriz[i][j]=cont;
                std::cout<<matriz[i][j]<<"\n";
                cont++;
            }
            cont++;
        }
        break;
    case 2:
        std::cout<<"Llenando a mano la matriz.\n";
        for(int i=0; i<orden;i++){
            for(int j=0; j<orden; j++){
                std::cout<<"Ingrese el valor de la posición ["<< i <<"]["<< j <<"]\n";
                std::cin>>cont;
                matriz[i][j]= cont;
            }
        }
        break;
    case 3:
        std::cout<<"Crear matriz identidad.\n";
        for(int i=0; i<orden;i++){
            for(int j=0; j<orden; j++){
                if(i == j){
                    matriz[i][j]= 1;
                } else{
                    matriz[i][j] = 0;
                }
            }
        }
        break;
    case 4:
        std::cout<<"Modificar la matriz.\n";

        break;
    case 5:
    std::cout<<"Visualizando matriz.\n";
        for(int i=0; i<orden;i++){
            for(int j=0; j<orden; j++){
                std::cout<<matriz[i][j]<<"\t";
            }
        }
        break;
    case 6:
    std::cout<<"Saliendo...\n\n";
    salida=true;
    break;
    default:
        std::cout<<"Opción erronea.\n";
        break;
}

}