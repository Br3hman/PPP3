/*
[2] Print the values of the ten intsto cout.
[3] Deallocate the array (using delete[]).
*/
#include<iostream>
int main() {
    constexpr int size_p= 10;
    int* p = new int[size_p];//Garbage values
    for (int i = 0; i < size_p; i++)
    {
        if(i>0)
            std::cout<<",";
        std::cout<<p[0];//printing the garbage values as no init value is given
    }
    delete[] p; //Deallocate the array (using delete[]).
    return 0;
}