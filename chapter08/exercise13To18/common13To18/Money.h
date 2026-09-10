/*
[14] Design and implement a Money class for calculations involving
dollars and cents where arithmetic has to be accurate to the last
cent using the 4/5 rounding rule (.5 of a cent rounds up; anything
less than .5 rounds down).

Represent a monetary amount as a number of cents in a long int,
but input and output as dollars and cents,

e.g., $123.45. Do not worry about amounts that don’t fit into a long int.

I will need to implement constructors, accessor functions, and arithmetic
operators for the Money class, ensuring that all calculations adhere to the 4/5 rounding rule.

Constructors
(long int cents = 0) // default constructor with optional cents parameter

Accessor functions
(long int getCents() const) // returns the number of cents
(double getDollars() const) // returns the amount in dollars

Arithmetic operators to implement would include
(a) addition,
(b) subtraction,
(c) multiplication, and
(d) division,
all adhering to the 4/5 rounding rule.

Operator >> and <<
(a) input operator >>, I need to implement it to read Money objects from input streams.
    I also need to handle $ signs in the input and also negative amounts.
(b) output operator <<, I need to implement it to write Money objects to output streams.

Also, consider implementing comparison operators (==, !=, <, <=, >, >=)
to facilitate comparisons between Money objects.
*/

#include <iostream>
#include <numeric>   // std::gcd and std::abs
#include <stdexcept>
#include <cmath>
#include <vector>

namespace PPP_Calc{
enum class Currency{
    USD,
    EUR,
    GBP,
    JPY
};

inline int currencyToInt(Currency c){
    switch(c){
        case Currency::USD: return 0;
        case Currency::EUR: return 1;
        case Currency::GBP: return 2;
        case Currency::JPY: return 3;
        default: throw std::invalid_argument("Unknown currency");
    }
}

inline Currency intToCurrency(int i){
    switch(i){
        case 0: return Currency::USD;
        case 1: return Currency::EUR;
        case 2: return Currency::GBP;
        case 3: return Currency::JPY;
        default: throw std::invalid_argument("Unknown currency");
    }
}

    double currencyExchangeRate(const Currency from, Currency to);

    class Money{
        public:
        Money() = default;
        Money(Currency c): cents{0}, c{c} { ;};
        Money(double d, Currency c): cents{round_rule(d)}, c{c} { ;};
        long int getCents() const { return cents; }
        Currency getCurrency() const { return c; }
        double getDollars() const { return static_cast<double>(cents) / 100; }
        Money& operator=(double d){
            cents=round_rule(d);
            return *this;
        }
        Money& operator+=(const Money& a);
        Money& operator-=(const Money& a);
        Money& operator*=(const Money& a);
        Money& operator/=(const Money& a);
        private:
        long int round_rule(double c){
            //1234.454 -> 1234.45 or 1234.456 -> 1234.46
            //std::cout << "c: " << c << "\n";
            long int val = c * 100; //truncate value after 2 decimals
            //std::cout << "val (after truncation): " << val << "\n";
            long int temp = c * 1000;
            //std::cout << "temp (for rounding check): " << temp << "\n";
            if (temp % 10 > 4){ // 1234.454 -> 4 and 1234.456-> 6 so we add one
                ++val; // add one to it
                //std::cout << "val (after rounding): " << val << "\n";
            }
            return val;
        }
        long int cents=0;
        Currency c=Currency::USD;
    };
    inline Money operator+(Money lhs, const Money& rhs){return lhs += rhs;}
    inline Money operator-(Money lhs, const Money& rhs){return lhs -= rhs;}
    inline Money operator*(Money lhs, const Money& rhs){return lhs *= rhs;}
    inline Money operator/(Money lhs, const Money& rhs){return lhs /= rhs;}
    std::istream& operator>>(std::istream& iss, Money& m);
    std::ostream& operator<<(std::ostream& oss, Money& m);
}