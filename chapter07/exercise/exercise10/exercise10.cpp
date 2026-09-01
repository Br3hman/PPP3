/*
exercise 10
[10] Write a function maxv() that returns the largest element of a vector argument.
maxv is renamed to max_value
*/

#include <iostream>
//#include <sstream>
#include <stdexcept>
//#include <fstream>
//#include <string>
#include <vector>
#include <algorithm>
////#include <map>
//#include <cmath>
//#include <climits>
//#include <limits>

template<typename T1, typename T2>
double compute_value(const std::vector<T1>& vec1,const std::vector<T2>& vec2){
    if(vec1.size()!=vec2.size())
        throw std::runtime_error("Both Vector should have same size");
    double sum{};
    for(auto i=0;i<vec1.size(); i++)
        sum += vec1[i]*vec2[i];

    return sum;
}

template<typename T1, typename T2>
void print_pairs(const std::vector<T1>& vec1, const std::vector<T2>& vec2){
    for(size_t i=0;i<vec1.size() && i<vec2.size();i++){
        std::cout<<"("<<vec1[i]<<","<<vec2[i]<<")"<<std::endl;
    }
}

template<typename T>
T max_value(const std::vector<T>& vec){ // cannot sort a const vector, use std::max_element instead
    if (vec.empty())
        throw std::runtime_error("Vector is empty");

    // use std::max_element to find the largest element,
    // '*' is used to dereference the iterator to get the value
    return *std::max_element(vec.begin(), vec.end());
}

int main(){
    std::vector<double> price{20,40,30,10,5,1};
    std::vector<double> weight{4,5,6,7,8,9};
    std::cout<<"Total Values of following items\n";
    print_pairs(price,weight);
    std::cout<<"Total="<< compute_value(price,weight)<<std::endl;
    std::cout<<"Max price="<< max_value(price)<<std::endl;
    std::cout<<"Max weight="<< max_value(weight)<<std::endl;

    return 0;
}