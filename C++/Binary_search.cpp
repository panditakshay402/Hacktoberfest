#include <iostream>
#include <vector>

int binarySearchRecursive(const std::vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // Target not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Target found at index 'mid'
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    } else {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 7;
    int result = binarySearchRecursive(arr, target, 0, arr.size() - 1);

    if (result != -1) {
        std::cout << "Target " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
 
// Driver's code
int main()
{
    // initializing vector of integers
    vector<int> arr = { 10, 15, 20, 25, 30, 35 };
 
    // using binary_search to check if 15 exists
    if (binary_search(arr.begin(), arr.end(), 15))
        cout << "15 exists in vector";
    else
        cout << "15 does not exist";
 
    cout << endl;
 
    // using binary_search to check if 23 exists
    if (binary_search(arr.begin(), arr.end(), 23))
        cout << "23 exists in vector";
    else
        cout << "23 does not exist";
 
    cout << endl;
}
