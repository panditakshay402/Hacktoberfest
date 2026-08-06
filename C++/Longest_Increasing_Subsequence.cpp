// Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int solve(int ind, int prev_ind, vector<int>& nums, vector<vector<int>> &dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int len=solve(ind+1, prev_ind,nums,dp);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            len=max(len, 1+solve(ind+1,ind, nums,dp));
        }
        return dp[ind][prev_ind+1]= len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(0,-1, nums,dp);
    }
};
