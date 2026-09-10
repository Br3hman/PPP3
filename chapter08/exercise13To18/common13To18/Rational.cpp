#include "Rational.h"
namespace PPP_Calc{
     Rational& Rational::operator+=(const Rational& rhs){
        num = num*rhs.den + rhs.num * den;
        den = den * rhs.den;
        normalize();
        return *this;//updated object return
     }
     Rational& Rational::operator-=(const Rational& rhs){
        num = num*rhs.den - rhs.num * den;
        den = den * rhs.den;
        normalize();
        return *this;//updated object return
     }
     Rational& Rational::operator*=(const Rational& rhs){
        num *=rhs.num;
        den *= rhs.den;
        normalize();
        return *this;//updated object return
     }
    Rational& Rational::operator/=(const Rational& rhs){
        if (rhs.num == 0)
            throw std::domain_error("Division by zero in Rational.");
        num *=rhs.den;
        den *= rhs.num;
        normalize();
        return *this;//updated object return
     }

}