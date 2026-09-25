#ifndef B1_H
#define B1_H

#include <iostream>
class B1 {
    public:
        void f(){std::cout << "B1::f()\n";}
        virtual void vf() const {std::cout << "B1::vf()\n";}
};




#endif // B1_H