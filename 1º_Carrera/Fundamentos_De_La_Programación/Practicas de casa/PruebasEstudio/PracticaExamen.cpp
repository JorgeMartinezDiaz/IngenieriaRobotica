#include<iostream>
#include<cmath>

int main(){

int estudiantes;
int asignaturas;
float sumaEstudiante, promedio, promedioGeneral;
int aprobados = 0;

std::cout<<"Introduzca el numero de estudiantes que quiera evaluar su media. Como máximo serán 50 y debe ser minimo 1. \n";
std::cin>>estudiantes;
while(estudiantes<=0 || estudiantes>50){
    std::cout<<"Opción erronea. Introudzca el numero de alumnos.\n";
    std::cin>>estudiantes;
}
std::cout<<"Realizaremos el programa para "<<estudiantes<<" estudiantes.\n";
std::cout<<"Cuantas asignaturas tienen los estudiantes:";
std::cin>>asignaturas;

float arrayNotas[estudiantes][asignaturas];

for(int i=0; i<estudiantes; i++){
    std::cout<<"Estudiante "<< i+1<<":\n";
    for( int j= 0; j<asignaturas;j++){
        do{
        std::cout<<"Materia "<< j+1<<": ";
        std::cin>>arrayNotas[i][j];
        if(arrayNotas[i][j]<0 || arrayNotas[i][j>10]){
            std::cout<<"Nota invalida. Ingrese un valor entre 0 y 10.\n\n";
        }
    }while(arrayNotas[i][j]<0 || arrayNotas[i][j]>10);
    }
}
for(int i = 0; i<estudiantes;i++){
    sumaEstudiante=0;
    for(int j = 0; j<asignaturas; j++){
        sumaEstudiante += arrayNotas[i][j];
    }
    promedio= sumaEstudiante/asignaturas;
    std::cout<<"Promedio estudiante "<< i + 1 <<" es: "<<promedio<<"\n";
    promedioGeneral += promedio;
    if(promedio >= 5){
        aprobados++;
    }
}

promedioGeneral=promedioGeneral/estudiantes;
std::cout<<"El promedio general de la clase es :"<<promedioGeneral<<"\n";
std::cout<<"El número de aprobados es: "<<aprobados<<"\n";
    
return 0;
}