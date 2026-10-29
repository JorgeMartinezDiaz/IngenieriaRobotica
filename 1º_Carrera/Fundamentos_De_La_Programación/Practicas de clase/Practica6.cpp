#include <iostream>

int pedirTemperaturas(float[], int);
float promedioSemanal(float[], int);
float promedioDiario(float[], int);
float promedioMomentos(float[], int, int);

int main() {
    int dias = 7;
    int diasTotales = dias * 3;
    float arrayTemperaturas[diasTotales];
    int cantidad = pedirTemperaturas(arrayTemperaturas, dias);
    std::cout << "\=== RESULTADOS METEREOLÓGICOS ===\n";
    std::cout << "Promedio semanal: " << promedioSemanal(arrayTemperaturas, cantidad) << " °C\n";
    std::cout << "\nPromedio diario de cada día:\n";
    for (int i = 0; i < dias; i++) {
        std::cout << "  Día " << i + 1 << ": " << promedioDiario(arrayTemperaturas, i) << " °C\n";
    }
    std::cout << "\nPromedio al amanecer: " << promedioMomentos(arrayTemperaturas, dias, 0) << " °C\n";
    std::cout << "Promedio al mediodía: " << promedioMomentos(arrayTemperaturas, dias, 1) << " °C\n";
    std::cout << "Promedio al atardecer: " << promedioMomentos(arrayTemperaturas, dias, 2) << " °C\n";
  return 0;
}

int pedirTemperaturas(float arrayTemperaturas2[], int totalDias) {
    int indice = 0;
    for (int i = 1; i <= totalDias; i++) {
        std::cout << "\nDía " << i << ":\n";
        for (int j = 0; j < 3; j++) {
            string nombreMomento;
            if (j == 0) nombreMomento = "amanecer";
            else if (j == 1) nombreMomento = "mediodía";
            else nombreMomento = "atardecer";
          std::cout << "  Temperatura al " << nombreMomento << ": ";
          std::cin >> arrayTemperaturas2[indice];
        indice++;
        }
    }
    return indice; 
}
float promedioSemanal(float arrayTemperaturas2[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arrayTemperaturas2[i];
    }
    return suma / n;
}
float promedioDiario(float arrayTemperaturas2[], int dia) {
    float suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += arrayTemperaturas2[dia * 3 + i];
    }
    return suma / 3;
}
float promedioMomentos(float arrayTemperaturas2[], int totalDias, int momento) {
    float suma = 0;
    for (int i = 0; i < totalDias; i++) {
        suma += arrayTemperaturas2[i * 3 + momento];
    }
    return suma/totalDias;
  }