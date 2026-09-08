#include "name_pairs.h"

name_pairs::name_pairs(/* args */)
{
}

name_pairs::~name_pairs()
{
}

void name_pairs::read_name(){
    std::cout<<"Welcome to name pair class\n"
    "Please enter a list of Names (type quit exit)\n";
    std::string name_en;
    while (std::cin>> name_en)
    {
        if (name_en=="quit" || name_en=="q")
        {
            break;
        }
        name.push_back(name_en);
    }
}

void name_pairs::read_age(){
    if (name.empty())
        throw std::runtime_error("Name list is empty");

    for(std::string n:name){
        double age_en;
        std::cout<<format("Please enter {}'s age:",n);
        std::cin>> age_en;
        age.push_back(age_en);
    }
}

void name_pairs::print(){
    if (name.empty())
        throw std::runtime_error("Name list is empty");
    std::cout<<"--------------------\n";
    for(auto i=0; i<name.size();i++){
        std::cout << std::format("{} is {} years old\n", name[i], age[i]);
    }
}

void name_pairs::sort_name(){
    if (name.empty())
        throw std::runtime_error("Name list is empty, nothing to sort");
    std::vector<std::string> sorted_names = name;
    std::sort(sorted_names.begin(), sorted_names.end());
    std::vector<double> sorted_ages;
    for (const auto& n : sorted_names) {
        auto it = std::find(name.begin(), name.end(), n);
        sorted_ages.push_back(age[it - name.begin()]);
    }
    name = sorted_names;
    age = sorted_ages;

}