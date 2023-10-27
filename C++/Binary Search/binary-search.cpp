#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& sortedArray, int target){
    int left = 0;
    int right = sortedArray.size() - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;

        // checking target at middle
        if (sortedArray[mid] == target){
            return mid;
        }

        // if target is greater, exclude the left of the array.
        if (sortedArray[mid] < target){
            left = mid + 1;
        }
        
        // Else exclude the right part of the array.
        else{
            right = mid - 1;
        }
    }

    return -1;
}

int main(){

    // given a sorted array.
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17};

    int target = 7;
    int result = binarySearch(sortedArray, target);

    if (result != -1){
        cout << "Element found at index: " << result << "\n"; 
    }
    else{
        cout << "Element not found in the array." << "\n"; 
    }

    return 0;
}