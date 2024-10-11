# Binary Search Implementation

## Overview
Binary Search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing the portion of the list that could contain the item in half until you've narrowed down the possible locations to just one.

## Iterative Binary Search Implementation

### C++ Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search iteratively
// Time Complexity: O(log n), Space Complexity: O(1)
int binarySearch(vector<int> &arr, int target)
{
    int n = arr.size();
    int start = 0;       
    int end = n - 1;     
    
    // Loop until the start index exceeds the end index
    while (start <= end)
    {
        // Calculate mid index to avoid overflow
        int mid = start + (end - start) / 2;
        
        // Check if the target is found at mid index
        if (target == arr[mid])
            return mid;  // Return the mid index if found
        else if (target > arr[mid])
            start = mid + 1;  // Search in right half
        else
            end = mid - 1;    // Search in left half
    }
    return -1;  // Return -1 if the target is not found
}

int main()
{
    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12}; // Example sorted array
    cout << binarySearch(arr, 3) << endl;
    return 0;
}
```
### Recursion Binary Serach Implemenation

### C++ Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search recusrively
// Time Complexity: O(log n), Space Complexity: O(log n)
int recursiveBinarySearch(vector<int> &arr, int target, int start, int end)
{
    // Base condition: if search range is valid
    if (start <= end)
    {
        // Calculate the middle index (avoids overflow)
        int mid = start + (end - start) / 2; 

        // If target is less than mid element, search left half
        if (target < arr[mid])
        {
            return recursiveBinarySearch(arr, target, start, mid - 1);
        }
        // If target is greater than mid element, search right half
        else if (target > arr[mid])
        {
            return recursiveBinarySearch(arr, target, mid + 1, end);
        }
        // Target found at mid index
        else
        {
            return mid;
        }
    }

    // Target not found in array
    return -1;
}
int main()
{
    vector<int> arr = {-1, 0, 3, 4, 5, 9, 12}; // Example sorted array
    int n = arr.size();
    cout << recursiveBinarySearch(arr, 9, 0, n - 1) << endl;
    return 0;
}

```
## Complexity Analysis

### Iterative Binary Search
- **Time Complexity**: O(log n)
  - The algorithm halves the search space with each comparison, making it efficient for large datasets.

- **Space Complexity**: O(1)
  - The iterative approach uses a constant amount of space, as it does not require additional space for function call stacks.

### Recursive Binary Search
- **Time Complexity**: O(log n)
  - Similar to the iterative version, it also reduces the search space by half with each recursive call.

- **Space Complexity**: O(log n)
  - The recursive approach utilizes the call stack, which can lead to increased memory usage for deep recursion.

### Why Iterative is Preferred
- **Memory Efficiency**: The iterative approach uses O(1) space, making it more memory-efficient than the recursive version, which requires O(log n) space due to the call stack.
  
- **Performance**: Iterative solutions generally have lower overhead than recursive solutions. Each recursive call involves function call overhead, which can slow down execution.

- **Avoiding Stack Overflow**: The iterative approach can handle larger datasets without the risk of stack overflow errors that can occur with deep recursion in the recursive version.

In summary, the iterative binary search is often favored in practice due to its efficiency in both time and space, making it a more robust solution for larger datasets.
