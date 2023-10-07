                                           //JAI SHRI GANESH
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod ((1e7)+9)                   
#define vl vector<ll>
#define vvl vector<vector<ll>>
 void func(int n, string s)
 {
   if(n<=0)
   return;
   else
   {
       cout<<s<<endl;;
       func(n-1,s);
   }
 }
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    func(n,s);
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//   #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
//   #endif
{
   solve();
}
}














