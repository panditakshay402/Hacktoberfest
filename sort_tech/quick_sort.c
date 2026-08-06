#include <stdio.h>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high, int* step) {
    int pivot = arr[high];  // Pivot element
    int i = low - 1;        // Index of the smaller element

    for (int j = low; j < high; j++) {
        // Print the array state before comparison
        printf("Step %d: ", (*step)++);
        for (int k = low; k <= high; k++) {
            printf("%d ", arr[k]);
        }

        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of the smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            printf("=> Swapped %d and %d", arr[i], arr[j]);
        }
        printf("\n");
    }

    // Swap the pivot element with the element at index (i + 1)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    printf("Step %d: ", (*step)++);
    for (int k = low; k <= high; k++) {
        printf("%d ", arr[k]);
    }
    printf("=> Swapped pivot %d and %d\n", arr[i + 1], arr[high]);

    return i + 1;  // Return the partition point
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high, int* step) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivotIndex = partition(arr, low, high, step);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1, step);
        quickSort(arr, pivotIndex + 1, high, step);
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

    int step = 1;  // Step counter to track comparisons
    quickSort(arr, 0, n - 1, &step);

    // Final sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
