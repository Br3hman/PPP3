#include "Date.h"

namespace DateLib {
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

    enum class Day{  // internal only — not exposed via Date.h
        Mon=1, Tue, Wed, Thu, Fri, Sat, Sun
    };

    std::string day_of_a_week_to_string(Day dow){
        switch(dow){
            case Day::Mon: return "Monday";
            case Day::Tue: return "Tuesday";
            case Day::Wed: return "Wednesday";
            case Day::Thu: return "Thursday";
            case Day::Fri: return "Friday";
            case Day::Sat: return "Saturday";
            case Day::Sun: return "Sunday";
            default: return "Unknown";
        }
    }

    void Date::add_day(int n){
            int day_index = d + n;
            int month_index =  day_index / 31; // Rough estimate, assuming 31 days per month
            if(day_index< 0 && day_index % 31 != 0){
                // integer division truncates toward zero, so correct the negative case manually
                month_index -= 1;
                day_index = 31 + (day_index % 31);
            }
            d = day_index % 31;
            if(d == 0) d = 31; // keep day in the 1..31 range instead of 0
            add_month(month_index);
    }

    void Date::add_month(int n){
        int month_index = to_int(m) + n;
        int year_increment = (month_index - 1) / 12; // -1 shifts 1-based month to 0-based so full years divide evenly
        if(month_index > 12){
        month_index = ((month_index - 1) % 12) + 1; // wrap back into the 1..12 range
        }
        add_year(year_increment);
        m = int_to_month(month_index);
    }

    void Date::add_year(int n){
        y.y += n;
    }

    //helper function
    bool is_leap_year(Year y){
        // The Leap Year Rule
        // A year is a leap year if:
        // It is divisible by 4, AND
        // It is NOT divisible by 100, UNLESS it is also divisible by 400.
        return (y.y % 4 == 0 && y.y % 100 != 0) || (y.y % 400 == 0);
    }
    int to_int(Month m){
        return static_cast<int>(m);
    }
    int to_int(Day dow){
        return static_cast<int>(dow);
    }
    Month int_to_month(int i){
        return static_cast<Month>(i);
    }

    // Zeller's Congruence: computes the weekday for any Gregorian date
    Day day_of_a_week(const Date& d) {
        // Treat January and February as months 13 and 14 of the previous year for Zeller's Congruence
        int y = d.get_year().y;
        int m = to_int(d.get_month());
        int day = d.get_day();
        if(m==1){
            m = 13; // Treat January as month 13 of the previous year
            y -= 1; // Adjust the year for January being treated as month 13 of the previous year
        } else if(m==2){
            m = 14; // Treat February as month 14 of the previous year
            y -= 1; // Adjust the year for February being treated as month 14 of the previous year
        }
        // Zeller's Congruence formula to calculate the day of the week
        int K = y % 100; // year within century
        int J = y / 100; // zero-based century
        int f = day + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J;
        int day_of_week = ((f + 5) % 7) + 1; // remaps Zeller's 0=Saturday result to 1=Monday..7=Sunday
        switch(day_of_week){
            case 1: return Day::Mon;
            case 2: return Day::Tue;
            case 3: return Day::Wed;
            case 4: return Day::Thu;
            case 5: return Day::Fri;
            case 6: return Day::Sat;
            case 7: return Day::Sun;
            default: return Day::Mon; // Fallback, should not happen
        }
    }

    std::string next_workday(const Date& d) {
        Day current_day = day_of_a_week(d);
        Date next_day = d;
        switch(current_day){
            case Day::Fri:
                next_day.add_day(3); // skip the weekend, landing on Monday
                break;
            case Day::Sat:
                next_day.add_day(2); // skip Sunday, landing on Monday
                break;
            default:
                next_day.add_day(1); // any other day, the next day is a workday
                break;
        }
        return day_of_a_week_to_string(day_of_a_week(next_day));
    }

// Helper function: returns day of year (1-365 or 1-366)
int day_of_year(const Date& d) {
    // Days in each month for a non-leap year
    static const int days_in_month[] = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    int days = d.get_day();

    // Sum all preceding months
    for (int m = 1; m < to_int(d.get_month()); ++m) {
        days += days_in_month[m];
    }

    // Add leap day if February has passed in a leap year
    if (to_int(d.get_month()) > 2 && is_leap_year(d.get_year())) {
        days += 1;
    }

    return days;
}

int week_of_year(const Date& d) {
    int day_number = day_of_year(d);
    int jan1_weekday = to_int(day_of_a_week(Date(d.get_year(), Month::jan, 1))); // unused: not yet factored into the week calc below
    return (day_number + 6) / 7; // round up so a partial first week still counts as week 1
}



} // namespace DateLib