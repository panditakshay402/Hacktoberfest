#include <stdio.h>

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n) {
    int step = 1; // To keep track of the step number
    
    // Outer loop for each pass over the array
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; // Flag to track if any swapping happened in this pass
        
        // Inner loop to perform the swapping of adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            // Print the array state before comparison
            printf("Step %d: ", step);
            for (int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
            }

            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap them if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
                printf("=> Swapped %d and %d", arr[j], arr[j + 1]);
            }
            printf("\n");
            step++;
        }

        // If no two elements were swapped, the array is already sorted
        if (swapped == 0)
            break;
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

    // Calling the bubbleSort function
    bubbleSort(arr, n);

    // Final sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
