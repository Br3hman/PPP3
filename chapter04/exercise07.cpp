/*
Quadratic equations are of the form a*x2 + b*x + c = 0. 
To solve these, one uses the quadratic formula: 
There is a problem, though: if b2- 4ac is less than zero, 
then it will fail. 

Write a program that can calculate x for a quadratic equation. 
Create a function that prints out the roots of a quadratic equation, 
given a, b, c. When the program detects an equation with no real roots, 
have it print out a message. 

How do you know that your results are plausible? 
Can you check that they are correct?

*/
#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cstdint>
#include <cmath>

std::pair<double, double> calculate_roots(double a, double b, double c){
    // Function to calculate the roots of a quadratic equation
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        // No real roots
        std::cerr << "The equation has no real roots." << std::endl;
        throw std::runtime_error("No real roots");
    }
    double sqrt_discriminant = std::sqrt(discriminant);
    double root1 = (-b + sqrt_discriminant) / (2 * a);
    double root2 = (-b - sqrt_discriminant) / (2 * a);
    return { root1, root2 };
}

void test_calculate_valid_roots(){
    // a=1, b=-5, c=6 => 3 and 2
    // a=1, b=-3, c=2 => 2 and 1
    auto [root1, root2] = calculate_roots(1, -5, 6);
    if(root1 != 3.0 || root2 != 2.0){
        std::cerr << "Test case failed: a=1, b=-5, c=6 => expected roots: 3 and 2, got: " << root1 << " and " << root2 << std::endl;
    }
    else{
        std::cout << "Test case passed: a=1, b=-5, c=6 => roots: " << root1 << " and " << root2 << std::endl;
    }
    auto [root3, root4] = calculate_roots(1, -3, 2);
    if(root3 != 2.0 || root4 != 1.0){
        std::cerr << "Test case failed: a=1, b=-3, c=2 => expected roots: 2 and 1, got: " << root3 << " and " << root4 << std::endl;
    }
    else{
        std::cout << "Test case passed: a=1, b=-3, c=2 => roots: " << root3 << " and " << root4 << std::endl;
    }
}

void test_calculate_no_real_roots(){
    // a=1, b=2, c=5 => expects a throw, no real roots
    calculate_roots(1, 2, 5); //since this should throw, we don't need to check or assign the return value
}



int main(){

    try{
        test_calculate_valid_roots();
        test_calculate_no_real_roots();
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; // Exit with error
    }


    return 0; // Exit without error
}

    
