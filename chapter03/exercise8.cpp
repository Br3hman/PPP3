/*
[8] Modify the “mini calculator” from exercise 6 to accept (just) single-digit 
numbers written as either digits or spelled out.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

double convertToDouble(const std::string& input, const std::vector<std::string>& digits) {
    if (isdigit(input[0])) {
        return input[0] - '0'; // Convert char digit to double
    } else {
        auto it = std::find(digits.begin(), digits.end(), input);
        if (it != digits.end()) {
            return static_cast<double>(std::distance(digits.begin(), it)); // Convert spelled-out number to double
        } else {
            throw std::invalid_argument("Invalid input: " + input);
        }
    }
}
int main(){
    std::string inputA, inputB;
    std::vector<std::string> digits{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    double a{0}, b{0};
    std::string operator_;
    std::cout << "Enter two numbers (a and b) followed by an operator (+,-,*,/): ";
    std::cin >> inputA >> inputB >> operator_;

    try {
        a = convertToDouble(inputA, digits);
        b = convertToDouble(inputB, digits);
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 1; // Exit with error
    }


    if(operator_=="+"){
        std::cout<<"The sum of "<<a<<" and "<<b<<" is: "<<a+b<<std::endl;
    }else if(operator_=="-"){
        std::cout<<"The difference of "<<a<<" and "<<b<<" is: "<<a-b<<std::endl;
    }else if(operator_=="*"){
        std::cout<<"The product of "<<a<<" and "<<b<<" is: "<<a*b<<std::endl;
    }else if(operator_=="/"){
        if(b!=0){
            std::cout<<"The quotient of "<<a<<" and "<<b<<" is: "<<a/b<<std::endl;
        }else{
            std::cout<<"Division by zero is not allowed."<<std::endl;
        }
    }else{
        std::cout<<"Invalid operator. Please use '+,-,*,/'."<<std::endl;
    }

    return 0;
}