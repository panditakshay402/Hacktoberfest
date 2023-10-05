#include <stdio.h>

int main() {
    int i, j, space, rows;

    // Prompt the user to enter the number of rows (must be an odd number for a symmetric diamond)
    printf("Enter the number of rows (odd number): ");
    scanf("%d", &rows);

    if (rows % 2 == 0) {
        printf("Please enter an odd number for a symmetric diamond.\n");
        return 1; // Exit the program with an error code
    }

    int midpoint = (rows + 1) / 2; // Calculate the midpoint of the diamond

    // Loop to print the upper half of the diamond
    for (i = 1; i <= midpoint; i++) {
        // Loop to print leading spaces
        for (space = 1; space <= midpoint - i; space++) {
            printf(" ");
        }

        // Loop to print asterisks
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }

        // Move to the next line after each row
        printf("\n");
    }

    // Loop to print the lower half of the diamond
    for (i = midpoint - 1; i >= 1; i--) {
        // Loop to print leading spaces
        for (space = 1; space <= midpoint - i; space++) {
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

// This program prints a diamond pattern of asterisks with the specified number of rows. It includes a check to ensure that the number of rows entered by the user is odd because a symmetric diamond pattern requires an odd number of rows.

// It declares integer variables i, j, space, rows, and midpoint. i is used to iterate through rows, j is used for printing asterisks, space is used for printing leading spaces, rows stores the user input for the number of rows, and midpoint calculates the midpoint of the diamond.

// The program prompts the user to enter the number of rows and reads the input using scanf.

// It checks if the entered number of rows is even. If it is, it prints an error message and exits the program with an error code.

// The program calculates the midpoint of the diamond pattern.

// It uses an outer loop (for i) to print the upper half of the diamond pattern and another outer loop to print the lower half of the diamond pattern. Both loops use similar logic for printing leading spaces and asterisks.

// After printing each row, the program moves to the next line using printf("\n").

// This program will print a diamond pattern made of asterisks with the specified number of rows, ensuring it is symmetric for odd row counts. You can change the number of rows by entering a different odd value when prompted.