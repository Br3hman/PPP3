/*
Write a program that reads and stores a series of integers and then 
computes the sum of the first N integers. First ask for N, then read 
the values into a vector, then calculate the sum of the first N values. 

For example: Please enter the number of values you want to sum: 3 
Please enter some integers (press ’|’ to stop): 12 23 13 24 15 | 
The sum of the first 3 numbers ( 12 23 13 )is 48 Handle all inputs. 

For example, make sure to give an error message if the user asks for 
a sum of more numbers than there are in the vector.

*/
#include <iostream>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <cstdint>
//#include <cmath>



int main(){
    int n_inegers{0};
    std::vector<int> integers;
    std::cout << "Please enter the number of values you want to sum:" << std::endl;
    std::cin >> n_inegers;
    std::cout << "Please enter some integers (press '|' to stop):" << std::endl;
    int input;
    while(std::cin >> input){
        integers.push_back(input);
    }

    if(static_cast<size_t>(n_inegers) > integers.size()-1){ //'std::vector<int>::size_type' {aka 'long long unsigned int'}
        std::cerr << "Error: You requested to sum " << n_inegers << " integers, but only " << integers.size() << " were provided." << std::endl;
        return 1; // Exit with error
    }else
{
        int sum{0};
        for(int i = 0; i < n_inegers; ++i){
            sum += integers[i];
        }
        std::cout << "The sum of the first " << n_inegers << " integers is: " << sum << std::endl;
    }



    return 0; // Exit without error
}

    
