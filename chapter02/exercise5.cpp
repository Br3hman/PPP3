/* 
Write a program that prompts the user to enter two integer values. 
Store these values in int variables named val1 and val2. 
Write your program to determine the smaller, larger, sum, 
difference, product, and ratio of these values and report them to the user.
*/
#include <iostream>
int main(){
    double val1, val2;
    
    std::cout << "Enter two double values:\n ";
    std::cout << "Value 1: ";
    std::cin >> val1;


    std::cout << "Value 2: ";
    std::cin >> val2;

    std::cout << "Smaller value: " << (val1 < val2 ? val1 : val2);
    std::cout << "\nLarger value: " << (val1 > val2 ? val1 : val2);
    std::cout << "\nSum: " << (val1 + val2);
    std::cout << "\nDifference (Value 1 - Value 2): " << (val1 - val2);
    std::cout << "\nDifference (Value 2 - Value 1): " << (val2 - val1);

    std::cout << "\nProduct: " << (val1 * val2);
    
    if (val2 != 0) {
        std::cout << "\nRatio (Value 1 / Value 2): " << (val1 / val2);
    } else {
        std::cout << "\nRatio: Undefined (division by zero)";
    }
    return 0;
}