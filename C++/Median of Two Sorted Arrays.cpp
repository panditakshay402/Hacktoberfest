#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> v;
    double ans = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        v.push_back(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        v.push_back(nums2[i]);
    }
    sort(v.begin(), v.end());
    int size = v.size();
    int median = v.size() / 2;
    if (size % 2 == 0)
    {
        ans = (v[median - 1] + v[median]) / 2.0;
        return ans;
    }
    else
    {
        ans = v[median];
        return ans;
    }
}
int main()
{
}
