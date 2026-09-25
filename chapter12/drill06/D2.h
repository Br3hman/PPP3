#ifndef D2_H
#define D2_H

#include <iostream>
#include "../drill05/D5.h"

class D2: public D5 {
    public:
        void f(){std::cout << "D2::f()\n";}
        void vf() const override{std::cout << "D2::vf()\n";}
        void pv() const override{std::cout << "D2::pv()\n";}
};

#endif // D2_H