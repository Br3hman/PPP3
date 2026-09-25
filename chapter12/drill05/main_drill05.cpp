#include "D5.h"

int main() {
    // B5 is an abstract class and cannot be instantiated
    // B5 b5;
    // b5.f();
    // b5.vf();

    // D5 can be instantiated and used
    D5 d5;
    d5.f();
    d5.vf();
    d5.pv();

    // Using a reference to the base class B5 to access the derived class D5
    B5& b5_ref = d5;
    b5_ref.f();
    b5_ref.vf();
    b5_ref.pv();

    return 0;
}