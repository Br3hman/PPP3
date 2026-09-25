#ifndef D21_H
#define D21_H

#include <iostream>
#include <string>
#include "B2.h"

class D21: public B2 {
    public:
        void pvf() const override{std::cout << name << std::endl;}
    private:
        std::string name="My Name is D21";

};

#endif // D21_H