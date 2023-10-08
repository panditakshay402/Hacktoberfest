#include<bits/stdc++.h>
using namespace std;

// int helper(int day, int last,vector<vector<int>>&v, vector<vector<int>>&dp)
// {
//     if(day==0)
//     {
//         int maxi=0;
//         for(int i=0;i<3;i++)
//         {
//             if(i!=last)
//              maxi=max(maxi,v[day][i]);
//         }
//         return maxi;
//     }
//     if(dp[day][last]!=-1)
//     {
//         return dp[day][last];
//     }
//     int maxi=0;
//     for(int i=0;i<3;i++)
//     {
//         if(i!=last)
//         {
//             int point=helper(day-1,i,v,dp) + v[day][i];
//             maxi=max(maxi,point);
//         }
        
//     }
//     return (dp[day][last]=maxi);
// }

int ninja(int n,vector<vector<int>> &v)
{
    vector<vector<int>> dp(n,vector(4,0));
    // return helper(n-1,3,v,dp);
    dp[0][0]=max(v[0][1],v[0][2]);
    dp[0][1]=max(v[0][0],v[0][2]);
    dp[0][2]=max(v[0][1],v[0][0]);
    dp[0][3]=max(v[0][0],max(v[0][1],v[0][2]));
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            int maxi=0;
            for(k=0;k<3;k++)
            {
                if(k!=j){
                    int point=dp[i-1][k]+v[i][k];
                    maxi=max(maxi,point);
                }
            }
            dp[i][j]=maxi;
        }
    }
    return dp[n-1][3];
}