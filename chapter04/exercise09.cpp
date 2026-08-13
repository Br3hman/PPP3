/*
[9] Modify the program from the previous exercise to write out an error if the result 
cannot be represented as an int.
*/
#include <iostream>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <cstdint>
//#include <cmath>
#include <limits>



int main(){
    int n_inegers{0};
    std::vector<int> integers;
    std::cout << "Please enter the number of values you want to sum:" << std::endl;
    std::cin >> n_inegers;
    std::cout << "Please enter some integers (press '|' to stop):" << std::endl;
    long long input;
    while(std::cin >> input){
        if(input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min()){
            std::cerr << input << " is out of int range ["
                      << std::numeric_limits<int>::min() << ", "
                      << std::numeric_limits<int>::max() << "], try again: ";
            continue;
        }
        integers.push_back(static_cast<int>(input));
    }

    if(static_cast<size_t>(n_inegers) > integers.size()){ //'std::vector<int>::size_type' {aka 'long long unsigned int'}
        std::cerr << "Error: You requested to sum " << n_inegers << " integers, but only " << integers.size() << " were provided." << std::endl;
        return 1; // Exit with error
    }else
    {
        int sum{0};
        for(int i = 0; i < n_inegers; ++i){
            sum += integers[i];
            if(sum > std::numeric_limits<int>::max() || sum < std::numeric_limits<int>::min()){
                std::cerr << "Error: Integer overflow occurred while summing the integers." << std::endl;
                return 1; // Exit with error
            }
        }
        std::cout << "The sum of the first " << n_inegers << " integers is: " << sum << std::endl;
    }



    return 0; // Exit without error
}

    
