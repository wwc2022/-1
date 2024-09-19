#include<iostream>

int Fibonacci(int);


int main(){
    int a;
    a = Fibonacci(20);
    std::cout<<a;
}


int Fibonacci(int a){
    if(a<1)return 0;
    
    if(a==1||a==2) return 1;
   
    else a = Fibonacci(a-1)+Fibonacci(a-2);
    return a;

}