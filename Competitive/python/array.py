def maxSubArray(nums):
    # Initialize variables to store the maximum sum and current sum
    max_sum = float('-inf')  # Initialize to negative infinity to handle all negative numbers
    current_sum = 0
    
    # Iterate through the array
    for num in nums:
        # Update the current sum by either continuing the subarray or starting a new one
        current_sum = max(num, current_sum + num)
        
        # Update the maximum sum if the current sum is greater
        max_sum = max(max_sum, current_sum)
    
    # Return the maximum subarray sum
    return max_sum

# Example usage
nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
result = maxSubArray(nums)
print("Maximum Subarray Sum:", result)


# Explanation of each line:

# def maxSubArray(nums):: This line defines a function called maxSubArray that takes an array of integers (nums) as input.

# max_sum = float('-inf'): Initialize a variable max_sum to negative infinity. This is done to ensure that the first element of the array is considered as the starting point for the maximum subarray sum.

# current_sum = 0: Initialize a variable current_sum to zero, which will keep track of the current sum of the subarray as we iterate through the array.

# for num in nums:: Start a loop to iterate through each element (num) in the input array nums.

# current_sum = max(num, current_sum + num): Update the current sum. We compare the current element num with the sum of the current subarray (current_sum + num). We take the maximum of these two values to decide whether to continue the current subarray or start a new one.

# max_sum = max(max_sum, current_sum): Update the maximum subarray sum (max_sum) if the current sum is greater than the previous maximum sum.

# return max_sum: Finally, the function returns the maximum subarray sum.

# nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]: Example input array.

# result = maxSubArray(nums): Call the maxSubArray function with the input array and store the result in the result variable.

# print("Maximum Subarray Sum:", result): Print the maximum subarray sum to the console.







