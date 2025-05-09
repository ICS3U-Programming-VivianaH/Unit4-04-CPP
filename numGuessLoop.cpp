// Copyright 2025 Viviana Hurtado
// Created by: Viviana Hurtado
// Date: April, 2025
// This program generates a random correct guess.
// It then uses a loop to keep asking the user to
// guess the number until they guess correctly.

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main() {
    // declare integer
    int randomNumber;

    // random seed
    srand((unsigned)time(NULL));

    // Get random number between 0 and 9
    unsigned int seed = time(NULL);
    randomNumber = rand_r(&seed) % 10;

    // loop until correct guess
    while (true) {
        std::string userGuessAsString;
        int userGuessAsInt;

        std::cout << "Guess the number (between 0 and 9): ";
        std::getline(std::cin, userGuessAsString);

        try {
            // convert the user's guess to an int
            userGuessAsInt = std::stoi(userGuessAsString);

            // check if the guess is correct
            if (userGuessAsInt == randomNumber) {
                std::cout << "You guessed it! The number was " << randomNumber << ".\n";
                break;
            } else {
                std::cout << "Wrong guess. Try again.\n";
            }
        } catch (std::invalid_argument const&) {
            std::cout << userGuessAsString << " is not an integer.\n";
        }
    }
}
