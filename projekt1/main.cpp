#include "DiningPhilosophers.h"
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

// Function to check if a string contains only digits (valid natural number)
bool isNaturalNumber(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    // Check if exactly one argument is provided
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <number_of_philosophers>" << endl;
        return 1;
    }

    string input = argv[1];

    // Validate if the input is a natural number
    if (!isNaturalNumber(input)) {
        cerr << "Error: The argument must be a natural number (positive integer)." << endl;
        return 1;  // Return error code
    }

    int numPhilosophers = stoi(input);

    // Validate if the number is greater than zero
    if (numPhilosophers <= 0) {
        cerr << "Error: The number of philosophers must be greater than zero." << endl;
        return 1;  // Return error code
    }

    // Start the dining philosophers simulation
    DiningPhilosophers dp(numPhilosophers);
    dp.start();

    return 0;
}
