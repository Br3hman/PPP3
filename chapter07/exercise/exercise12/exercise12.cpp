/*
exercise 12
[12] Improve print_until_s() from §7.4.2. Test it. What makes a good set of test cases? Give reasons.
Then, write a print_until_ss() that prints until it sees a second occurrence of its quit argument.
*/

#include <iostream>
//#include <sstream>
#include <stdexcept>
//#include <fstream>
//#include <string>
#include <vector>
#include <algorithm>
#include <numeric> //for accumulate
////#include <map>
//#include <cmath>
//#include <climits>
//#include <limits>

void print_until_s(std::vector<std::string> v, std::string quit){
         // print until the string called "quit" is found
    for(const auto& s : v){
        if(s == quit)
            break;
        std::cout << s << std::endl;
    }
}

void print_until_ss(std::vector<std::string> v, std::string quit){
    int count = 0;
    for(const auto& s : v){
        if(s == quit){
            count++;
            if(count == 2)
                break;
        }
        std::cout << s << std::endl;
    }
}



int main(){
    try
    {
        std::vector<std::string> test_strings{"apple", "banana", "cherry", "apple", "date"};
        std::cout << "Testing print_until_s with quit='apple':\n";
        print_until_s(test_strings, "apple");
        std::cout << "Testing print_until_ss with quit='apple':\n";
        print_until_ss(test_strings, "apple");
        std::cout << "Testing print_until_s with quit='banana':\n";
        print_until_s(test_strings, "banana");
        std::cout << "Testing print_until_ss with quit='banana':\n";
        print_until_ss(test_strings, "banana");

    return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


}