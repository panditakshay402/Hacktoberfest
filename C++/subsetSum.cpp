#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, int arr[]) {
    int static t[10000][10000];
    int i, j;
    for( i = 0; i<n+1; i++){
      for (j = 0; j < k + 1; j++) {
        if (i == 0)
          t[i][j] = false;
        if (j == 0)
          t[i][j] = true;
      }
    }

    for(int i = 1;i<n+1; i++){
        for(int j = 1; j<k+1; j++){
            

if(arr[i-1] <= j){
    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];

}else{
    t[i][j] = t[i-1][j];

 
        }
    }
}
return t[n][k];

   
}

int main(){
    int arr[] = {10,5,3,2,4};

    int n = sizeof(arr)/sizeof(int);
    int k = 20;
   cout<< subsetSumToK(n,k,arr);
   if(subsetSumToK? cout<<"true" : cout<<"false");

    return 0;
}
