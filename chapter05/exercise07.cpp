/*
[7] Write a program that reads digits and composes them into integers. 
For example, 123 is read as the characters 1, 2, and 3. 
The program should output 123 is 1 hundred and 2 tens and 3 ones. 

The number should be output as an int value. 
Handle numbers with one, two, three, or four digits. 
Hint: To get the integer value 5 from the character 
'5' subtract '0', that is, '5'−'0'==5.

*/
#include <iostream>
#include <stdexcept>
//#include <string>
#include <vector>
//#include <cstddef>   // for std::size_t
#include <algorithm>
//#include <map>
//#include<cmath>




//------------------------------------------------



bool is_digit(const std::string& str) {
    return std::all_of(str.begin(), str.end(), [](char c) { return std::isdigit(c); });
}
int main() {
    try
    {
        std::string input;
        std::cout << "Enter a number (up to 4 digits): ";
        std::cin >> input;
        if (!is_digit(input) || input.length() > 4) {
            throw std::runtime_error("Invalid input. Please enter a number with up to 4 digits.");
        }
        int number = std::stoi(input);

        std::vector<std::string> numbers = {"thousand","hundred","ten","one"};
        std::cout << number << " is";
        for(size_t i = 0; i<input.size(); ++i){
            int digit = input[i] - '0';
            size_t idx = numbers.size() - (input.size()-i);
            if(i==0 && digit==0){
                std::cout<<"";
            }
            else
                {
                    if(i!=0 && (input[0]-'0')!=0 ) std::cout<<" and";
                    std::cout<<" "<< digit<<" "<<( digit <= 1 ? numbers[idx]:numbers[idx]+"s");
                }
        }
        std::cout << ".\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}


