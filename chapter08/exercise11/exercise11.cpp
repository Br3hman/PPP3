/*
exercise 11
[11] Design and implement a set of useful helper functions for the Date
class with functions such as next_workday() (assume that any day that is
not a Saturday or a Sunday is a workday) and week_of_year() (assume that
week 1 is the week with January 1 in it and that the first day of a week is a Sunday).
*/

#include "Date.h"

int main()
{
    DateLib::Date today{DateLib::Year{2026}, DateLib::Month::sep, 3};
    std::cout << "Today is: " << today << "\n";
    today.add_day(1);
    std::cout << "Tomorrow is: " << today << "\n";
    std::cout<<"Is " << today.get_year() << " a leap year? " << (DateLib::is_leap_year(today.get_year()) ? "Yes" : "No") << "\n";
    std::cout << "Next workday after day after tomorrow: " << DateLib::next_workday(today) << "\n";
    std::cout << "Week of the year: " << DateLib::week_of_year(today) << "\n";
    return 0;
}
