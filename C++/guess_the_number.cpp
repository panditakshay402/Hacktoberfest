#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
    int secretNumber = rand() % 100 + 1;       // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    std::cout << "Welcome to Guess the Number!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber)
            std::cout << "Too low! Try again." << std::endl;
        else if (guess > secretNumber)
            std::cout << "Too high! Try again." << std::endl;
        else
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts!" << std::endl;

    } while (guess != secretNumber);

    return 0;
}
