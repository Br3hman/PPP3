#ifndef D1_H
#define D1_H

#include <iostream>
#include "../drill01/B1.h"

class D1: public B1 {
    public:
        void f(){std::cout << "D1::f()\n";}
        void vf() const override{std::cout << "D1::vf()\n";}
};

#endif // D1_H