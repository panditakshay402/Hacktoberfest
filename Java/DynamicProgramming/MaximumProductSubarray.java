Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


## Solution


class Solution {
    public int maxProduct(int[] A) {
        int n = A.length;
        int r = A[0];
 
        int imax = r, imin = r;
        for (int i = 1; i < n; i++) {
            
            if (A[i] < 0) {
                int temp = imax;
                imax = imin;
                imin = temp;
            }
 
            imax = Math.max(A[i], imax * A[i]);
            imin = Math.min(A[i], imin * A[i]);
 
            r = Math.max(r, imax);
        }
        return r;
    }
}