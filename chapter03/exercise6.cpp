/*
[6] Write a program that performs as a very simple calculator. Your calculator should be 
able to handle the four basic math operations – add, subtract, multiply, and divide –
on two input values. Your program should prompt the user to enter three arguments: 
two double values and a character to represent an operation. If the entry arguments 
are 35.6, 24.1, and '+', the program output should be The sum of 35.6 and 24.1 is 59.7. 
In Chapter 5 and Chapter 6, we look at a much more sophisticated simple calculator.
*/
#include <iostream>
#include <string>
//#include <vector>
//#include <algorithm>

int main(){
    double a{0}, b{0};
    std::string operator_;
    std::cout << "Enter two numbers (a and b) followed by an operator (+,-,*,/): ";
    std::cin >> a >> b >> operator_;
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