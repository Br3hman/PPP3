/*
[6] Write versions of the functions from exercise 5, but with a vector<string>.
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

template<typename T> //to avoid using int-specific functions or std::string specific functions
void print(const std::string& label, const std::vector<T>& vec){
    std::cout<<label<<std::endl;
    for(auto v:vec){
        std::cout<<v<<" ";
    }
    std::cout<<"\n";
}


template<typename T>//to avoid using int-specific functions or std::string specific functions
std::vector<T> reverse_copy(const std::vector<T>& vec){
    std::vector<T> reversed;
    for(int i = vec.size() - 1; i >= 0; --i){
        reversed.push_back(vec[i]);
    }
    return reversed;
}
// Reverses the elements of the vector in place without using any other vectors.
// First element is swapped with the last, the second with the second last, and so on.
// This continues until the middle of the vector is reached.
template<typename T>//to avoid using int-specific functions or std::string specific functions
void reverse_in_place(std::vector<T>& vec){
    int n = vec.size();// Get the size of the vector
    for(int i = 0; i < n / 2; ++i){
        std::swap(vec[i], vec[n - i - 1]);
    }
}
int main(){
    std::vector<std::string> names{"Alice", "Bob", "Charlie", "Diana"};
    int x=1;
    int y=2;

    std::string label = "The names are:";
    print(label,names);

    std::vector<std::string> reversed_names = reverse_copy(names);
    print("Reversed copy of the names:", reversed_names);

    reverse_in_place(names);
    print("Names reversed in place:", names);
    return 0;
}