Longest Common Subsequence (LCS):

Problem: Find the length and the actual subsequence common to two strings.
Explanation: Create a 2D array to store the length of the LCS of substrings and use it to reconstruct the LCS.

public class LongestCommonSubsequence {
    public static String findLCS(String str1, String str2) {
        int m = str1.length();
        int n = str2.length();

        // Create a 2D array to store the length of LCS of substrings
        int[][] dp = new int[m + 1][n + 1];

        // Build the dp array using dynamic programming
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Reconstruct the LCS from the dp array
        int index = dp[m][n];
        char[] lcs = new char[index];
        int i = m, j = n;
        while (i > 0 && j > 0) {
            if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
                lcs[index - 1] = str1.charAt(i - 1);
                i--;
                j--;
                index--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return new String(lcs);
    }

    public static void main(String[] args) {
        String str1 = "AGGTAB";
        String str2 = "GXTXAYB";
        String lcs = findLCS(str1, str2);
        System.out.println("Length of LCS: " + lcs.length());
        System.out.println("LCS: " + lcs);
    }
}
