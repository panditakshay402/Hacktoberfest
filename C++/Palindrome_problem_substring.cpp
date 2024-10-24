/* A string s of lower case english alphabet of length n and 2 integers l and r. 
A boy wants to know whether all the letters of the substring from index l to r (l and r included)
can be rearranged to form a palindrome or not.
He wants to know this for q values of l and r.

constraints
1<=t<=10
1<=n,q<=1e5
1<=l<=r<=n
'a'<=s[i]<='z' for 1<=i<=n */

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int hsh[N][26];

int main(){
    int t;
    cin>t;
    while(t--){
        for(int i=0; i<N; i++){
            for(int j=0; j<26; ++j){
                hsh[i][j]=0;
            }
        }
        int n, q;
        cin>>n>>q;
        string s;
        cin>>s;
        for(int i=0; i<n; i++){
            hsh[i+1][s[i]-'a']++;
        }
        for(int i=0; i<26; ++i){
            for(int j=1; j<=n; ++j){
                hsh[j][i] += hsh[j-1][i];
            }
        }
        while(q--){
            int l, r;
            cin>>l>>r;
            int oddCt=0;
            for(int i=0; i<26; ++i){
                int charCt =hsh[r][i]-hsh[l-1][i];
                if(charCt%2!=0) oddCt++;
            }
            if(oddCt>1) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }
}

//O(t*(n + n*26 + q*26))= O(t*n) = 10*1e5