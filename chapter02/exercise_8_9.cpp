/*
[8] Write a program to test an integer value to determine if it is odd or even. 
As always, make sure your output is clear and complete. In other words, 
don’t just output yes or no. Your output should stand alone, 
like The value 4 is an even number. 
[9] Write a program that converts spelled-out numbers such as “zero” and “two” 
into digits, such as 0 and 2. When the user inputs a number, 
the program should print out the corresponding digit. 
Do it for the values 0, 1, 2, 3, and 4 and write out not a number I know 
if the user enters something that doesn’t correspond, such as stupid computer!. 
*/

#include <iostream>
#include <string>
int main() {
    int value;
    std::cout << "Enter an integer value: ";
    std::cin >> value;
    if (value % 2 == 0) {
        std::cout << "The value " << value << " is an even number." << std::endl;
    } else {
        std::cout << "The value " << value << " is an odd number." << std::endl;
    }
    std::string spelled_out_number;
    std::cout << "Lets convert a spelled-out number to a digit." << std::endl;
    std::cout << "Enter a spelled-out number (zero, one, two, three, four): ";
    std::cin >> spelled_out_number;
    if(spelled_out_number == "zero") {
        std::cout << 0 << std::endl;
    } else if(spelled_out_number == "one") {
        std::cout << 1 << std::endl;
    } else if(spelled_out_number == "two") {
        std::cout << 2 << std::endl;
    } else if(spelled_out_number == "three") {
        std::cout << 3 << std::endl;
    } else if(spelled_out_number == "four") {
        std::cout << 4 << std::endl;
    } else {
        std::cout << "not a number I know" << std::endl;
    }
}