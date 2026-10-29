a#include<iostream>
#include<cmath>

float promedio1(float[], int);
float promedio2(float[], int);
float promedio3(float[], int);
float promedio4(float[], int);
float promedioGeneral(float[], int);

int main(){
int Opcion;
std::cout<<"Problema 1: Estadistica de la altura universitaria.\n";
std::cout<<"Problema 2: Tablas de multiplicar.\n";
std::cout<<"Introduzca la opción que deseé: ";
std::cin>> Opcion;
if(Opcion==1){
    int estudiantes;
    std::cout<<"\nEstadistica altura universitaria. \n";
    std::cout<<"Cuantos estudiantes vas a utilizar para la estadística: ";
    std::cin>>estudiantes;
    float arrayAltura[estudiantes];
    std::cout<<"\n***Tabla de opciones altura***\n";
    std::cout<<"Grupo 1: Altura inferior a 1.60.\n";
    std::cout<<"Grupo 2: Altura entre 1.60 incluido a 1.70.\n";
    std::cout<<"Grupo 3: Altura entre 1.70 incluido a 1.80.\n";
    std::cout<<"Grupo 4: Altura mayores de 1.80 incluido.\n\n";
    for(int i = 0; i<estudiantes; i++){
        std::cout<<"Introduzca la altura: ";
        std::cin>>arrayAltura[i];
    }

float resultado = promedio1(arrayAltura, estudiantes);
float resultado2 = promedio2(arrayAltura, estudiantes);
float resultado3 = promedio3(arrayAltura, estudiantes);
float resultado4 = promedio4(arrayAltura, estudiantes);
float resultadoGeneral = promedioGeneral(arrayAltura, estudiantes);

std::cout<<"\nResultados:\n";
std::cout<<"El promedio del grupo 1 es: "<<resultado<<"\n";
std::cout<<"El promedio del grupo 2 es: "<<resultado2 <<"\n";
std::cout<<"El promedio del grupo 3 es: "<<resultado3 <<"\n";
std::cout<<"El promedio del grupo 4 es: "<<resultado4 <<"\n";
std::cout<<"El promedio general es: "<<resultadoGeneral <<"\n";
}
else if(Opcion==2){
    int tabla = 10;
    int multiplicador = 12;
    int arrayResultado[tabla][multiplicador];
    std::cout<<"\n**Tablas de multiplicar**\n";
    std::cout<<"Se le mostrarán las tablas de multiplicar del 1 al 10 con multiplicadro hasta el 12.\n\n";
        for(int i=0; i < tabla; i++){
            for(int j = 0; j < multiplicador; j++){
                arrayResultado[i][j] = (i+1) * (j+1);
            }
        }
    for(int i= 0; i<tabla; i++){
        std::cout<<"Tabla del "<< i+1 <<":\n";
        for(int j = 0; j<multiplicador; j++){
           std::cout<<arrayResultado[i][j]<<" "; 
        }
        std::cout<<"\n\n";
    }
}
else std::cout<<"Opción introducida erronea.\n";
  return 0;
}

float promedio1(float arrayAltura[], int cantidad){
    float resultado = 0;
    int contador = 0;
    for(int i = 0; i<cantidad; i++){
      if(arrayAltura[i]< 1.60){
        resultado += arrayAltura[i];
        contador++;
      }
    }
    if (contador == 0) return 0;
    return resultado / contador;
}
float promedio2(float arrayAltura[], int cantidad){
    float resultado = 0;
    int contador = 0;
    for(int i = 0; i<cantidad; i++){
      if(arrayAltura[i]>=1.60 && arrayAltura[i]<1.70){
        resultado += arrayAltura[i];
        contador++;
      }
    }
    if (contador == 0) return 0;
    return resultado / contador;
}
float promedio3(float arrayAltura[], int cantidad){
    float resultado = 0;
    int contador = 0;
    for(int i = 0; i<cantidad; i++){
      if(arrayAltura[i]>= 1.70 && arrayAltura[i]<1.80){
        resultado += arrayAltura[i];
        contador++;
      }
    }
    if (contador == 0) return 0;
    return resultado / contador;
}
float promedio4(float arrayAltura[], int cantidad){
    float resultado = 0;
    int contador = 0;
    for(int i = 0; i<cantidad; i++){
      if(arrayAltura[i]>= 1.80){
        resultado += arrayAltura[i];
        contador++;
      }
    }
    if (contador == 0) return 0;
    return resultado / contador;
}
float promedioGeneral(float arrayAltura[], int cantidad){
    float resultado = 0;
    for(int i = 0; i < cantidad; i++){
        resultado += arrayAltura[i];
    }
    return resultado / cantidad;
}
