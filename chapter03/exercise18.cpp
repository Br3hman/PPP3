/*
[18] Write a program where you first enter a set of name-and-value pairs, 
such as Joe 17 and Barbara 22. For each pair, add the name to a vector 
called names and the number to a vector called scores (in corresponding 
positions, so that if names[7]=="Joe" then scores[7]==17). Terminate i
nput with NoName 0. Check that each name is unique and terminate with 
an error message if a name is entered twice. Write out all the 
(name,score) pairs, one per line.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include <cstdint>
#include <cmath>

std::pair<std::string, int> get_input(){
    std::string input;
    int number;
    std::cout << "Enter a Name and a value (or 'q' to quit):" << std::endl;
    std::cin >> input;
    if(input == "NoName" || input == "q"){
        return {input, 0}; // Return a pair indicating quit
    }
    std::cin >> number;
    return {input, number};
}


int main(){
    std::vector<std::pair<std::string, int>> entries;
    while(true){

        auto [name, value] = get_input();
        if(name == "NoName") break;
        entries.push_back({name, value});
        if(name == "NoName") break;
        if(name=="q") break;
    }

    std::sort(entries.begin(), entries.end(), [](const auto& a, const auto& b) {
        return a.first < b.first; // Sort by the name
    });

    for (auto i = 0; i < entries.size()-1; ++i) {
        if (entries[i].first == entries[i + 1].first){
            std::cout << "Duplicate: " << entries[i].first << std::endl;
            return 1; // Exit with error
        }
    }

    for(const auto& [name, value] : entries){
        std::cout << name << ": " << value << std::endl;
    }
    return 0;
}

    
