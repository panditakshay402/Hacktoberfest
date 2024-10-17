Problem Statement : You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
  
Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
 
Constraints:
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

Solution :- Recursion + Memoization = Dynamic Programming.
  
class Solution {
    public int coinChange(int[] coins, int amount) {
        
        int[][] dp = new int[coins.length][amount + 1];
        for (int x[] : dp) {
            Arrays.fill (x, -1);
        }

        int ans = f (coins, amount, 0, dp); 
        return ans < (int) 1e9 ? ans : -1;
    }
    static int f (int[] coins, int amount, int index, int[][] dp) {

        if (index == coins.length - 1) {
            if (amount % coins[index] == 0) {
                return amount / coins[index];
            } else {
                return (int) 1e9;
            }
        }
        if (dp[index][amount] != -1) {
            return dp[index][amount];
        }
        int pick = (int) 1e9;

        if (coins[index] <= amount) {
             pick = 1 + f(coins, amount - coins[index], index, dp);
        }
        int notPick = 0 + f (coins, amount, index + 1, dp);

        return dp[index][amount] = Math.min (pick, notPick);
    }
}
