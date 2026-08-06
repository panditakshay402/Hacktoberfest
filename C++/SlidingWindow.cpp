#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(const vector<int>& nums, int k) {
    int n = nums.size();
    if (n < k) {
        cout << "Invalid input: Array size is less than k." << endl;
        return -1;
    }

    int maxSum = 0;
    int currentSum = 0;

    // Compute the sum of the first 'k' elements
    for (int i = 0; i < k; i++) {
        currentSum += nums[i];
    }
    maxSum = currentSum;

    // Slide the window and update the maximum sum
    for (int i = k; i < n; i++) {
        currentSum += nums[i] - nums[i - k];
        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int result = maxSubarraySum(nums, k);
    cout << "Maximum Sum of Subarray of Size " << k << " is: " << result << endl;

    return 0;
}
