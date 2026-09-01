/*
exercise 11
[11] Write a function that finds the smallest and the largest element of a vector argument
and also computes the mean and the median.

Do not use global variables.
Either return a struct containing the results or pass them back through reference arguments.

Which of the two ways of returning several result values do you prefer and why?
I prefer the struct as result because its much cleaner solution,
*/

#include <iostream>
//#include <sstream>
#include <stdexcept>
//#include <fstream>
//#include <string>
#include <vector>
#include <algorithm>
#include <numeric> //for accumulate
////#include <map>
//#include <cmath>
//#include <climits>
//#include <limits>


struct Stats
{
    double min{}, max{}, mean{}, median{};
    void print() const {
        std::cout << "min=" << min << " max=" << max
                  << " mean=" << mean << " median=" << median << "\n";
    }
};



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

Stats analyze(const std::vector<double>& v){ // pass by const ref — no copy at call site
    if (v.empty())
        throw std::runtime_error("Vector is empty");

    std::vector<double> sorted = v;         // copy only when needed, inside the function
    std::sort(sorted.begin(), sorted.end());
    Stats result;
    result.min= *std::min_element(sorted.begin(),sorted.end());
    result.max= *std::max_element(sorted.begin(),sorted.end());
    result.mean=std::accumulate(sorted.begin(),sorted.end(),0.0)/sorted.size();
    size_t n = sorted.size();
    if (n % 2 == 1) //size is a odd number
        result.median = sorted[n/2];
    else
        result.median= (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;

    return result;



}

int main(){
    try
    {
        std::vector<double> price{20,40,30,10,5,1};
        std::vector<double> weight{4,5,6,7,8,9};
        std::cout<<"Total Values of following items\n";
        print_pairs(price,weight);
        std::cout<<"Total="<< compute_value(price,weight)<<std::endl;
        std::cout<<"Max price="<< max_value(price)<<std::endl;
        std::cout<<"Max weight="<< max_value(weight)<<std::endl;
        Stats sp=analyze(price);
        Stats sw=analyze(weight);
        sp.print();
        sw.print();

    return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


}