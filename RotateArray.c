#include <stdio.h>

void reverse(int* nums, int start, int end) {
    // Helper function to reverse a subarray.
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize; // Ensure k is within the array length.

    // Reverse the entire array.
    reverse(nums, 0, numsSize - 1);
    // Reverse the first k elements.
    reverse(nums, 0, k - 1);
    // Reverse the remaining elements.
    reverse(nums, k, numsSize - 1);
}

int main() {
    int nums1[] = {1, 2, 3, 4, 5, 6, 7};
    int k1 = 3;
    int numsSize1 = 7;

    rotate(nums1, numsSize1, k1);

    printf("Output: [");
    for (int i = 0; i < numsSize1; i++) {
        printf("%d", nums1[i]);
        if (i < numsSize1 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    int nums2[] = {-1, -100, 3, 99};
    int k2 = 2;
    int numsSize2 = 4;

    rotate(nums2, numsSize2, k2);

    printf("Output: [");
    for (int i = 0; i < numsSize2; i++) {
        printf("%d", nums2[i]);
        if (i < numsSize2 - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
