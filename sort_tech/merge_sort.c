#include <stdio.h>

// Function to merge two halves of the array
void merge(int arr[], int left, int mid, int right, int* step) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays to hold the divided parts
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into arr[left..right]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Print the array state after merging
    printf("Step %d: ", (*step)++);
    for (int l = left; l <= right; l++) {
        printf("%d ", arr[l]);
    }
    printf("\n");
}

// Function to implement Merge Sort
void mergeSort(int arr[], int left, int right, int* step) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively divide the array
        mergeSort(arr, left, mid, step);
        mergeSort(arr, mid + 1, right, step);

        // Merge the divided parts
        merge(arr, left, mid, right, step);
    }
}

int main() {
    int n;

    // Asking the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Taking input from the user for the array
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int step = 1; // Step counter to track comparisons
    mergeSort(arr, 0, n - 1, &step);

    // Final sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
