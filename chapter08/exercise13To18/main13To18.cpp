#include "common13To18/Money.h"
using namespace PPP_Calc;
int main(){
    Money m1{10.45, Currency::USD};
    Money m2{5.0, Currency::EUR};
    Money m3 = m1 + m2;
    std::cout << "m1: " << m1 << "\n";
    std::cout << "m2: " << m2 << "\n";
    std::cout << "m3: " << m3 << "\n";
    return 0;
}