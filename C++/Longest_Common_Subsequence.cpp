#include <iostream>
#include <vector>

using namespace std;

int lcs(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";
    
    int result = lcs(text1, text2);
    cout << "Length of Longest Common Subsequence: " << result << endl;

    return 0;
}
