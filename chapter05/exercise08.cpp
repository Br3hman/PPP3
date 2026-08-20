/*
[8] A permutation is an ordered subset of a set. For example,
say you wanted to pick a combination to a vault. There are 60 possible numbers,
and you need three different numbers for the combination.
There are P(60, 3) permutations for the combination,
where P is defined by the formula P(a, b) = (a!) / ((a - b)!)
where ! is used as a suffix factorial operator.
For example, 4! is 4*3*2*1. Combinations are similar to permutations, except that
the order of the objects doesn’t matter. For example, if you were making a
“banana split” sundae and wished to use three different flavors of ice cream
out of five that you had, you probably wouldn’t care if you put a scoop of vanilla at the beginning
or the end or the serving dish.

The formula for combinations is C(a, b) = (P(a, b)) / (b!)
Design a program that asks users for two numbers,
asks them whether they want to calculate permutations or combinations,
and prints out the result. This will have several parts.
Do an analysis of the above requirements. Write exactly what the program will have to do.
Then, go into the design phase. Write pseudo code for the program and break it into
subcomponents. This program should have error checking.

Make sure that all erroneous inputs will generate good error messages.

1. write a factorial function with error message in case number is negative
2. write a function that calculate the permutation using the formula for permutations is  P(a, b) = (a!) / ((a - b)!)
3. wirte a function that calculate the combination
The formula for combinations is C(a, b) = (P(a, b)) / (b!)
4. Ask user whether they want to calculate permutations or combinations,
4a. if permutation then get two inputs and get print the result
4b. if combination then get two input and print the result

Also general error checking should be implemented for user inputs.
negative numbers should be rejected and an error message should be printed.
if b is greater than a then an error message should be printed and the program should terminate.
also datatype overflow should be checked for factorial function, 
if the number is too large then an error message should be printed and the program should terminate.
 
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

double factorial(double n){
    if(n<0){
        throw std::runtime_error("Factorial is not defined for negative numbers");
    }
    if(n>100){ // It might be a good idea to limit the input to avoid overflow, as factorials grow very quickly.
        throw std::runtime_error("Number too large: factorial would overflow");
    }
    if(n==0 || n==1){
        return 1;
    }
    double result = 1;
    for(int i=2; i<=n; ++i){
        result *= i;
    }
    return result;
}


double permutation(double a, double b){
    if(b>a){
        throw std::runtime_error("b cannot be greater than a for permutations");
    }
    return factorial(a) / factorial(a-b);
}

double combination(double a, double b) {
	return permutation(a, b) / factorial(b);
}



int main() {
    try
    {
        std::cout<<"\t Welcome to Problem 8, to select the calculation for type\n"
        "[P] permutation\n"
        "[C] combination\n";
        char ch;
        double a{0},b{0};
        std::cin>>ch;
        switch (ch)
        {
        case 'p': case 'P':
            {
                std::cout<<"Enter value for a: ";
                std::cin>>a;
                std::cout<<"Enter value for b: ";
                std::cin>>b;
                double res = permutation(a, b);
                std::cout << "\npermutation = " << res << '\n';
                break;
            }
        case 'c': case 'C':
            {
                std::cout<<"Enter value for a: ";
                std::cin>>a;
                std::cout<<"Enter value for b: ";
                std::cin>>b;
                double res = combination(a, b);
                std::cout << "\ncombination = " << res << '\n';
                break;
            }
        default:
            std::cerr << "Invalid character!\n";
            break;
        }

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}


