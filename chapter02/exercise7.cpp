/*  
Do exercise 6, but with three string values. 
So, if the user enters the values 
Steinbeck, Hemingway, Fitzgerald, 
the output should be Fitzgerald, Hemingway, Steinbeck.
*/
#include <iostream>
#include <string>
int main(){
    std::string val1, val2, val3;
    std::cout << "Enter three names: ";
    std::cout << "Name 1: ";
    std::cin >> val1;
    std::cout << "Name 2: ";
    std::cin >> val2;
    std::cout << "Name 3: ";
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