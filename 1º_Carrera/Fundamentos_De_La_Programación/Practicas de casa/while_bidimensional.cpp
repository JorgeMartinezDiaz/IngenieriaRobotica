#include <iostream>

int main(){
    int cont=1;
    int i=0, j=0;
    int array[3][3];
    while(i<3){
        while(j<3){
            array[i][j]=cont;
            cont++;
            j++;
        }
        i++;
        j=0;
    }
    i=0, j=0;
    std::cout << "La matriz creada es: " << std::endl;
    while(i<3){
        while(j<3){
            std::cout << array[i][j] << "\t";
            j++;
        }
        i++;
        j=0;
        std::cout << std::endl;
    }

}