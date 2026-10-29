#include<iostream>
#include<fstream>
#include<string>

void leerArchivo(int &sumaNumerosTotal);

int main(){
    int sumaNumerosTotal = 0;
    leerArchivo(sumaNumerosTotal);
    std::cout<<sumaNumerosTotal<<"\n";
return 0;
}

void leerArchivo(int &sumaNumerosTotal){
    std::ifstream archivo("entrada.txt");
    if(archivo.is_open()){
        std::string linea;
        while(std::getline(archivo, linea)){
        size_t posA = linea.find('a');
        size_t posZ = linea.find('z');
        if(posA<linea.length() && posZ<linea.length() && posA<posZ){
            std::string contenido = linea.substr(posA+1, posZ-posA-1);
            if(contenido.length()>0){
                bool numero = true;
                for(std::size_t i = 0; i<contenido.length();i++){
                    if(contenido[i]<'0'||contenido[i]>'9'){
                        numero = false;
                        break;
                    }
                }
                if(numero==true){
                    sumaNumerosTotal += std::stoi(contenido);
                }
            }
        }
    }
    archivo.close();
    }else{
    std::cout<<"Error al abrir el archivo.\n";
    }  
}
