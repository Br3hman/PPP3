/* 
Write a program that reads a string from input and then, for each character read, 
prints out the character and its integer value on a line.
*/
#include <iostream>
#include <string>

int main(){
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;
    for (char c : input) {
        std::cout << c << " " << static_cast<int>(c) << std::endl;
    }
    return 0;
}