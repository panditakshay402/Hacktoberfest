#include <iostream>
using namespace std;

// The gcd function is a recursive function uses Euclid's algorithm to calculate the GCD of two integers a and b.
// The algorithm states that the GCD of two numbers is the same as the GCD of the smaller number and the remainder of the larger number divided by the smaller number.
// This process is repeated until the remainder is 0, at which point the GCD is found.
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: \n";
    cin >> num1 >> num2;

    int result = gcd(num1, num2);
    cout << "GCD/HCF of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}

// What is GCD/HCF?
// GCD (Greatest Common Divisor) or HCF (Highest Common Factor) of two numbers is the largest number that divides both of them.
// For example GCD of 20 and 28 is 4 and GCD of 98 and 56 is 14.

// What is Euclid's Algorithm?
// Euclid's algorithm is an efficient method for computing the greatest common divisor (GCD) of two numbers,
// the largest number that divides both of them without leaving a remainder.
