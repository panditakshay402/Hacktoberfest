#include <stdio.h>

int main() {
    int i, j, space, rows;

    // Prompt the user to enter the number of rows
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Loop to print the rows
    for (i = 1; i <= rows; i++) {
        // Loop to print leading spaces
        for (space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        // Loop to print asterisks
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        // Move to the next line after each row
        printf("\n");
    }

    return 0;
}

// Explanation:

// This program, like the previous one, includes the necessary header file <stdio.h> for input and output functions.

// We declare integer variables i, j, space, and rows. i is used to iterate through rows, j is used for printing asterisks, space is used for printing leading spaces, and rows stores the user input for the number of rows.

// The program prompts the user to enter the number of rows and reads the input using scanf.

// We use an outer loop (for i) to iterate through the rows, starting from 1 and going up to rows.

// Inside the outer loop, we have two inner loops:

// The first inner loop (for space) is used to print leading spaces before the asterisks. The number of spaces is determined by rows - i.

// The second inner loop (for j) is used to print the asterisks. The number of asterisks in each row is 2 * i - 1, which creates a pyramid shape.

// After printing each row, we move to the next line using printf("\n") to start a new row.

// This program will print a pyramid pattern made of asterisks with the specified number of rows. You can change the number of rows by entering a different value when prompted.