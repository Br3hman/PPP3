/*
[1] Write a program that consists of a while-loop that 
(each time around the loop) reads in two ints and then prints them. 
Exit the program when a terminating '|' is entered. 
[2] Change the program to write out the smaller value is: 
followed by the smaller of the numbers and the larger value is: 
followed by the larger value.
[3] Augment the program so that it writes the line the numbers are equal 
(only) if they are equal.
[4] Change the program so that it uses doubles instead of ints. 
[5] Change the program so that it writes out the numbers are a
lmost equal after writing out which is the larger and the smaller 
if the two numbers differ by less than 1.0/100.
 */
#include <iostream>
#include <cmath>
int main()
{
    double x{0}, y{0};
    std::cout << "Enter two numbers (| to end):\n";
    while (std::cin >> x >> y)
    {
        if(std::abs(x-y)>1.0/100) {
            if(x<y) {
                 std::cout << "x: " << x << ", y: " << y << '\n';
            } else {
                std::cout << "y: " << y << ", x: " << x << '\n';
            }
        } else {
            std::cout << "The values are almost equal.\n";    
            std::cout << "x: " << x << ", y: " << y << '\n';
        }
    }
    return 0;
}