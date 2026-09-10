/*
[13] Design and implement a rational number class, Rational.
A rational number has two parts:
a numerator and a denominator,
for example, 5/6 (five-sixths, also known as approximately .83333).
Look up the definition if you need to.
Provide
    (a) assignment,
    (b) addition,
    (c) subtraction,
    (d) multiplication,
    (e) division, and
    (f) equality operators.

Also, provide a conversion to double.

Why would people want to use a Rational class?

Exact Precision: Floating-point arithmetic fails at exact representation
for simple fractions (e.g., 1/3 = 0.333333...).
Repeated additions like 1/3 + 1/3 + 1/3 using double can yield 0.9999999999999999,
whereas Rational guarantees exactly $1$.

Financial & Scientific Calculations: Prevents accumulated rounding error
drift in interest rates, ratios, stock fractions, and algebraic computing
systems (e.g., Symbolic Math Libraries / CAS).

Exact Equality Testing: Comparing double values using == is
dangerous due to epsilon inaccuracies. Comparing two normalized
Rational numbers is a strict, unambiguous integer comparison.

Rational Class (Exact Mathematical Fractions)
Core Concept: Class invariants and mathematical
    precision without precision loss.
Key Takeaway: Demonstrates how to design custom
    numerical types by maintaining an invariant
    (keeping fractions in simplified form using GCD)
    and overloading arithmetic operators so custom
    types behave like built-in primitives (int, double).

*/
#include <iostream>
#include <numeric>   // std::gcd and std::abs
#include <stdexcept>

namespace PPP_Calc{
    class Rational
    {
    public:
        // Constructor with default values for numerator and denominator
        Rational(long long n=0, long long g=1): num{n}, den{g} {
            normalize(); //need to do it for each object
        };
        ~Rational();
        // Accessor functions for numerator and denominator
        long long numerator() const { return num; }
        long long denominator() const { return den; }
        // Operator overloads that mutate the Rational object (e.g., +=, -=, *=, /=) would go here.
        // As naturally belong to *this object being changed
        Rational& operator+=(const Rational& rhs);
        Rational& operator-=(const Rational& rhs);
        Rational& operator*=(const Rational& rhs);
        Rational& operator/=(const Rational& rhs);
    private:
        void normalize()
        // reducing a fraction to lowest terms
        {
            if(den == 0)
                throw std::invalid_argument("Denominator cannot be zero\n.");
            //Greatest common divisor function returns the greatest common divisors of the argument of Num and Den.
            //Needed for normalization
            //std::gcd requires integer types (not floating point), which fits long long num, den members perfectly.
            long long g = std::gcd(std::abs(num),std::abs(den));
            //finally
            num /= g;
            den /= g;
        }
        long long num;
        long long den;
    };

    //free functions, using only the public interface - no friend need
    inline Rational operator+(Rational& a, const Rational&b) {  a+=b; return a; }
    inline Rational operator-(Rational& a, const Rational&b) {  a-=b; return a; }
    inline Rational operator*(Rational& a, const Rational&b) {  a*=b; return a; }
    inline Rational operator/(Rational& a, const Rational&b) {  a/=b; return a; }

    inline bool operator==(const Rational& a, const Rational& b){
        return a.numerator() == b.numerator() && a.denominator() == b.denominator();
    }
}//end of namespace PPP_Calc