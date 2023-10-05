#include <iostream>
#include <string>

void printName(int N, const std::string& name) {
    if (N > 0) {
        std::cout << name << std::endl;
        printName(N - 1, name);
    }
}

int main() {
    int N;
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter the number of times to print your name: ";
    std::cin >> N;

    printName(N, name);

    return 0;
}
