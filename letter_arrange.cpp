#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string user_input;

    // Take user input for a string of characters
    std::cout << "Enter a string of characters: ";
    std::cin >> user_input;

    // Sort the characters in the input string
    std::sort(user_input.begin(), user_input.end());

    // Print the sorted characters
    std::cout << "Characters in alphabetical order: " << user_input << std::endl;

    return 0;
}
