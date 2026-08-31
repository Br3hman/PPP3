/*
[4] An int can hold integers only up to a maximum number. Find an approximation of that maximum number by using fibonacci().
*/

#include <iostream>
//#include <sstream>
//#include <stdexcept>
//#include <fstream>
#include <string>
#include <vector>
//#include <algorithm>
////#include <map>
//#include <cmath>
//#include <climits>
#include <limits>

void print(const std::string& label, const std::vector<int>& vec){
    std::cout<<label<<" Total numbers of element:"<< vec.size() <<std::endl;
    for(auto v:vec){
        std::cout<<v<<" ";
    }
    std::cout<<"\n";
}

void fibonacci(int first, int second, std::vector<int>& vec, int n){
    int max = std::numeric_limits<int>::max();
    if(n <= 0) return;
    vec.push_back(first);
    if(n == 1) return;
    vec.push_back(second);
    for(int i = 1; i < n-1; ++i){
        //std::cout << "i: "<< i << " i+1: " << i+1 << std::endl;
        int a = vec[i];
        int b = vec[i-1];
        if (b > max-std::abs(a)) break;
        vec.push_back(a + b);
    }
}

int main(){
    std::vector<int> numbers;
    int x=1;
    int y=2;
    fibonacci(x, y, numbers, 1000);
    std::string label = "The Fibonacci numbers are:";
    print(label,numbers);
    return 0;
}