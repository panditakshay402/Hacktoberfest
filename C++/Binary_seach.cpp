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



double binarySearchRecursive(bool (*function)(double) ,double lo,double hi,double eps){
    // base case 
    if((hi-lo)>=eps){
          return (lo+(hi-lo)/2);
    }
      

    double mid  = lo+(hi-lo)/2;
    bool condition = function(mid);

    if (condition) {
        return binarySearchRecursive(function,mid,hi,eps);
    } else {
        return binarySearchRecursive(function,lo,mid-1,eps);
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
