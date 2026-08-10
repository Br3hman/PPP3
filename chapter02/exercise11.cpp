/*
[11] Write a program that prompts the user to enter some number of pennies 
(1-cent coins), nickels (5-cent coins), dimes (10-cent coins), 
quarters (25-cent coins), half dollars (50-cent coins), and 
one-dollar coins (100-cent coins). 

Query the user separately for the number of each size coin, 
e.g., “How many pennies do you have?” 

Then your program should print out something like this: 
You have 23 pennies.
You have 17 nickels.
You have 14 dimes.
You have 7 quarters.
You have 3 half dollars.
The value of all of your coins is 573 cents.

Make some improvements: if only one of a coin is reported, 
make the output grammatically correct, e.g., 14 dimes and 1 dime (not 1 dimes). 
Also, report the sum in dollars and cents, i.e., .73 instead of 573 cents.
*/
#include <iostream>
#include <string>
int main(){
    double pennies, nickels, dimes, quarters, half_dollars, one_dollars;
    std::cout << "How many pennies do you have? ";
    std::cin >> pennies;
    std::cout << "How many nickels do you have? ";
    std::cin >> nickels;
    std::cout << "How many dimes do you have? ";
    std::cin >> dimes;
    std::cout << "How many quarters do you have? ";
    std::cin >> quarters;
    std::cout << "How many half dollars do you have? ";
    std::cin >> half_dollars;
    std::cout << "How many one-dollar coins do you have? ";
    std::cin >> one_dollars;

    std::cout << "You have " << pennies << " " << ((pennies == 0 || pennies == 1) ? "penny" : "pennies") << ".\n";
    std::cout << "You have " << nickels << " nickel" << ((nickels == 0 || nickels == 1) ? "" : "s") << ".\n";
    std::cout << "You have " << dimes << " dime" << ((dimes == 0 || dimes == 1) ? "" : "s") << ".\n";
    std::cout << "You have " << quarters << " quarter" << ((quarters == 0 || quarters == 1) ? "" : "s") << ".\n";
    std::cout << "You have " << half_dollars << " half dollar" << ((half_dollars == 0 || half_dollars == 1) ? "" : "s") << ".\n";
    std::cout << "You have " << one_dollars << " one-dollar coin" << ((one_dollars == 0 || one_dollars == 1) ? "" : "s") << ".\n";
    
    double total_cents = pennies + 5 * nickels + 10 * dimes + 25 * quarters + 50 * half_dollars + 100 * one_dollars;
    
    
    if (total_cents <= 0) 
        std::cout << "The value of all of your coins is 0$ \n";
    else
        std::cout << "The value of all of your coins is " << static_cast<int>(total_cents) / 100 << "$ and " << static_cast<int>(total_cents) % 100 << " cents.\n";

    return 0;
}