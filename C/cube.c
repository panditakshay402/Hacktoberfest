#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of the cube: ");
    scanf("%d", &size);

    // Loop for the height of the cube
    for (int i = 0; i < size; i++) {
        // Loop for the depth of the cube
        for (int j = 0; j < size; j++) {
            // Loop for the width of the cube
            for (int k = 0; k < size; k++) {
                // Check if it's an edge or a corner of the cube
                if (i == 0 || i == size - 1 || j == 0 || j == size - 1 || k == 0 || k == size - 1) {
                    // Print a '*' to represent the surface of the cube
                    printf("* ");
                } else {
                    // Print a space for the interior of the cube
                    printf("  ");
                }
            }
            // Move to the next depth line
            printf("\n");
        }
        // Separate each level of the cube
        printf("\n");
    }

    return 0;
}
