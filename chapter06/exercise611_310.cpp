/*
[10] Try to calculate the number of rice grains that the inventor asked for 
in exercise 9 above. You'll find that the number is so large that it won't 
fit in an int or a double. Observe what happens when the number gets too 
large to represent exactly as an int and as a double. 
What is the largest number of squares for which you can calculate the 
exact number of grains (using an int)? What is the largest number of 
squares for which you can calculate the approximate number of grains (using a double)?
*/
#include <iostream>
#include <cstdint>
#include <cmath>

// Chessboard has 64 squares; grains double each square starting from 1
constexpr int total_squares = 64;
constexpr int int32_max_squares = 31; // 2^31-1 overflows for square 32
constexpr int double_max_squares = 64; // double can approximate all 64 squares

void print_table()
{
    double grains_on_square = 1.0;
    double total_grains = 1.0;

    std::cout << "Square | Grains on square       | Total grains\n";
    std::cout << "-------+------------------------+----------------------------\n";
    for (int i = 1; i <= total_squares; ++i) {
        if (i > 1) {
            grains_on_square *= 2.0;
            total_grains += grains_on_square;
        }
        std::cout << i << "\t" << grains_on_square << "\t\t" << total_grains << '\n';
    }
}

void print_limits()
{
    // 32-bit signed int overflows at 2^31; last exact square is 31
    std::cout << "Largest square with exact count using int32_t: " << int32_max_squares << '\n';
    // double has 53-bit mantissa; all 64 doublings are representable (though not exact integers)
    std::cout << "Largest square with approximate count using double: " << double_max_squares << '\n';
}

int main()
{
    print_table();
    print_limits();
    return 0;
}