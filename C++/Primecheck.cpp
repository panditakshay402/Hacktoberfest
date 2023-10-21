#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the number to be checked :";
    cin>>n;
    int i=2;
    while(i<n) {
        if(n%i==0){
            cout<<n<<" is not a prime number"<<endl;
            i=i+1;
            break;
        }
        else {
            cout<<n<<" is a prime number"<<endl;
            break;
        }
    }
}