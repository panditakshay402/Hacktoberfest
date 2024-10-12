#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    
   int arr[n];
   for (int i=0; i<n; i++) {
cin>>arr[i];
   }
   int q;
   cin>>q;
   for (int m=0; m<q; m++) {
   int val;
   cin>>val;
   auto it=lower_bound(arr,arr+n,val);
   if(*it==val)
   {
       cout<<"Yes"<<" ";
       int s=(it-arr);
       cout<<s+1<<endl;
       
   }
   else{
   cout<<"No"<<" "; 
   int p=distance(arr, it);
       cout<<p+1<<endl; 
   }
   }
   
    return 0;
}
