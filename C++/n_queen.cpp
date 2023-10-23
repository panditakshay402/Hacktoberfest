#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
int ans;
bool check(vector<string> a,int i,int j,int n){
        
        for(int x=i+1,y=j-1;x<n && y>=0;x++,y--){
            if(a[x][y] == 'Q')
            return true;
        }
        for(int x=i-1,y=j+1;x>=0 && y<n;x--,y++){
            if(a[x][y] == 'Q')
            return true;
        }
        for(int x=i-1,y=j-1;x>=0 && y>=0;x--,y--){
            if(a[x][y] == 'Q')
            return true;
        }
        for(int y=j+1;y<n;y++){
            if(a[i][y] == 'Q')
            return true;
        }
        for(int y=j-1;y>=0;y--){
            if(a[i][y] == 'Q')
            return true;
        }
        for(int x=i+1;x<n;x++){
            if(a[x][j] == 'Q')
            return true;
        }
        for(int x=i-1;x>=0;x--){
            if(a[x][j] == 'Q')
            return true;
        }
        return false;
    }
void n_queen(int queen,vector<string> a,int n){
        if(queen >= n){
            ans++;
            return;
        }
            for(int i=0;i<n;i++){
                if(a[i][queen] == '*')
                continue;
                if(!check(a,i,queen,n)){
                    a[i][queen]='Q';
                    n_queen(queen+1,a,n);
                }
                a[i][queen]='.';
            }
    }


int main()
{
    vector<string> arr(8,string(8,'.'));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>arr[i][j];
        }
    }
    ans =0;
    n_queen(0,arr,8);
    cout<<ans;
}
