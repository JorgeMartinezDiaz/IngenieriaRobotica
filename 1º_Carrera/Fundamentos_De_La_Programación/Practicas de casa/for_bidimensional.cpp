#include <iostream>

int main(){
    int cont=1;
    int array[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            array[i][j]=cont;
            cont++;
            // std::cout << "Ingrese el valor para la ["<< i <<"][" << j << "] posición:"<<std::endl;
            // std::cin >> cont;
            // array[i][j]=cont;
        }
    }
    std::cout << "La matriz creada es: " << std::endl;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            std::cout << array[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    // std::cout << "El array creado es: " << std::endl;
    // for(int i=0; i<9; i++){
    //     std::cout << array[0][i]<< "\t";
    // }
}