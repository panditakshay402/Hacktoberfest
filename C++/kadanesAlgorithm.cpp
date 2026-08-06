#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    // using kadane's Algo
    int sum = 0;
    int maxi = INT_MIN;
    int i = 0;

    while (i < nums.size())
    {
        sum += nums[i];
        i++;

        maxi = max(sum, maxi);

        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        a.push_back(elem);
    }

    cout << "ans: " << maxSubArray(a) << endl;

    return 0;
}