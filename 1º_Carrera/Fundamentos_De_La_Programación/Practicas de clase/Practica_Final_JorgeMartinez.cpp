#include<iostream>
#include<fstream>
#include<cstdlib>

struct Pos{
    int x;
    int y;
};

void MostrarTablero(char **tablero, int n, int m, Pos robot){
    system("clear");
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            if(i==robot.x && j==robot.y){
                std::cout<<"R ";
            }else 
            std::cout<<tablero[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"Presione ENTER para continuar...";
    std::cin.get();
}

bool MovimientoRobot(char **tablero, int n, int m, Pos &robot){
    int movimientoX[4]={-1,0,0,1};
    int movimientoY[4]={0,-1,1,0};

    for(int i=0;i<4;i++){
       int nuevaPosicionX = robot.x + movimientoX[i];
       int nuevaPosicionY = robot.y + movimientoY[i];
       if(nuevaPosicionX<n && nuevaPosicionX >=0 && nuevaPosicionY<m && nuevaPosicionY >=0 && tablero[nuevaPosicionX][nuevaPosicionY]=='.'){
        tablero[robot.x][robot.y]='*';
        robot.x = nuevaPosicionX;
        robot.y = nuevaPosicionY;
        return true;
       }
    }
    return false;
}

int main(){
    std::ifstream archivo("config.txt");
    if(!archivo){
        std::cout<<"Error. No se pudo abrir el archivo: config.txt\n\n";
        return 0;
    }
    int n, m;
    char coma;
    archivo>>n>>coma>>m;

    char **tablero = new char*[n];
    for(int i=0;i<n;i++){
        tablero[i] = new char[m];
        for(int j=0;j<m;j++){
            tablero[i][j] = '.';
        }
    }
    Pos robot;
    archivo>>robot.x>>coma>>robot.y;
    int obstaculoX, obstaculoY;
    while(archivo>>obstaculoX>>coma>>obstaculoY){
        if(obstaculoX>=0 && obstaculoX<n && obstaculoY>=0 && obstaculoY<m){
            tablero[obstaculoX][obstaculoY]='#';
        }
    }
    archivo.close();

    if(robot.x<0 || robot.x>=n|| robot.y<0 || robot.y>=m || tablero[robot.x][robot.y]=='#'){
        std::cout<<"Error. El robot se encuentra fuera del tablero o sobre un obstáculo.\n\n";
        return 0;
    }
    std::cin.ignore();

    while(true){
        MostrarTablero(tablero, n, m, robot);
        if(!MovimientoRobot(tablero, n, m, robot))
    break;
    }
    int recorridas = 0;
    int libres = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tablero[i][j]=='*'){
                recorridas++;
            }else if(tablero[i][j]=='.'){
                libres++;
            }
        }
    }
    std::ofstream salida("salida.txt");
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==robot.x && j==robot.y){
                salida<< "R ";
            }else 
            salida<<tablero[i][j]<<" ";
        }
    salida<<"\n";
    }
    salida<<"Celdas recorridas: "<<recorridas<<"\n";
    salida<<"Celdas libres: "<<libres<<"\n\n";
    salida.close();

    std::cout<<"\n\n\tRESULTADOS\n";
    std::cout<<"--------------\n\n";
    std::cout<<"Celdas recorridas: "<<recorridas<<"\n";
    std::cout<<"Celdas libres: "<<libres<<"\n\n";

    for(int i=0;i<n;i++){
        delete[] tablero[i];
    }
    delete[] tablero;
return 0;
}