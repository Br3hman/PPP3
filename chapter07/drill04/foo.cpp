#include "foo.h"
#include <iostream>

int foo;

void print_foo() {
    std::cout << "foo = " << foo << "\n";
}

void print(int x) {
    std::cout << "x = " << x << "\n";
}