/*
[10] Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to p1.
[11] Allocate an array of ten ints, and assign its address to a variable p2.
[12] Copy the values from the array pointed to by p1 into the array pointed to by p2.
[13] Repeat 10–12 using a vector rather than an array.
*/
#include<iostream>
#include<vector>

void printVector(std::vector<int>& vec){
    for(int ele:vec)
        std::cout<<ele<<", ";
}

std::vector<int> make_vector(int n) {
    std::vector<int> vec(n);
    int value = 1;
    for (int i = 0; i < n; ++i){
        vec[i] = value;
        value *= 2;
    }
    printVector(vec);
    std::cout<<std::endl;
    return vec;
}

int main(){
    std::vector<int> vec = make_vector(10);
    std::vector<int> vec2 = vec;
    printVector(vec2);
    std::cout<<std::endl;
}