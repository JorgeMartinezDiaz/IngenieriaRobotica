#include<iostream>

void determinante(int, int, int[][3]);
void transpuesta(int, int, int[][3]);

int main(){
    int fila = 0;
    int columna = 0; 
    int opcion;
    
    do{
    std::cout<<"Introduzca el tamaño de la fila debe ser 2 o 3: ";
    std:: cin>>fila;
    }while(fila != 2 && fila != 3 );
    do{
    std::cout<<"Introduzca el tamaño de la columna como con las filas debe ser 2 o 3: ";
    std:: cin>>columna;    
    }while(columna != 2 && columna != 3);

    int matriz[3][3];
    
    std::cout<<"\n====Ingreso de valores====\n";
    for(int i = 0; i<fila; i++){
        for(int j=0; j<columna; j++){
            std::cout<<"Ingrese el valor de la posición ["<<i<<"]["<<j<<"]: ";
            std::cin>>matriz[i][j];
        }
    }
    std::cout<<"\n====Menu de Opciones====\n";
    std::cout<<"1-> Visualizar la matriz ingresada.\n";
    std::cout<<"2-> Matriz transpuesta.\n";

    if(fila==columna){
        std::cout<<"3-> Determinante de la matriz.\n";
    }else{
        std::cout<<"No se le muestra la opción de cálculo del determinante porque su matriz no es cuadrada(filas=columnas)\n";
    }
    std::cout<<"\nIntroduzca la opción que quiera realizar: ";
    std::cin>>opcion;
    std::cout<<"\n\n";

    switch (opcion){
    case 1:
        std::cout<<"===Visualizar matriz ingresada===\n\n";
        for(int i=0; i<fila;i++){
            for(int j=0; j<columna; j++){
                std::cout<<matriz[i][j]<<"\t";
            }
        std::cout<<"\n";
        }
        std::cout<<"\n";
        break;
    case 2:
        std::cout<<"===Transpuesta de la Matriz===\n\n";
        transpuesta(fila, columna, matriz);
        break;
    case 3:
        if(fila==columna){
        std::cout<<"===Determinante de la Matriz===\n\n";
        determinante(fila, columna, matriz);
        }else
        std::cout<<"Ha pulsado 3. No se puede calcular el determinante porque su matriz no es cuadrada.\n";
        break;
    default:
    std::cout<<"Opción ingresada errónea.\n";
        break;
    }
return  0; 
}

void determinante(int fila, int columna, int matriz[][3]){
    float det = 0;
if(fila==2){
    det = (matriz[0][0] * matriz[1][1]) - (matriz[1][0] * matriz[0][1]);
    std::cout<<"El determinante de su matriz cuadrada de tamaño dos es "<< det <<"\n\n";
} else if(fila == 3){
    float op1, op2 = 0;
    op1 = matriz[0][0]* matriz[1][1]* matriz[2][2] + matriz[0][1]* matriz[1][2]* matriz[2][0] + matriz[1][0]* matriz[2][1]* matriz[0][2];
    op2 = matriz[0][2]* matriz[1][1]* matriz[2][0] + matriz[0][1]* matriz[1][0]* matriz[2][2] + matriz[1][2]* matriz[2][1]* matriz[0][0];
    det = op1 - op2;
    std::cout<<"El determinante de su matriz cuadrada de tamaño tres es "<< det <<"\n\n";
    }
}

void transpuesta(int fila, int columna, int matriz[][3]){
    std::cout<<"La matriz transpuesta es: \n";
    for(int i = 0; i< columna ; i++){
        for(int j = 0; j< fila ; j++){
            std::cout<<matriz[j][i]<<"\t";
        }
    std::cout<<"\n";
    }
}