/*
[14] Read (day-of-the-week,value) pairs from standard input. 
For example: Tuesday 23 Friday 56 Tuesday −3 Thursday 99 
Collect all the values for each day of the week in a vector<int>. 
Write out the values of the seven day-of-the-week vectors. 
Print out the sum of the values in each vector. 
Ignore illegal days of the week, 
such as Funday, but accept common synonyms such as 
Mon and monday. Write out the number of rejected values.

1. Read (day-of-week, value) pairs
2. Collect values per day in vector<int>
3. Print values of each day's vector
4. Print sum of each day's vector
5. Ignore illegal day names, accept synonyms like Mon, monday, etc.
6. Print number of rejected values

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


char parse_day(std::string s){
    if (s == "mon" || s == "Mon" || s == "monday" || s == "Monday") return 'M';
    if (s == "tue" || s == "Tue" ||s == "tuesday" || s == "Tuesday") return 'T';
    if (s == "wed" || s == "Wed" ||s == "wednesday" || s == "Wednesday") return 'W';
    if (s == "thu" || s == "Thu" ||s == "thursday" || s == "Thursday") return 'H';
    if (s == "fri" || s == "Fri" ||s == "friday" || s == "Friday") return 'F';
    if (s == "sat" || s == "Sat" ||s == "saturday" || s == "Saturday") return 'S';
    if (s == "sun" || s == "Sun" ||s == "sunday" || s == "Sunday") return 'U';
    return 'R';
}

int main() {
    std::vector<std::pair<std::string, int>> day_values = {
        {"Monday", 0}, {"Tuesday", 0}, {"Wednesday", 0},
        {"Thursday", 0}, {"Friday", 0}, {"Saturday", 0},
        {"Sunday", 0}};

    std::cout << "Enter (day-of-week, value) pairs (e.g., Monday 5). Type 'exit' to finish:\n";
    std::string day;
    int value;
    int rejected_count = 0;
    while(std::cin >> day){
        if(day == "exit") break;
        std::cin >> value;
        char parsed_day = parse_day(day);
        switch(parsed_day) {
            case 'M': day_values[0].second += value; break;
            case 'T': day_values[1].second += value; break;
            case 'W': day_values[2].second += value; break;
            case 'H': day_values[3].second += value; break;
            case 'F': day_values[4].second += value; break;
            case 'S': day_values[5].second += value; break;
            case 'U': day_values[6].second += value; break;
            default: ++rejected_count; break;
        }
    }

    std::cout << "--------------Values per day--------------\n";
    for (const auto& dv : day_values) {
        std::cout << dv.first << ": " << dv.second << "\n";
    }
    std::cout << "Rejected values: " << rejected_count << "\n";

    return 0;
}

   

    
