#include "D2.h"

int main() {
    // B5 is an abstract class and cannot be instantiated
    // B5 b5;
    // b5.f();
    // b5.vf();

    // D2 can be instantiated and used
    D2 d2;
    d2.f();
    d2.vf();
    d2.pv();

    // Using a reference to the base class B5 to access the derived class D2
    B5& b5_ref = d2;
    b5_ref.f();
    b5_ref.vf();
    b5_ref.pv();

    return 0;
}