/*
[3] Create a vector of Fibonacci numbers and print them using the function from exercise 2.
To create the vector, write a function, fibonacci(x,y,v,n), where integers x and y are ints,
v is an empty vector<int>, and n is the number of elements to put into v;
v[0] will be x and v[1] will be y. A Fibonacci number is one that is part of a sequence where
each element is the sum of the two previous ones. For example, starting with 1 and 2,
we get 1, 2, 3, 5, 8, 13, 21, ... . Your fibonacci() function should make such a sequence
starting with its x and y arguments.
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

void print(const std::string& label, const std::vector<int>& vec){
    std::cout<<label<<std::endl;
    for(auto v:vec){
        std::cout<<v<<" ";
    }
    std::cout<<"\n";
}

void fibonacci(int first, int second, std::vector<int>& vec, int n){
    if(n <= 0) return;
    vec.push_back(first);
    if(n == 1) return;
    vec.push_back(second);
    for(int i = 0; i < n-1; ++i){
        //std::cout << "i: "<< i << " i+1: " << i+1 << std::endl;
        int next = vec[i] + vec[i+1];
        vec.push_back(next);
    }
}

int main(){
    std::vector<int> numbers;
    int x=1;
    int y=2;
    fibonacci(x, y, numbers, 10);
    std::string label = "The Fibonacci numbers are:";
    print(label,numbers);
    return 0;
}