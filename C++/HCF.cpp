#include<bits/stdc++.h>
using namespace std;
// #define int long long
// #define endl "\n"

// Function to find HCF using Euclidean Algorithm
int findHCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    // Input two numbers from the user
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int hcf = findHCF(num1, num2);
    std::cout << "The Highest Common Factor (HCF) of " << num1 << " and " << num2 << " is: " << hcf << std::endl;

    return 0;
}
