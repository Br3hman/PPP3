/*
[2] Write a function print() that prints a vector of ints to cout.
Give it two arguments: a string for “labeling” the output and a vector.
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

int main(){
    std::vector<int> numbers{0,1,2,3,4,5,6,7};
    std::string label = "The numbers are:";
    print(label,numbers);
    return 0;
}