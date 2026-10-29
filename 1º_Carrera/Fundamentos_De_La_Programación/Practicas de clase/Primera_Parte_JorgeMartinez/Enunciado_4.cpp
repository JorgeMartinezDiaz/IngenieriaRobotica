#include<iostream>
#include<cmath>

int main(){
float num1=5;
float num2=1;
float num3=2;
if(num1>num2 && num1>num3 && num2>num3){
std::cout<< num1,num2,num3;
}
else{
if(num2>num1 && num2>num3 && num1>num3){
std::cout<< num2,num1,num3;
}
}
else{
if(num3>num1 && num3>num2 && num1>num2){
    std::cout<<n um3,num1,num2;
    }
}
return 0;
}