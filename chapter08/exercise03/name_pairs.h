/*
exercise 03
[3] Replace Name_pair::print() with a (global)
operator << and define == and != for Name_pairs.

a. Added namespace to the name_pairs class and the operator << function.

1. I made a helper function << to print the name_pairs object.
Since, I dont want it to have direct access to private members,
I modifed the code to use the public print() function inside the operator <<.




*/

#include <iostream>
#include <ostream>
#include <format>
//#include <sstream>
#include <stdexcept>
//#include <fstream>
//#include <string>
#include <vector>
#include <algorithm>
#include <numeric> //for accumulate
////#include <map>
#include <cmath>
//#include <climits>
//#include <limits>

namespace Name_Pairs{

class name_pairs
{
public:
    name_pairs(/* args */);
    name_pairs(const std::vector<std::string>& names, const std::vector<double>& ages):
        name(names), age(ages) {}
    void read_name();
    void read_age();
    std::ostream& print(std::ostream& os) const;
    void sort_name();
    bool get_name_match(const name_pairs& a, const name_pairs& b) const;
    ~name_pairs();
private:
    std::vector<std::string> name;
    std::vector<double> age;
};

std::ostream& operator<<(std::ostream& os, const name_pairs& np);
bool operator==(const name_pairs& lhs, const name_pairs& rhs);
bool operator!=(const name_pairs& lhs, const name_pairs& rhs);

} // namespace Name_Pairs