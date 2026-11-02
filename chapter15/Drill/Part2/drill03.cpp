/** Drill 01
 * [1] Allocate an int, initialize it to 7, and assign its address to a variable p1.
 * [2] Print out the value of p1 and of the int it points to.
 * [3] Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
 */
#include<iostream>
 int main() {
    int* p1 = new int(7);
    int* p2 = new int[1,2,3,4,5,6,7];
    std::cout<<"Value of p1:"<<*p1<<std::endl;
    return 0;
 }
