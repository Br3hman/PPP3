/*
[6] Now change the body of the loop so that it reads just 
one double each time around. Define two variables to keep 
track of which is the smallest and which is the largest 
value you have seen so far. Each time through the loop write out 
the value entered. If it’s the smallest so far, write the smallest 
so far after the number. If it is the largest so far, write 
the largest so far after the number. 
[7] Add a unit to each double entered; that is, enter values such as 
10cm, 2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft. 
Assume conversion factors 1m==100cm, 1in==2.54cm, 1ft==12in. Read 
the unit indicator into a string. You may consider 12 m (with a space 
between the number and the unit) equivalent to 12m (without a space). 
[8] Reject values without units or with “illegal” representations of 
units, such as y, yard, meter, km, and gallons.
 */
#include <iostream>
#include <cmath>
#include <limits>
#include <string>

int main()
{    
    std::string unit{""};
    double current{0}, smallest{std::numeric_limits<double>::max()}, largest{std::numeric_limits<double>::lowest()};
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
        std::cout << "Enter a number with a unit (cm, m, in, ft): (| to end):\n";

    }
    return 0;
}
