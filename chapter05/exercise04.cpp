/*
[4] Define a class Name_value that holds a string and a value.
Rework exercise 20 in Chapter 3 to use a vector<Name_value> instead of two vectors.

1. Create a class Name_value that holds a string and a value.
2. Rework exercise 20 in Chapter 3 to use a vector<Name_value> instead of two vectors.
Whereas the original exercise used two separate vectors,
one for names and one for values, this reworked version uses a single vector of Name_value objects.
3. Program should first enter a set of name-and-value pairs, such as Joe 17 and Barbara 22.
4. For each pair, add the name to a vector called names and the number to a vector called scores
(in corresponding positions, so that if names[7]=="Joe" then scores[7]==17).
5. Terminate input with NoName 0 or with 'q'.
6. When you enter a value, the program will output all the names with that score or score not found.
    -Need to check for duplicate names and report an error if a name is entered twice.
    -Need to sort the names before checking for duplicates.
    -Need to check for duplicate names and report an error if a name is entered twice.

CC
std::vector<std::size_t> vec

What it is:

    std::size_t is an integer type used for sizes and indexes.
    std::vector<T> is a dynamic array of T.
    So std::vector<std::size_t> is a growable list of indexes.
    Why it is useful in your search case:

        No match: return an empty vector.
        One match: return one index.
        Multiple matches: return many indexes.
        Caller can then read or update the original vector using those positions.

*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstddef>   // for std::size_t
#include <algorithm>
//#include <map>
//#include<cmath>

class Name_value {
    public:
        Name_value(std::string Name, int val): n{Name}, v{val}{};
        std::string name() const {return n;} //get the name of the entry
        double value() const {return v;} // get the value of the entry
    private:
        std::string n; //Name entry
        int v; //for numbers: a value
};

bool is_unique(const std::vector<Name_value>& vec){
       for (auto i = 0; i < vec.size()-1; ++i) {
            if (vec[i].name() == vec[i + 1].name()){
                std::cout << "Duplicate entry found: " << vec[i].name() << std::endl;
                return false; // Exit with error
            }
        }
    return true;
}

std::vector<std::size_t> search_match(const std::vector<Name_value>& vec_in, int values){
    std::vector<std::size_t> vec_out;
    for(std::size_t i=0; i<vec_in.size(); ++i){
        if(vec_in[i].value() == values){
            vec_out.push_back(i);
        }
    }
    if(vec_out.empty()){
        throw std::runtime_error("No matching value found.");
    }
    return vec_out;
}




int main() {
    try{

        std::vector<Name_value> entries;
        while(true){
            std::string input;
            int number;
            std::cout << "Enter a Name and a value (or 'q' to quit):" << std::endl;
            std::cin >> input;
            if(input == "NoName" || input == "q"){
                break; // Exit the loop if "NoName" or 'q' is entered
            }
            std::cin >> number;
            entries.push_back(Name_value(input, number));
        }
        if(entries.empty()){
            std::cout << "No entries were provided." << std::endl;
            return 0; // Exit without error if no entries were provided
        }

        std::sort(entries.begin(), entries.end(), [](const Name_value& a, const Name_value& b){
            return a.name() < b.name();
        });
        if(!is_unique(entries)){
            return 1; // Exit with error if duplicates are found
        }
        std::cout << "Enter a value to search for:" << std::endl;
        int search_value;
        std::cin >> search_value;
        std::vector<std::size_t> matching_indices = search_match(entries, search_value);
        std::cout << "Matching entries:" << std::endl;
        for(std::size_t index : matching_indices){
            std::cout << entries[index].name() << " " << entries[index].value() << std::endl;
        }

    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}


