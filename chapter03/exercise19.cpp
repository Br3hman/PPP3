/*
[19] Modify the program from the previous exercise so that once you have entered 
the name-and-value pairs, you ask for values: In a loop, when you enter a name, 
the program will output the corresponding score or name not found.
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

    std::cout << "Enter a name to search for:" << std::endl;
    std::string search_name;
    std::cin >> search_name;
    auto it = std::find_if(entries.begin(), entries.end(), [&](const auto& entry) {
        return entry.first == search_name;
    });
    if(it != entries.end()){
        std::cout << "Found: " << it->first << ": " << it->second << std::endl;
    } else {
        std::cout << "Name not found." << std::endl;
    }
    return 0;
}

    
