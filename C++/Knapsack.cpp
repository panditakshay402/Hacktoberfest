#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W, n;
    cin >> W >> n;
    vector<int> weights(n);
    vector<int> values(n);

    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    int result = knapsack(W, weights, values);
    cout << result << endl;

    return 0;
}
