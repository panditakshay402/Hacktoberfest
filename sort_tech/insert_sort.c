#include <stdio.h>

// Function to implement Insertion Sort
void insertionSort(int arr[], int n) {
    int step = 1;  // Step counter

    // Loop through each element starting from the second element
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Print the array state before insertion
        printf("Step %d: ", step++);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Print the array after insertion
        printf("Step %d: ", step++);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("=> Inserted %d\n", key);
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

    // Calling the insertionSort function
    insertionSort(arr, n);

    // Final sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
