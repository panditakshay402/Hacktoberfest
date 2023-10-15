#include<vector>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int i=0;
        int j=0;
        int m=nums1.size();
        int n=nums2.size();
        vector<int>ans;

        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
            }
            else
            {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<m)
        {
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n)
        {
            ans.push_back(nums2[j]);
            j++;
        }

        if(ans.size()%2==1)
        {
            return ans[ans.size()/2];
        }
        else
        {
            double ans1=ans[ans.size()/2];
            double ans2=ans[(ans.size()/2)-1];

            return (ans1+ans2)/2;
        }
        
    }
};