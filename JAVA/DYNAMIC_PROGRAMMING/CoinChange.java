import java.util.Arrays;

public class CoinChange {
    
    public static int coinChange(int[] coins, int amount) {
        // Create a DP array initialized with a large value (infinity substitute)
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        
        // Base case: To make an amount of 0, we need 0 coins
        dp[0] = 0;
        
        // Fill the DP array
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If we can't make the amount, return -1; otherwise, return dp[amount]
        return dp[amount] > amount ? -1 : dp[amount];
    }
    
    public static void main(String[] args) {
        int[] coins = {1, 2, 5};
        int amount = 11;
        
        int result = coinChange(coins, amount);
        if (result == -1) {
            System.out.println("It is not possible to make the amount with the given coins.");
        } else {
            System.out.println("The minimum number of coins needed: " + result);
        }
    }
}
