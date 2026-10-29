#include <cassert>
#include <iostream>
#include <fstream>
 int main(int argc, char *argv[]){
 double x[100], y[100];
 std::ifstream leer_archivo("entrada.dat");
 assert(leer_archivo.is_open());
 int i = 0;
 while (!leer_archivo.eof()){
 leer_archivo >> x[i] >> y[i];
 i++;
 }
 leer_archivo.close();
 return 0;
 }