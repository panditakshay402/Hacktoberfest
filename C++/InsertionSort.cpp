#include <iostream>
#include <vector>

using namespace std;

// Insertion sort.
/*
Time Complexity: O(n^2);
Stability: True; // as we implemented it when we used arr[j] <= temp for not shifting the first number.
Adaptive = True; // as when array is sorted its time complexity is O(n) i.e less than actual time complexity, means it is making use of the fact that array is sorted if it is sorted.

>> comparison with Bubble sort: 
    Bubble sort is better as if in bubble sort in one iteration we found that we do not swapped any element, 
    then this implies that the array is "now"(after that iteration) is sorted and we stop there, but there is no such convinience in insersion sort.

*/

void show(vector<int> arr){
    for (int i=0;i<arr.size();i++){
        cout << arr[i] << endl;
    }
}

void insertionSort(vector<int>& arr){
    for (int i=1;i<arr.size();i++){
        for (int j=i-1;j>=0;j--){
            int temp = arr[j+1];
            if (arr[j] > temp){
                arr[j+1] = arr[j];
                arr[j] = temp;
            }else if (arr[j] <= temp){
                arr[j+1] = temp;
            }
        }
    }
}

int main(){

    int size;
    cin >> size;

    vector <int> arr(size);
    for (int i=0;i<size;i++){
        cin >> arr[i];
    }
    
    insertionSort(arr);
    cout << "SHOWING SORTED ARRAY (BY INSERSION SORT): " << endl;
    show(arr);
    



    return 0;
}