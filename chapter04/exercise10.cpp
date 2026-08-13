/*
[10] Modify the program from the previous exercise to use double instead of int. 
Also, make a vector of doubles containing the N-1 differences between adjacent values 
and write out that vector of differences.
*/
#include <iostream>
//#include <string>
#include <vector>
//#include <algorithm>
//#include <cstdint>
//#include <cmath>
#include <limits>



int main(){
    double n_entries{0};
    std::vector<double> numbers;
    std::cout << "Please enter the number of values you want to sum:" << std::endl;
    std::cin >> n_entries;
    std::cout << "Please enter some numbers (press '|' to stop):" << std::endl;
    double input;
    while(std::cin >> input){
        if(input > std::numeric_limits<double>::max() || input < std::numeric_limits<double>::lowest()){
            std::cerr << input << " is out of double range ["
                      << std::numeric_limits<double>::lowest() << ", "
                      << std::numeric_limits<double>::max() << "], try again: ";
            continue;
        }
        numbers.push_back(static_cast<double>(input));
    }

    if (n_entries < 2 || static_cast<size_t>(n_entries) > numbers.size()) {
            std::cerr << "Error: need at least 2 valid numbers.\n";
            return 1;
        }

    std::vector<double> diff_vec;
    for(int i = 1; i < n_entries; ++i){
        diff_vec.push_back(numbers[i]-numbers[i-1]);
    }

    if (diff_vec.size()>1)
    {
        std::cout << "The difference vector is:";
        for(const auto en:diff_vec){
             std::cout << en << ", ";
        }
    }



    return 0; // Exit without error
}

    
