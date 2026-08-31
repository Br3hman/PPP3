/*
[5] Write two functions that reverse the order of elements in a vector<int>.
For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1.
The first reverse function should produce a new vector with the reversed sequence,
leaving its original vector unchanged.

The other reverse function should reverse the elements of its vector without
using any other vectors (hint: swap).
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

std::vector<int> reverse_copy(const std::vector<int>& vec){
    std::vector<int> reversed;
    for(int i = vec.size() - 1; i >= 0; --i){
        reversed.push_back(vec[i]);
    }
    return reversed;
}
// Reverses the elements of the vector in place without using any other vectors.
// First element is swapped with the last, the second with the second last, and so on.
// This continues until the middle of the vector is reached.
void reverse_in_place(std::vector<int>& vec){
    int n = vec.size();// Get the size of the vector
    for(int i = 0; i < n / 2; ++i){
        std::swap(vec[i], vec[n - i - 1]);
    }
}
int main(){
    std::vector<int> numbers;
    int x=1;
    int y=2;
    fibonacci(x, y, numbers, 11);
    std::string label = "The Fibonacci numbers are:";
    print(label,numbers);

    std::vector<int> reversed_numbers = reverse_copy(numbers);
    print("Reversed copy of the Fibonacci numbers:", reversed_numbers);

    reverse_in_place(numbers);
    print("Fibonacci numbers reversed in place:", numbers);
    return 0;
}