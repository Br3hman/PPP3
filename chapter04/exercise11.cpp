/*
[11] Write a program that writes out the first N values of the Fibonacci series, 
that is, the series that starts with 1 1 2 3 5 8 13 21 34. 
The next number of the series is the sum of the two previous ones. 
Find the largest Fibonacci number that fits in an int.

*/
#include <iostream>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <cstdint>
//#include <cmath>
#include <limits>



int main(){
    int N{0};
    std::vector<int> integers;
    std::cout<<"Enter a number to which you want Fibonaci numbers:";
    std::cin>>N;
    if (N<2)
    {
        std::cerr<<"Number "<<N<<" is too small select a numeber greater than 3";
        return 1;
    }

    int sum{1};
    integers.push_back(sum);
    integers.push_back(1);
    int max = std::numeric_limits<int>::max();

    for (int i = 1; i < N-1; i++)
    {
        int a = integers[i];
        int b = integers[i-1];
        if (b > max-std::abs(a))
        {
            std::cerr<<"Sum of all number is too big so far I have as following:"<<std::endl;
            for(const int& num:integers){
                std::cout<<num<<", ";
            }
    
            return 1;
        }
        sum = a + b;

        
        integers.push_back(sum);
    }

    for(const int& num:integers){
        std::cout<<num<<", ";
    }
    

    

    return 0; // Exit without error
}

    
