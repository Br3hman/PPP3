/*
[4] Read a sequence of double values into a vector. Think of each value as the distance between 
two cities along a given route. Compute and print the total distance (the sum of all distances). 
Find and print the smallest and greatest distance between two neighboring cities. 
Find and print the mean distance between two neighboring cities.
*/
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    double current_distance{0.0}, sum{0.0};
    std::vector<double> distance;
    std::cout << "Enter distances (Ctrl+D to end):" << std::endl;
    while(std::cin >> current_distance){
        sum += current_distance;
        distance.push_back(current_distance);
    }

    if(distance.empty()){
        std::cout << "No distances were entered." << std::endl;
    } else {
        std::sort(distance.begin(), distance.end());
        std::cout << "Smallest distance: " << distance.front() << std::endl;
        std::cout << "Largest distance: " << distance.back() << std::endl;
        double mean_distance = (distance.front() + distance.back()) / 2.0;
        std::cout << "Mean distance: " << mean_distance << std::endl;
    }
    return 0;
}