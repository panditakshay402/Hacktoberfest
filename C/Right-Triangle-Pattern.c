#include <stdio.h>

int main() {
    int rows;

    // Ask the user to enter the number of rows in the pattern
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    // Outer loop will iterate through each row of the pattern
    for(int i = 1; i <= rows; i++) {
        // Inner loop will print stars in each row
        for(int j = 1; j <= i; j++) {
            // Print a star and a space
            printf("* ");
        }
        // Move to the next line after printing stars in one row
        printf("\n");
    }

    return 0;
}
