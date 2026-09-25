#ifndef B2_H
#define B2_H

#include <iostream>

class B2 {
    public:
          virtual void pvf() const  = 0;
};

void f(const B2& b2_ref) {
    b2_ref.pvf();
}
#endif // B2_H