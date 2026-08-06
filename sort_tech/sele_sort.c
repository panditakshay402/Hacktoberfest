#include <stdio.h>

// Function to implement Selection Sort
void selectionSort(int arr[], int n) {
    int step = 1;  // To keep track of the step number

    // Loop through all elements
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        int minIndex = i;

        // Print the current state before finding the minimum
        printf("Step %d: ", step++);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        // Print the array after swapping
        printf("Step %d: ", step++);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("=> Swapped %d and %d\n", arr[i], arr[minIndex]);
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

    // Calling the selectionSort function
    selectionSort(arr, n);

    // Final sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
