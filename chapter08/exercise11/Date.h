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
namespace DateLib {
//
enum class Month{
    jan=1, feb, mar, apr, may, jun, jui, aug, sep, oct, nov, dec
};

struct Year
{
    int y;
};

//Class definitions must come before any function that references Date
class Date
{
public:
    Date(Year yy, Month mm, int dd): y{yy}, m{mm}, d{dd} {};
    //~Date();
    // Modification / State Change
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

    //Inspection Read-Only
    Year get_year() const { return y; }
    Month get_month() const { return m; }
    int get_day() const { return d; }
private:
    Year y{2000};
    Month m= Month::jan;
    int d{1};
};

//helper function
bool is_leap_year(Year y);
int to_int(Month m);
Month int_to_month(int i);
int get_next_workday(int day_of_week);
std::string next_workday(const Date& d);
int week_of_year(const Date& d);
//helper overloaded operators
bool operator==(Year a, Year b);
bool operator!=(Year a, Year b);
bool operator==(Month a, Month b);
bool operator!=(Month a, Month b);
Month& operator++(Month& m);    // Prefix increment
Month& operator+=(Month& m, int n); // Postfix increment
std::ostream& operator<<(std::ostream& os, Year y);
std::ostream& operator<<(std::ostream& os, Month m);
std::ostream& operator<<(std::ostream& os, Date d);
} // namespace DateLib