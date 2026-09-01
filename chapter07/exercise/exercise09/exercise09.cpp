/*
[9] Write a function that given two vector<double>s price and weight
computes a value (an “index”) that is the sum of all price[i]*weight[i].
Make sure to have weight.size()==price.size().
*/

#include <iostream>
//#include <sstream>
#include <stdexcept>
//#include <fstream>
//#include <string>
#include <vector>
//#include <algorithm>
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
        sum += vec1[i]*vec2[2];

    return sum;
}

template<typename T1, typename T2>
void print_pairs(const std::vector<T1>& vec1, const std::vector<T2>& vec2){
    for(size_t i=0;i<vec1.size() && i<vec2.size();i++){
        std::cout<<"("<<vec1[i]<<","<<vec2[i]<<")"<<std::endl;
    }
}

int main(){
    std::vector<double> price{20,40,30,10,5,1};
    std::vector<double> weight{4,5,6,7,8,9};
    std::cout<<"Total Values of following items\n";
    print_pairs(price,weight);
    std::cout<<"Total="<< compute_value(price,weight);

    return 0;
}