/*
[20] Modify the program from the previous exercise so that
once you have entered the name-and-value pairs,
you ask for names: In a loop, when you enter a value,
the program will output all the names with that score or score not found.
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

    std::cout << "Enter a value to search for:" << std::endl;
    int search_value;
    std::cin >> search_value;
    bool found = false;
    for(const auto& entry : entries){
        if(entry.second == search_value){
            std::cout << "Found: " << entry.first << std::endl;
            found = true;
        }
    }
    if(!found){
        std::cout << "Value not found." << std::endl;
    }

    return 0; // Exit without error
}

    
