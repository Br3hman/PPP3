#include "../drill02/D1.h"

int main() {
    D1 d1;
    d1.f();
    d1.vf();

    B1& b1_ref = d1;
    b1_ref.f();
    b1_ref.vf();
}