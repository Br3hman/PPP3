#include "name_pairs.h"


Name_Pairs::name_pairs::name_pairs(/* args */)
{
}

Name_Pairs::name_pairs::~name_pairs()
{
}



void Name_Pairs::name_pairs::read_name(){
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

void Name_Pairs::name_pairs::read_age(){
    if (name.empty())
        throw std::runtime_error("Name list is empty");

    for(std::string n:name){
        double age_en;
        std::cout<<format("Please enter {}'s age:",n);
        std::cin>> age_en;
        age.push_back(age_en);
    }
}

std::ostream& Name_Pairs::name_pairs::print(std::ostream& os) const{
    if (name.empty())
        throw std::runtime_error("Name list is empty");
    os<<"--------------------\n";
    for(auto i=0; i<name.size();i++){
        os << std::format("{} is {} years old\n", name[i], age[i]);
    }
    return os;
}

void Name_Pairs::name_pairs::sort_name(){
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

bool Name_Pairs::name_pairs::get_name_match(const name_pairs& a, const name_pairs& b) const{
    if (a.name.size() != b.name.size())
        throw std::out_of_range("Name lists are of different sizes");
    for (size_t i = 0; i < a.name.size(); ++i) {
        if (a.name[i] != b.name[i] || a.age[i] != b.age[i])
            return false;
    }
    return true;
}

std::ostream& Name_Pairs::operator<<(std::ostream& os, const name_pairs& np){
     return np.print(os);
}

bool Name_Pairs::operator==(const name_pairs& lhs, const name_pairs& rhs){
    return lhs.get_name_match(lhs, rhs);
}

bool Name_Pairs::operator!=(const name_pairs& lhs, const name_pairs& rhs){
    return !(lhs == rhs);
}