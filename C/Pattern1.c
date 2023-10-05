#include <stdio.h>

int main() {
    int i, j, rows;

    // Prompt the user to enter the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop to iterate through rows
    for (i = 1; i <= rows; i++) {
        // Inner loop to print spaces before numbers
        for (j = 1; j <= rows - i; j++) {
            printf("  "); // Two spaces for alignment
        }

        // Inner loop to print numbers
        for (j = 1; j <= i; j++) {
            printf("%2d ", j); // %2d ensures a minimum width of 2 characters for alignment
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}

// Explanation:

// We start by including the necessary header file, <stdio.h>, which is required for input and output functions.

// We declare integer variables i, j, and rows. i is used to iterate through rows, j is used for column printing, and rows stores the user input for the number of rows.

// We prompt the user to enter the number of rows using printf and then read the input using scanf.

// We use an outer loop (for loop) to iterate through the rows. The loop runs from 1 to rows.

// Inside the outer loop, we use two inner loops:

// The first inner loop (for j) is used to print spaces before the numbers. The number of spaces is determined by rows - i to create a right-angled triangle effect.

// The second inner loop (for j) is used to print the numbers. We use %2d in printf to ensure that each number occupies at least two characters for better alignment.

// After printing each row of numbers, we move to the next line using printf("\n") to start a new row.

// This program will print a right-angled triangle pattern of numbers with proper alignment and comments for clarity. You can change the number of rows by entering a different value when prompted.