#include<iostream>
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
    int i = 0;
    while(i<estudiantes){
        std::cout<<"Introduzca la altura: ";
        std::cin>>arrayAltura[i];
        i++;
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
  int arrayResultados[tabla][multiplicador];
  std::cout<<"***Tablas de multiplicar***\n";
  std::cout<<"Se le mostrarán las tablas de multiplicar del 1 hasta el 10 con multiplicador hasta el 12.\n\n";
  int i = 0;
  while(i < tabla){
    int j = 0;
    while(j < multiplicador){
      arrayResultados[i][j]=(i + 1)*(j + 1);
      j++;
    }
    i++;
  }
  i = 0;
  while(i < tabla){
    std::cout<<"Tabla del "<<i+1<<":\n";
    int j = 0;
    while(j < multiplicador){
      std::cout<<arrayResultados[i][j]<<" ";
      j++;
    }
    std::cout<<"\n\n";
    i++;
  }
}
else std::cout<<"Opción introducida erronea.\n";
  return 0;
}

float promedio1(float arrayAltura[], int cantidad){
    float resultado = 0;
    int contador = 0;
    int i = 0;
    while(i<cantidad){
      if(arrayAltura[i]< 1.60){
        resultado += arrayAltura[i];
        contador++;
        i++
      }
    }
    if (contador == 0) return 0;
    return resultado / contador;
}
float promedio2(float arrayAltura[], int cantidad){
    float resultado = 0;
    int contador = 0;
    int i = 0;
    while(i<cantidad){
      if(arrayAltura[i]>=1.60 && arrayAltura[i]<1.70){
        resultado += arrayAltura[i];
        contador++;
        i++;
      }
    }
    if (contador == 0) return 0;
    return resultado / contador;
}
float promedio3(float arrayAltura[], int cantidad){
    float resultado = 0;
    int contador = 0;
    int i = 0;
    while(i<cantidad){
      if(arrayAltura[i]>= 1.70 && arrayAltura[i]<1.80){
        resultado += arrayAltura[i];
        contador++;
        i++;
      }
    }
    if (contador == 0) return 0;
    return resultado / contador;
}
float promedio4(float arrayAltura[], int cantidad){
    float resultado = 0;
    int contador = 0;
    int i = 0;
    while(i<cantidad){
      if(arrayAltura[i]>= 1.80){
        resultado += arrayAltura[i];
        contador++;
        i++
      }
    }
    if (contador == 0) return 0;
    return resultado / contador;
}
float promedioGeneral(float arrayAltura[], int cantidad){
    float resultado = 0;
    int i = 0;
    while(i < cantidad){
        resultado += arrayAltura[i];
        i++;
    }
    return resultado / cantidad;
}