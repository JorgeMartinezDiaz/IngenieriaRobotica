#include<iostream>
#include<cmath>

int main(){
float X;
float Y;
float Z;
std::cout<<"Introduca el primer número: ";
std::cin>>X;
std::cout<<"Introduca el segundo número: ";
std::cin>>Y;
std::cout<<"Introduca el tercer número: ";
std::cin>>Z;
if(Z<=Y){
    std::cout<<"\nEl nuevo valor de Y es "<<Z+1<<"\n";
}
else{
if(Z<=X){
    std::cout<<"\nEl nuevo valor de X es "<<Z+2<<"\n";
}
else{
    std::cout<<"\nEl nuevo valor de Z es "<<Z+3<<"\n";
}
}
return 0;
}