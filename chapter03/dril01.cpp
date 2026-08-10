/*
[1] Write a program that consists of a while-loop that 
(each time around the loop) reads in two ints and then prints them. 
Exit the program when a terminating '|' is entered. 
 */
#include <iostream>
int main()
{
    int x{0}, y{0};
    std::cout << "Enter two integers (| to end):\n";
    while (std::cin >> x >> y)
    {
        std::cout << "x: " << x << ", y: " << y << '\n';
    }
    return 0;
}