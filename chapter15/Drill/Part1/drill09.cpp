/*
[9] Do 5, 6, and 7 using a vector instead of an array and a print_vector() instead of print_array().
*/
#include<iostream>
#include<vector>


void printVector(std::vector<int>& vec){
    for(int ele:vec)
        std::cout<<ele<<", ";
}

std::vector<int> make_vector(int n) {
    std::vector<int> vec(n);

    for (int i = 0; i < n; ++i)
        vec[i] = 100 + i;
    printVector(vec);
    std::cout<<std::endl;
    return vec;
}

int main() {
    //Drill 05
    std::vector<int> drill05 = make_vector(10);
    //Drill 06
    std::vector<int> drill06 = make_vector(11);
    //Drill 07
    std::vector<int> drill07 = make_vector(20);

    return 0;
}