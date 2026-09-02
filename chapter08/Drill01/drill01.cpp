/*
drill 1
Write Day, Month, and their associated functions as described above.
Complete the final version of Date with default constructor,
is_valid(), Month, Year, etc.

Define a Date called today initialized to February 2, 2020.
Then, define a Date called tomorrow and give it a value by
copying today into it and increasing its day by one using add_day().

Finally, output today and tomorrow using a << defined as in §9.6 and §9.7.

Your check for a valid date, is_valid(), may be very simple.
Feel free to ignore leap years.

However, don’t accept a month that is not in the [1,12]
range or a day of the month that is not in the [1,31] range.

Test each version with at least one invalid date (e.g., 2004, 13, -5).

*/

#include <iostream>
#include <ostream>
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

//
enum class Month{
    jan=1, feb, mar, apr, may, jun, jui, aug, sep, oct, nov, dec
};

struct Year
{
    int y;
};
//helper function
int to_int(Month m);
Month int_to_month(int i);

//helper overloaded operators
bool operator==(Year a, Year b);
bool operator!=(Year a, Year b);
bool operator==(Month a, Month b);
bool operator!=(Month a, Month b);
Month& operator++(Month& m);    // Prefix increment
Month& operator+=(Month& m, int n); // Postfix increment
std::ostream& operator<<(std::ostream& os, Year y);
std::ostream& operator<<(std::ostream& os, Month m);


//Class definitions and other code will follow here
class Date
{
public:
    Date(Year yy, Month mm, int dd): y{yy}, m{mm}, d{dd} {};
    //~Date();
    // Modification / State Change
    void add_day(int n){
        int day_index = d + n;
        int month_index =  day_index / 31; // Rough estimate, assuming 31 days per month
        if(day_index< 0 && day_index % 31 != 0){
            month_index -= 1;
            day_index = 31 + (day_index % 31);
        }
        d = day_index % 31;
        if(d == 0) d = 31;
        add_month(month_index);

    }
    void add_month(int n){
        int month_index = to_int(m) + n;
        int year_increment = (month_index - 1) / 12; // 12 / 12 = 1   // WRONG — says a year already passed, but Dec is still year 0
        if(month_index > 12){
            month_index = ((month_index - 1) % 12) + 1;
        }
        add_year(year_increment);
        m = int_to_month(month_index);
    }
    void add_year(int n){
        y.y += n;
    }

    //Inspection Read-Only
    Year get_year() const { return y; }
    Month get_month() const { return m; }
    int get_day() const { return d; }
private:
    Year y{2000};
    Month m= Month::jan;
    int d{1};
};
std::ostream& operator<<(std::ostream& os, Date d);

int main()
{
    Date today{Year{2026}, Month::sep, 2};
    std::cout << "Today is: " << today << "\n";
    today.add_day(1);
    std::cout << "Tomorrow is: " << today << "\n";
    return 0;
}

//helper function
int to_int(Month m){
    return static_cast<int>(m);
}
Month int_to_month(int i){
    return static_cast<Month>(i);
}

//helper overloaded operators
bool operator==(Year a, Year b){
    return a.y == b.y;
}
bool operator!=(Year a, Year b){
    return !(a == b);
}
bool operator==(Month a, Month b){
    return a == b;
}
bool operator!=(Month a, Month b){
    return !(a == b);
}
Month& operator++(Month& m){    // Prefix increment
    m = static_cast<Month>(static_cast<int>(m) + 1);
    return m;
}
Month& operator+=(Month& m, int n){ // Postfix increment
    m = static_cast<Month>(static_cast<int>(m) + n);
    return m;
}
std::ostream& operator<<(std::ostream& os, Year y){
    os << y.y;
    return os;
}
std::ostream& operator<<(std::ostream& os, Month m){
    os << static_cast<int>(m);
    return os;
}
std::ostream& operator<<(std::ostream& os, Date d){
    os << d.get_year() << "-" << d.get_month() << "-" << d.get_day();
    return os;
}