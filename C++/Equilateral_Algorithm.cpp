#include<bits/stdc++.h>
using namespace std;

int main() {
    // Initialize variables to store the lengths of the three sides of the triangle
    double side1, side2, side3;

    // Prompt the user to input the lengths of the three sides
    cout << "Enter the length of side 1: ";
    cin >> side1;
    cout << "Enter the length of side 2: ";
    cin >> side2;
    cout << "Enter the length of side 3: ";
    cin >> side3;

    // Check if all three sides are equal (equilateral)
    if (side1 == side2 && side2 == side3) {
        cout << "It's an equilateral triangle." << endl;
    } else {
        cout << "It's not an equilateral triangle." << endl;
    }

    return 0;
}

// Explanation:

// Include the necessary header file <iostream> to enable input and output operations.

// Create the main function, the entry point of the program.

// Declare three variables (side1, side2, and side3) to store the lengths of the three sides of the triangle.

// Prompt the user to input the lengths of the three sides using cout and cin for each side.

// Check if all three sides are equal. If they are, it's an equilateral triangle because all sides of an equilateral triangle have the same length. We use an if statement to perform this check.

// If all three sides are equal, display "It's an equilateral triangle" using cout. Otherwise, display "It's not an equilateral triangle."

// Finally, return 0 to indicate successful execution of the program.

// This program calculates whether a triangle is equilateral based on user-provided side lengths. If all three sides are equal, it's an equilateral triangle; otherwise, it's not.