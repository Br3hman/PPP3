/*
[9] Keep track of the sum of values entered 
(as well as the smallest and the largest) and the number of values entered. 
When the loop ends, print the smallest, the largest, the number of values, 
and the sum of values. Note that to keep the sum, you have to decide on a 
unit to use for that sum; use meters. 
[10] Keep all the values entered (converted into meters) in a vector. 
At the end, write out those values. 
[11] Before writing out the values from the vector, sort them (that’ll make 
them come out in increasing order).
 */
#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>
#include <string>
#include <vector>

int main()
{    
    std::string unit{""};
    std::vector<double> entries;
    

    double sum{0}, current{0}, smallest{std::numeric_limits<double>::max()}, largest{std::numeric_limits<double>::lowest()};
    std::cout << "Enter a number with a unit (cm, m, in, ft): (| to end):\n";
    while (std::cin >> current)
    {
        std::cin >> unit;
        if(unit == "cm"){
            current /= 100; // convert cm to m

        }else if(unit == "m"){
            // current is already in meters, no conversion needed
        }else if(unit == "in"){
            current *= 0.0254; // convert inches to meters
        }else if(unit == "ft"){
            current *= 0.3048; // convert feet to meters
        }else{
            std::cout << "Invalid unit. Please enter a number with a valid unit (cm, m, in, ft).\n";
            continue; // skip the rest of the loop and prompt for a new number
        }

        if (current < 0 ) {
            std::cout << "The distance shouldn't be negative value: " << current << "m\n";
            std::cout << "Invalid unit. Please enter a number with a valid unit (cm, m, in, ft).\n";
            continue; // skip the rest of the loop and prompt for a new number
        }

        if (current < smallest) {
            smallest = current;
        }

        if (current > largest) {
            largest = current;
        }

        std::cout << "So far, the smallest number is: " << smallest << "m\n";
        std::cout << "So far, the largest number is: " << largest << "m\n";
        entries.push_back(current);
        sum += current;
        std::cout << "Enter a number with a unit (cm, m, in, ft): (| to end):\n";
    }

    std::cout << "So far, the smallest number is: " << smallest << "m\n";
    std::cout << "So far, the largest number is: " << largest << "m\n";
    std::cout << "The sum of all numbers is: " << sum << "m\n";
    std::sort(entries.begin(), entries.end());
    std::cout << "The numbers in sorted order are: ";
    for (const auto& entry : entries) {
        std::cout << entry << "m, ";
    }
    return 0;
}
