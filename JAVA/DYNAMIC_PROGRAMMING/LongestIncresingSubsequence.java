// A Naive Java Program for LIS Implementation
import java.io.*;
import java.util.*;

class LIS {

	// Stores the LIS
	static int max_ref;

	static int _lis(int arr[], int n)
	{
		// Base case
		if (n == 1)
			return 1;

		
		int res, max_ending_here = 1;

		for (int i = 1; i < n; i++) {
			res = _lis(arr, i);
			if (arr[i - 1] < arr[n - 1]
				&& res + 1 > max_ending_here)
				max_ending_here = res + 1;
		}

		
		if (max_ref < max_ending_here)
			max_ref = max_ending_here;

		// Return length of LIS ending with arr[n-1]
		return max_ending_here;
	}

	// The wrapper function for _lis()
	static int lis(int arr[], int n)
	{
		// The max variable holds the result
		max_ref = 1;

		// The function _lis() stores its result in max
		_lis(arr, n);

		// Returns max
		return max_ref;
	}

	// Driver program to test above functions
	public static void main(String args[])
	{
		int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
		int n = arr.length;

		// Function call
		System.out.println("Length of lis is "
						+ lis(arr, n));
	}
}

