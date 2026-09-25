#ifndef B5_H
#define B5_H

#include <iostream>

class B5 {
    public:
        void f(){std::cout << "B5::f()\n";}
        virtual void vf() const {std::cout << "B5::vf()\n";}
        virtual void pv() const  = 0;
};

#endif // B5_H