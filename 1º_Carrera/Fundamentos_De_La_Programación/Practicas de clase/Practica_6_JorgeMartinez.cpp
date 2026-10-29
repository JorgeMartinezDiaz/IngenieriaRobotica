#include <iostream>

int pedirTemperaturas(float[], int);
float promedioSemanal(float[], int);
float promedioDiario(float[], int);
float promedioMomentos(float[], int, int);
int mostrarTemperaturasSuperiores(float[],int,float);

int main() {
    const int dias = 7;
    int diasTotales = dias * 3;
    float arrayTemperaturas[diasTotales];
    int cantidad = pedirTemperaturas(arrayTemperaturas, dias);
    std::cout << "\n=== RESULTADOS METEREOLÓGICOS ===\n\n";
    float promedio = promedioSemanal(arrayTemperaturas, cantidad);
    std::cout << "Promedio semanal: " << promedioSemanal(arrayTemperaturas, cantidad) << " °C\n";
    std::cout << "Promedio diario de cada día:\n";
    for (int i = 0; i < dias; i++) {
        std::cout << "  Día " << i + 1 << ": " << promedioDiario(arrayTemperaturas, i) << " °C\n";
    }
    std::cout << "\nPromedio del amanecer: " << promedioMomentos(arrayTemperaturas, dias, 0) << " °C\n";
    std::cout << "Promedio del mediodía: " << promedioMomentos(arrayTemperaturas, dias, 1) << " °C\n";
    std::cout << "Promedio del atardecer: " << promedioMomentos(arrayTemperaturas, dias, 2) << " °C\n\n";
    int temperaturasSuperiores = mostrarTemperaturasSuperiores(arrayTemperaturas,dias,promedio);
    std::cout<<"\nTemperaturas superiores a la media semanal: "<< temperaturasSuperiores<<"\n\n";
  return 0;
}

int pedirTemperaturas(float arrayTemperaturas[], int totalDias) {
    int indice = 0;
    for (int i = 1; i <= totalDias; i++) {
        std::cout << "\nDía " << i << ":\n";
        for (int j = 0; j < 3; j++) {
        std::cout << "  Temperatura al ";
        switch(j){
            case 0:
                std::cout<<"atardecer";
                break;
            case 1:
                std::cout<<"mediodia";
                break;
            case 2:
                std::cout<<"atardecer";
                break;
        }
        std::cout<<": ";
        std::cin >> arrayTemperaturas[indice];
        indice++;
        }
    }
return indice; 
}
float promedioSemanal(float arrayTemperaturas[], int cantidad) {
    float suma = 0;
    for (int i = 0; i < cantidad; i++) {
        suma += arrayTemperaturas[i];
    }
return suma / cantidad;
}
float promedioDiario(float arrayTemperaturas[], int dia) {
    float suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += arrayTemperaturas[dia * 3 + i];
    }
return suma / 3;
}
float promedioMomentos(float arrayTemperaturas[], int totalDias, int momento) {
    float suma = 0;
    for (int i = 0; i < totalDias; i++) {
        suma += arrayTemperaturas[i * 3 + momento];
    }
return suma/totalDias;
}
int mostrarTemperaturasSuperiores(float arrayTemperaturas[], int totalDias, float promedioSemanal){
    int cont = 0;
    std::cout<<"===Temperaturas Superiores a la Media Semanal===\n";
    std::cout<<"La media semanal ha sido: "<<promedioSemanal<<" ºC.\n\n";
    for(int i = 0; i<totalDias; i++){
        for(int j=0; j<3;j++){
            float muestra = arrayTemperaturas[i*3+j];
            if(muestra>promedioSemanal){
                std::cout<<" Dia "<<i+1<<", ";
                switch(j){
                    case 0:
                        std::cout<<"atardecer";
                        break;
                    case 1:
                        std::cout<<"mediodia";
                        break;
                    case 2:
                        std::cout<<"atardecer";
                        break;
                }
            std::cout<<": "<< muestra <<" ºC\n";
            cont++;
            }
        }
    }
return cont;
}