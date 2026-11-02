/** Drill 01
 * [1] Allocate an int, initialize it to 7, and assign its address to a variable p1.
 * [2] Print out the value of p1 and of the int it points to.
 */
#include<iostream>
 int main() {
    int* p1 = new int(7);
    std::cout<<"Value of p1:"<<*p1<<std::endl;
    return 0;
 }
