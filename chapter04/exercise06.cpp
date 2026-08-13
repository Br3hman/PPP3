/*
[6] Write a program that converts from Celsius to Fahrenheit and from 
Fahrenheit to Celsius. Use estimation (§4.7.1) to see if your results are plausible.
*/
#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cstdint>
#include <cmath>

// (0°C × 9/5) + 32 = 32°F

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main(){
    std::cout << "Enter temperature in Celsius: ";
    double celsius;
    std::cin >> celsius;
    double fahrenheit = celsius_to_fahrenheit(celsius);
    std::cout << celsius << "°C is " << fahrenheit << "°F" << std::endl;
    if(std::abs(celsius - fahrenheit_to_celsius(fahrenheit)) < 1e-6) {
        std::cout << "Conversion is consistent, result is plausible." << std::endl;
    } else {
        std::cout << "Conversion is inconsistent." << std::endl;
    }
    return 0; // Exit without error
}

    
