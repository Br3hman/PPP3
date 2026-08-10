/*
[7] Make a vector holding the ten string values "zero", "one", . . . "nine". 
Use that in a program that converts a digit to its corresponding 
spelled-out value; e.g., the input 7 gives the output seven. Have the same program, 
using the same input loop, convert spelled-out numbers into their digit 
form; e.g., the input seven gives the output 7.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    // Lookup table: index == numeric value, e.g. digits[7] == "seven"
    std::vector<std::string> digits{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    std::string input;
    std::cout << "Enter a digit (0-9) or a spelled-out number (zero-nine):" << std::endl;

    // Keep reading until the user types 'q'
    while (std::cin >> input && input != "q") {
        if (input.size() == 1 && isdigit(input[0])) {
            // Single character digit: convert char to int by subtracting '0'
            // e.g. '7' - '0' == 7, then use as index into the vector
            int index = input[0] - '0';
            std::cout << digits[index] << std::endl;
        } else {
            // Spelled-out word: search the vector for a matching string
            auto it = std::find(digits.begin(), digits.end(), input);
            if (it != digits.end()) {
                // Match found — distance from begin() equals the numeric value
                std::cout << std::distance(digits.begin(), it) << std::endl;
            } else {
                // Input was neither a single digit nor a recognised word
                std::cout << "Invalid input" << std::endl;
            }
        }
        std::cout << "Enter a digit (0-9) or a spelled-out number (zero-nine) or 'q' to quit:" << std::endl;
    }

    return 0;
}