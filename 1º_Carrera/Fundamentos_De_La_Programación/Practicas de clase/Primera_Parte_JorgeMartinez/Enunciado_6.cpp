#include<iostream>
#include<cmath>

int main(){
float X=5;
float Y=1;
float Z=2;
if(Z<=Y){
    std::cout<<"\nEl nuevo valor de Y es "<<Z+1;
}
else{
if(Z<=X){
    std::cout<<"\nEl nuevo valor de X es "<<Z+2;
}
else{
    std::cout<<"\nEl nuevo valor de Z es "<<Z+3;
}
}
return 0;
}