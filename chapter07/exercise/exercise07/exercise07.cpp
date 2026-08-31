/*
[7] Read five names into a vector<string> name,
then prompt the user for the ages of the people named and store the ages in a vector<double> age.

Then print out the five (name[i],age[i]) pairs.
Sort the names (sort(name.begin(),name.end())) and print out the (name[i],age[i]) pairs.

The tricky part here is to get the age vector in the correct order to match the sorted name vector.

Hint: Before sorting name, take a copy and use that to make a copy of age in the right order after sorting name.
*/

#include <iostream>
//#include <sstream>
//#include <stdexcept>
//#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
////#include <map>
//#include <cmath>
//#include <climits>
#include <limits>

template<typename T> //to avoid using int-specific functions or std::string specific functions
void print(const std::string& label, const std::vector<T>& vec){
    std::cout<<label<<std::endl;
    for(auto v:vec){
        std::cout<<v<<" ";
    }
    std::cout<<"\n";
}

template<typename T1, typename T2>
void print_pairs(const std::vector<T1>& vec1, const std::vector<T2>& vec2){
    for(size_t i=0;i<vec1.size() && i<vec2.size();i++){
        std::cout<<"("<<vec1[i]<<","<<vec2[i]<<")"<<std::endl;
    }
}

void sort_name_age_pairs(std::vector<std::string>& name, std::vector<double>& age){
    std::vector<std::string> name_copy = name;
    std::vector<double> second;
    std::sort(name.begin(), name.end());
    for(int i=0; i<name.size(); i++){
        for (int j = 0; j < name_copy.size(); j++)
        {
            if(name[i]==name_copy[j]){
                //std::cout<<age[j]<<std::endl;
                second.push_back(age[j]);
            }
        }
    }
    age.clear();
    for(auto a:second)
       age.push_back(a);
}
int main(){
    std::vector<std::string> name;
    std::vector<double> age;
    int number_names=5;
    int entries = 0;
    std::cout<<"Please enter "<< number_names << " names:\n";
    std::string name_entry;
    std::cout<<"Name ["<<entries+1<<"]"<<": ";
    while (entries<number_names && std::cin>>name_entry)
    {
        name.push_back(name_entry);
        entries+=1;
        if (entries<number_names) {
            std::cout<<"Name ["<<entries+1<<"]"<<": ";
        }
    }

    std::cout<<"Please enter the ages for the names you provided:\n";
    for (auto s:name)
    {
        std::cout<< s <<"'s age=";
        double age_entry;
        std::cin>>age_entry;
        age.push_back(age_entry);
    }
    print_pairs(name, age);
    sort_name_age_pairs(name, age);
    std::cout<<"After sorting by name:\n";
    print_pairs(name, age);

    return 0;
}