/*
Se le pide al usuario un número que debe ser 2 o 3, y volver a pedirlo si está mal
Crear la matriz de ese orden, se puede crear donde se necesite

Un menú
- Llenar la matriz auto
- Llenar la matriz a mano
- Crear matriz identidad de ese orden
- Modificacion de la matriz
- visualizar la matriz

# Debe verificar que la matriz este creada antes de modificarla y de visualizarla

Despues de cada acción del menu debe volver a visualizar el menu
*/

#include <iostream>

int main(){
    bool salida = false;
    bool creada = false;
    int orden = 0;
    int opcion = 0;

    while(orden != 2 && orden !=3){
        std::cout << "Ingrese el orden de la matriz: ";
        std:: cin >> orden;
    }
    std::cout << orden << std::endl;

    double matriz[orden][orden];

    int cont=1;
    double temp=0;
    int itemp = 0;
    int jtemp = 0;

    while(!salida){
        std::cout << "==============================" << std::endl;
        std::cout << "Ingrese la opción:" << std::endl;
        std::cout << "1. Llenar la matriz auto" << std::endl;
        std::cout << "2. Llenar la matriz a mano" << std::endl;
        std::cout << "3. Crear matriz identidad" << std::endl;
        std::cout << "4. Modificar matriz" << std::endl;
        std::cout << "5. Visualizar matriz" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cin >> opcion;
        switch (opcion){
            case 1:
                // Llenar auto matriz
                std::cout << "Llenando auto matriz:" << std::endl;
                for(int i=0; i<orden; i++){
                    for(int j=0; j<orden; j++){
                        matriz[i][j] = cont;
                        cont++;
                    } 
                }
                creada = true;
                break;
            case 2:
                // Llenar a mano matriz
                std::cout << "Llenando a mano matriz:" << std::endl;
                for(int i=0; i<orden; i++){
                    for(int j=0; j<orden; j++){
                        std::cout << "Ingrese el valor de la posición [" << i <<"]["<< j <<"]:"<< std::endl;
                        std::cin >> temp;
                        matriz[i][j] = temp;
                    } 
                }
                creada = true;
                break;
            case 3:
                // Matriz identidad
                for(int i=0; i<orden; i++){
                    for(int j=0; j<orden; j++){
                        if (i == j){
                            matriz[i][j] = 1;
                        } else {
                            matriz[i][j] = 0;
                        }
                    } 
                }
                creada = true;
                break;
            case 4:
                if(creada){
                    /// Modificar Matriz
                    std::cout <<"Por favor, ingrese las coordenadas de la matriz del valor a modificar:" << std::endl;
                    std::cout <<"i=";
                    std::cin >> itemp;
                    std::cout <<"j=";
                    std::cin >> jtemp;
                    std::cout <<"Ahora ingrese el nuevo valor en la matriz:" << std::endl;
                    std::cin >> temp;
                    matriz[itemp][jtemp]=temp;
                } else {
                    std::cout << "La matriz no ha sido creada" << std::endl;
                }

                break; 
            case 5:
                if(creada){
                    // Visualizar matriz
                    std::cout << "Visualizando matriz:" << std::endl;
                    for(int i=0; i<orden; i++){
                        for(int j=0; j<orden; j++){
                            std:: cout << matriz[i][j] << "\t";
                        }
                        std::cout << std::endl;
                    }
                } else {
                    std::cout << "La matriz no ha sido creada" << std::endl;
                }

                break;   
            case 6:
                // Salida
                std::cout << "Adios" << std::endl;
                salida = true;
                break;
            default:
                std::cout << "Opción no existe" << std::endl;
                break;
            }
    }
}