// You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?




#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // Optimized Solution [T.C = O(n) & S.C = O(1)]
        int temp1 = 0,temp2 = 1;
        for(int i = 0;i < n;i++){
            int temp = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp;
        }
        return temp2;

        // DP Solution [T.C = O(n) & S.C = O(n)]
        // vector<int>dp(n + 1);
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i = 2;i <= n;i++) dp[i] = dp[i - 1] + dp[i - 2];
        // return dp[n];

        // Brute-force solution[T.C = O(n^2) & S.C = O(n)]
        // if(n == 1 || n == 0) return 1;
        // return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

int main(){
    Solution solve;

    // 1st example
    int n = 7;
    cout<<"No. of ways to climb for n = "<<n<<" : "<<solve.climbStairs(n)<<endl;

    // 2nd example
    n = 3;
    cout<<"No. of ways to climb for n = "<<n<<" : "<<solve.climbStairs(n)<<endl;

    // 3rd example
    n = 45;
    cout<<"No. of ways to climb for n = "<<n<<" : "<<solve.climbStairs(n)<<endl;
}