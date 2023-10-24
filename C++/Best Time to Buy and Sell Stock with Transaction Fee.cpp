//Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:

    int solve(int index, int buy, vector<int>&prices, int fee, vector<vector<int>>& dp) {
        if(index>=prices.size())    return 0;
        int profit = 0;


        if(dp[index][buy]!=-1)  return dp[index][buy];
        if(buy) {
            int buy = -prices[index] + solve(index+1, 0, prices, fee, dp);
            int skip = 0 + solve(index+1, 1, prices, fee, dp);
            profit = max(buy, skip);
        }
        else {
            int sell = (prices[index] + solve(index+1, 1, prices, fee, dp)) - fee;
            int skip = 0 + solve(index+1, 0, prices, fee, dp);
            profit = max(sell, skip);
        }

        dp[index][buy] = profit;
        return dp[index][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};
