#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MOD 1000000007

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);      
    int t=1;



  
    
    do    
    {
      cout<<"Enter 0 to convert Decimal to Binary "<<endl;
      cout<<"Enter 1 to convert Binary to Decimal"<<endl;
      int x;
      cin>>x;
      
      
      
      if(x==0)
      {
        int N;
        cout<<"Enter Decimal number"<<endl;
        cin>>N;
        stack<int>stk;
        while(N>0)
          {
            stk.push((N%2));
            N/=2;
          }
       
        while(!stk.empty())
          {
            cout<<stk.top()<<" ";
            stk.pop();
          }
          cout<<endl;
      }
      else if(x==1)
      {
        string num;
        cout<<"Enter Binary number"<<endl;
        cin>>num;
        int ans=0;
	      int ac=1; 
	      int size = num.length(); 
	      for (int i = size - 1; i >= 0; i--) 
        { 
		    if (num[i] == '1') 
			  ans+=ac; 
		    ac*=2; 
      	} 
        cout<<ans<<endl;
      }
      else
        cout<<"Please choose 0 and 1 only"<<endl;


     


        
    cout<<"Do you want to continue? Enter 0 for NO and 1 for YES"<<endl;
      cin>>t;
    }
    while(t==1);

   
    return 0;
}
