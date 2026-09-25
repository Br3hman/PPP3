#ifndef D5_H
#define D5_H

#include <iostream>
#include "B5.h"

class D5: public B5 {
    public:
        void f(){std::cout << "D5::f()\n";}
        void vf() const override{std::cout << "D5::vf()\n";}
        void pv() const override{std::cout << "D5::pv()\n";}
};

#endif // D5_H