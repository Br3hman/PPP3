/*
[3] If we define the median of a sequence as “a number so that exactly 
as many elements come before it in the sequence as come after it,” 
fix the program in §3.6.3 so that it always prints out a median. 
Hint: A median need not be an element of the sequence.
*/

#include <iostream>
#include <vector>
#include <algorithm>
int main(){
    std::vector<double> temps;
    std::cout << "Temperatures entries (Ctrl+D to end):" << std::endl;
    for(double temp; std::cin >> temp;){
        temps.push_back(temp);
    }
    std::sort(temps.begin(), temps.end());
    std::cout << "Sorted temperatures:[ ";
    for (const auto& temp : temps) {
        std::cout << temp << ", ";
    }
    std::cout << "]" << std::endl;
    
    
    
    double median;
    if(temps.size() % 2 == 0){
        median = (temps[temps.size()/2 - 1] + temps[temps.size()/2]) / 2;
    } else if (temps.size() == 0) {
        median = 0; // or some other value indicating no median
    } else {
        median = temps[temps.size()/2];
    }

    std::cout << "Median: " << median << std::endl;

    return 0;
}
