#ifndef D22_H
#define D22_H

#include <iostream>

#include "B2.h"

class D22: public B2 {
    public:
        void pvf() const override{std::cout<< "D22::pvf() value=" << value << std::endl;}
    private:
        int value=22;
};

#endif // D22_H