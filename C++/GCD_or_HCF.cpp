#include <iostream>

using namespace std;

// Function to calculate the GCD of two numbers using the Euclidean algorithm
int findGCD(int a, int b) {
    // Keep looping until b becomes 0
    while (b != 0) {
        // Store the current value of b
        int temp = b;
        // Update b to be the remainder when a is divided by b
        b = a % b;
        // Assign the previous value of b to a
        a = temp;
    }
    // When b becomes 0, a contains the GCD
    return a;
}

int main() {
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Find and display the GCD
    int gcd = findGCD(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;

    return 0;
}
