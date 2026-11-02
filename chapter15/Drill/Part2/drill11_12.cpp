/*
[10] Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to p1.
[11] Allocate an array of ten ints, and assign its address to a variable p2.
[12] Copy the values from the array pointed to by p1 into the array pointed to by p2.
*/
#include<iostream>
std::ostream&  print_array(std::ostream& os, int* a, int n){
    for(int i = 0; i < n; i++){
        if(i>0)
            os<<",";
        os<<a[i];
    }
    os<<std::endl;
    return os;
}
int main(){
    int* p1 = new int[10]{1,2,4,8,16,32,64,128,256,512};
    int* p2 = new int[10];
    print_array(std::cout,p1,10);
    print_array(std::cout,p2,10);
    p2=p1;
    std::cout<<"Assigned p1 to p2"<<std::endl;
    print_array(std::cout,p2,10);
    delete[] p1;
    delete[] p2;
}