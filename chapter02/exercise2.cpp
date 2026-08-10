/*
Write a program in C++ that converts from miles to kilometers. 
Your program should have a reasonable prompt for the user to 
enter a number of miles. Hint: A mile is1.609 kilometers.
*/
#include <iostream>
int main(){
    double miles{0};
    std::cout << "Enter the number of miles: ";
    std::cin >> miles;
    double kilometers = miles * 1.609;
    std::cout << miles << " miles is " << kilometers << " kilometers.\n";
    return 0;
}