/*

*/
#include <iostream>
//#include <stdexcept>
//#include <string>
//#include <vector>
//#include <cstddef>   // for std::size_t
//#include <algorithm>
//#include <map>
//#include<cmath>

namespace X{
    int var;
    void print_var() {
        std::cout << "X::var = " << var << "\n";
    }
}


namespace Y{
    int var;
    void print_var() {
        std::cout << "Y::var = " << var << "\n";
    }
}

namespace Z{
    int var;
    void print_var() {
        std::cout << "Z::var = " << var << "\n";
    }
}


int main() {
    X::var = 7;
    X::print_var();     //print X's var
    using namespace Y;
    var = 9;
    print_var();        //print Y's var
    {
        using Z::var;
        using Z::print_var;
        var=11;
        print_var();    //print Z's var
    }
    print_var();        //print Y's var
    X::print_var();

    return 0;
}