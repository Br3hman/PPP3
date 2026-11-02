/*
[2] Print the values of the ten intsto cout.
[3] Deallocate the array (using delete[]).
*/
#include<iostream>

std::ostream&  print_array(std::ostream& os, int* a, int n){
    for(int i = 0; i < n; i++){
        if(i>0)
            os<<",";
        os<<a[i];
    }
    return os;
}

int main() {
    constexpr int size_p= 10;
    int* p = new int[size_p];//Garbage values
    print_array(std::cout,p,size_p)<<std::endl;
    delete[] p; //Deallocate the array (using delete[]).
    return 0;
}