#include<iostream>
using namespace std;

//Factorial

int factorial(int n){
    if(n<=1){
        return 1;
    }
    else{
    return n * factorial(n-1);   // recursions
    }
}

// fibonacci sequence    //should use loop
int fibonacci(int n){
    if(n <= 1){
        return n;
    }
    return  fibonacci(n - 2) + fibonacci(n - 1);
}

//    fib(5)
//    fib(3) + fib (4)
//    fib(1) + fib(2) + fib(2) + fib (3)
//  ......

int main(){
    
    // Factorial of a number :
    // 6! = 6*5*4*3*2*1 = 720
    // 0! = 1 by definition 
    // 1! = 1 by definition
    // n! = n * (n-1)!
    int a;
    cout<<" enter a number"<<endl;
    cin>>a;
    //cout<<"the factorial is "<<factorial(a)<<endl;
    cout<<"the fibonacci is "<<fibonacci(a)<<endl;
    return 0;
}