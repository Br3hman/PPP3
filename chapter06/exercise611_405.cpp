/*
[chapter04 exercise05] Write a function ctok() that converts Celsius to Kelvin
and a function ktoc() that converts Kelvin to Celsius. Both should reject
physically impossible input (negative Kelvin).
*/
#include <iostream>
#include <stdexcept>

constexpr double absolute_zero_offset = 273.15; // Kelvin = Celsius + this

double ctok(double celsius)
{
    double kelvin = celsius + absolute_zero_offset;
    if (kelvin < 0)
        throw std::runtime_error("ctok: result is below absolute zero");
    return kelvin;
}

double ktoc(double kelvin)
{
    if (kelvin < 0)
        throw std::runtime_error("ktoc: Kelvin temperature cannot be negative");
    return kelvin - absolute_zero_offset;
}

int main()
try {
    double c;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> c;
    std::cout << "Temperature in Kelvin: " << ctok(c) << '\n';

    double k;
    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> k;
    std::cout << "Converted back to Celsius: " << ktoc(k) << '\n';

    return 0;
}
catch (std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
    return 1;
}