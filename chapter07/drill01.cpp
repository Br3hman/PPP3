/*
[1] Write three functions swap_v(int,int), swap_r(int&,int&), and swap_cr(const int&, const int&).
Each should have the body Click here to view code image { int temp; temp = a, a=b; b=temp; }
where a and b are the names of the arguments. Try calling each swap like this Click here to view code image int x = 7;
int y = 9;
swap_?(x,y);             // replace ? by v, r, or cr
swap_?(7,9);
const int cx = 7;
const int cy = 9;
swap_?(cx,cy);
swap_?(7.7,9.9);
double dx = 7.7;
double dy = 9.9;
swap_?(dx,dy);
swap_?(7.7,9.9);
Which functions and calls compiled, and why? After each swap that compiled,
print the value of the arguments after the call to see if they were actually swapped.
If you are surprised by a result, consult §7.5.
*/
#include <iostream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//#include <cstddef>   // for std::size_t
//#include <algorithm>
//#include <map>
//#include<cmath>

void swap_v(int a, int b){
    std::cout << "Inside swap_v (before swap): a = " << a << ", b = " << b << "\n";
    int temp = a;
    a = b;
    b = temp;
    std::cout << "Inside swap_v: a = " << a << ", b = " << b << "\n";
}
void swap_r(int& a, int& b){
    std::cout << "Inside swap_r (before swap): a = " << a << ", b = " << b << "\n";
    int temp = a;
    a = b;
    b = temp;
    std::cout << "Inside swap_r: a = " << a << ", b = " << b << "\n";
}
void swap_cr(const int& a, const int& b){
    // cannot swap const references
    std::cerr << "Cannot swap const references\n";
    return;
}

int main() {
    int x = 7;
    int y = 9;
    swap_v(x, y);
    std::cout << "After swap_v: x = " << x << ", y = " << y << "\n";
    swap_r(x, y);
    std::cout << "After swap_r: x = " << x << ", y = " << y << "\n";
    swap_cr(x, y);
    std::cout << "After swap_cr: x = " << x << ", y = " << y << "\n";

    swap_v(7, 9);
   // swap_r(7, 9); // error: cannot bind non-const lvalue reference to an rvalue
    swap_cr(7,9);
    std::cout << "After swap_cr: x = " << x << ", y = " << y << "\n";

    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy);
    std::cout << "After swap_v with const ints: cx = " << cx << ", cy = " << cy << "\n";
    // swap_r(cx, cy); // error: cannot bind non-const lvalue reference to a const int
    swap_cr(cx, cy);
    std::cout << "After swap_cr with const ints: cx = " << cx << ", cy = " << cy << "\n";

    double dx = 7.7;
    double dy = 9.9;
    // swap_v(dx, dy); // error: no matching function for call to 'swap_v' int version only exists
    // swap_r(dx, dy); // error: no matching function for call to 'swap_r' int version only exists
    // swap_cr(dx, dy); // error: no matching function for call to 'swap_cr' int version only exists
    return 0;
}