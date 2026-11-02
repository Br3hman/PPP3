/*
[10] Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to p1.
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
int main(){
    int* p1 = new int[10]{1,2,4,8,16,32,64,128,256,512};
    print_array(std::cout,p1,10);
    delete[] p1;
}