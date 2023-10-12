#include <iostream>
using namespace std;

int main() {
    int t,a,b;
    cin>>t;
    while(t-->0)
    {
       cin>>a>>b;
       if(a+b>6)
       cout<<"YES"<<endl;
       else
       cout<<"NO"<<endl;
    }
	return 0;
}
