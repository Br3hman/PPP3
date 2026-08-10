/*
Write a program that prompts the user to enter three integer values, 
and then outputs the values in numerical sequence separated by commas. 
So, if the user enters the values 10 4 6, the output should be 4, 6, 10. 
If two values are the same, they should just be ordered together. 
So, the input 4 5 4 should give 4, 4, 5.
*/
#include <iostream>
int main(){
    int val1, val2, val3;
    std::cout << "Enter three integer values: ";
    std::cout << "Value 1: ";
    std::cin >> val1;
    std::cout << "Value 2: ";
    std::cin >> val2;
    std::cout << "Value 3: ";
    std::cin >> val3;

    if (val1 <= val2 && val1 <= val3){
        if(val2 <= val3){
            std::cout << val1 << ", " << val2 << ", " << val3;
        } else {
            std::cout << val1 << ", " << val3 << ", " << val2;
        }
    }else if (val2 <= val1 && val2 <= val3){
        if(val1 <= val3){
            std::cout << val2 << ", " << val1 << ", " << val3;
        } else {
            std::cout << val2 << ", " << val3 << ", " << val1;
        }
    }else{
        if(val1 <= val2){
            std::cout << val3 << ", " << val1 << ", " << val2;
        } else {
            std::cout << val3 << ", " << val2 << ", " << val1;
        }
    }
    return 0;
}
