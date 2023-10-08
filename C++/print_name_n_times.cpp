#include<bits/stdc++.h>
using namespace std;
// #define int long long
// #define endl "\n"

void prrt(int n,string s){
    if(n==0){
        return;
    }
    cout<<s<<endl;
    n-=1;
    prrt(n,s);
}

int main(){
    int n;
    cin>>n;//enter the number of times you want to print your string 
    string s;
    cin>>s;// enter the string you want to plrint
    prrt(n,s);//function to recursively print the string
    return 0;
}