Coin Change Problem:

Problem: Find the minimum number of coins required to make a given sum.
Explanation: Use DP to store the minimum number of coins required for different subproblems.

import java.util.Arrays;
public class CoinChangeProblem {
    public static int minCoins(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, amount + 1);
        dp[0] = 0;

        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }

    public static void main(String[] args) {
        int[] coins = {1, 2, 5};
        int amount = 11;
        int minCoinsRequired = minCoins(coins, amount);

        if (minCoinsRequired == -1) {
            System.out.println("It's not possible to make the amount with the given coins.");
        } else {
            System.out.println("Minimum coins required to make " + amount + " is: " + minCoinsRequired);
        }
    }
}
