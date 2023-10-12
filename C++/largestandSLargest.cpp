#include <bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int m1=INT_MIN,m2=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>m1){
                m2=m1;
                m1=arr[i];
            }
            else{
                if(arr[i]>m2 && arr[i]!=m1){
                    m2=arr[i];
                }
            }
        }
        cout<<m1+m2<<endl;
    }
    return 0;
}
