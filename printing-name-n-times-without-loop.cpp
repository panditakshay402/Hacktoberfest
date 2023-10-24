#include <iostream>

void printNameNTimes(int n, const std::string& name) {
    if (n > 0) {
        std::cout << name << std::endl;
        printNameNTimes(n - 1, name);
    }
}

int main() {
    int n = 5;  // Change this to the desired number of times
    std::string name = "YourName";  // Change this to the desired name

    printNameNTimes(n, name);

    return 0;
}
