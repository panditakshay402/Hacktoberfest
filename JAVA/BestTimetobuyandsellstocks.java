/*
Problem Statement: 
Find the maximum profit that can be achieved from one transaction (buying and selling) in a given array of stock prices. 
The i-th element of the array represents the price of a stock on day i.

Approach:

1. We will initialize two variables, "minPrice" and "maxProfit". 
   - "minPrice" will store the minimum price seen so far, and it is initially set to the maximum possible integer value (`Integer.MAX_VALUE`).
   - "maxProfit" will store the maximum profit, and it is initially set to 0.

2. We will iterate through each price in the array:
   - If the current price (arr[i]) is less than "minPrice", we will update "minPrice" to arr[i].
   - If the current price minus "minPrice" (current profit) is greater than "maxProfit", we update "maxProfit" to this new profit.

3. By the end of the iteration, "maxProfit" will hold the maximum possible profit from one transaction.

Example:
Input: [7, 1, 5, 3, 6, 4]
After processing: minPrice = 1, maxProfit = 5 (buy on day 2 at price 1, sell on day 5 at price 6)

Time Complexity: O(n), where n is the number of elements in the array.

*/

public class MaxProfit {

    // Method to calculate the maximum profit from one transaction
    public static int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE; // Initialize minPrice to the maximum integer value
        int maxProfit = 0; // Initialize maxProfit to 0

        // Loop through each price in the array
        for (int price : prices) {
            // If the current price is less than the minPrice, update minPrice
            if (price < minPrice) {
                minPrice = price;
            }
            // If selling at the current price yields a higher profit, update maxProfit
            else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit; // Return the maximum profit found
    }

    // Main method to run test cases
    public static void main(String[] args) {
        // Test cases
        int[][] testCases = {
            {7, 1, 5, 3, 6, 4},  // Test case 1
            {7, 6, 4, 3, 1},      // Test case 2
            {1, 2, 3, 4, 5},      // Test case 3
            {3, 3, 3, 3, 3},      // Test case 4
            {2, 1, 2, 1, 2}       // Test case 5
        };
        int[] expectedResults = {5, 0, 4, 0, 1}; // Expected results

        // Running the test cases
        for (int i = 0; i < testCases.length; i++) {
            int result = maxProfit(testCases[i]);
            System.out.println("Test case " + (i+1) + ": Expected " + expectedResults[i] + ", Got " + result + ", " + (result == expectedResults[i] ? "Pass" : "Fail"));
        }
    }
}
