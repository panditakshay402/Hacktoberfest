//We start by including the necessary header files, which in this case is <iostream> for input and output.
#include <iostream>
using namespace std;

//We create a function named findHCF that takes two integers as input parameters, num1 and num2. This function will calculate the HCF of these two numbers.
int findHCF(int num1, int num2) {
    // Inside 'findHCF' function  we initialize a variable to store the HCF
    int hcf;

    //We use a for loop to iterate from 1 to the minimum of num1 and num2.
//Inside the loop, we check if both num1 and num2 are divisible by the current value of i using the modulus operator (%).
//If both numbers are divisible by i, we update the hcf variable with the current value of i. This is because, at this point, i is a common factor of both num1 and num2.
    for (int i = 1; i <= min(num1, num2); ++i) {
        // Check if both num1 and num2 are divisible by i
        if (num1 % i == 0 && num2 % i == 0) {
            // If yes, update the HCF to the current value of i
            hcf = i;
        }
    }

    // Return the HCF
    return hcf;
}
//In the main function, we input two numbers from the user using cin.
//We then call the findHCF function with the input numbers and store the result in the hcf variable.
//Finally, we output the HCF to the user.
int main() {
    int num1, num2;

    // Input two numbers from the user
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Call the findHCF function to calculate the HCF
    int hcf = findHCF(num1, num2);

    // Output the result
    cout << "The Highest Common Factor (HCF) of " << num1 << " and " << num2 << " is " << hcf << endl;

    return 0;
}
