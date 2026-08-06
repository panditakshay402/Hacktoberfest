Fibonacci Sequence:

Problem: Find the nth Fibonacci number.
Explanation: Use DP to store previously computed Fibonacci numbers to avoid recalculating them.

public class Fibonacci {
    public static long findNthFibonacci(int n) {
        // Create an array to store Fibonacci numbers
        long[] dp = new long[n + 1];

        // Base cases
        dp[0] = 0;
        dp[1] = 1;

        // Calculate and store Fibonacci numbers from 2 to n
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // The nth Fibonacci number is stored in dp[n]
        return dp[n];
    }

    public static void main(String[] args) {
        int n = 10; // Change this to the desired value of n
        long result = findNthFibonacci(n);
        System.out.println("The " + n + "th Fibonacci number is: " + result);
    }
}
