/*

*/
#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cstdint>
//#include <cmath>

double ctok(double celsius){
    double kelvin = celsius + 273.15;
    if(kelvin < 0){
        std::cerr << "Error: Temperature in Kelvin cannot be negative." << std::endl;
        exit(1); // Exit with error
    }
    return (celsius + 273.15);
}

double ktoc(double kelvin){
    if(kelvin < 0){
        std::cerr << "Error: Temperature in Kelvin cannot be negative." << std::endl;
        exit(1); // Exit with error
    }

    return kelvin-273.15;

}

int main(){
    double celsius;
    std::cout << "Enter temperature in Celsius: "; 
    std::cin >> celsius; // Get user input
    double kelvin = ctok(celsius);
    std::cout << "Temperature in Kelvin: " << kelvin << std::endl;
    double kelvin_input;
    std::cout << "Enter temperature in Kelvin: ";
    std::cin >> kelvin_input; // Get user input
    double celsius_converted = ktoc(kelvin_input);
    std::cout << "Converted back to Celsius: " << celsius_converted << std::endl;
    return 0; // Exit without error
}

    
