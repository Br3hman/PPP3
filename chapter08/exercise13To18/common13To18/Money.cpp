#include "Money.h"
namespace PPP_Calc{

    double currencyExchangeRate(Currency from, Currency to){
        // Implement the actual exchange rate logic here
        // For simplicity, let's assume 1:1 exchange rate for now
        if (from==to)
            return 1.0;

        std::vector<std::vector<double>> exchangeRates = {
            {1.0, 0.9, 0.8, 110.0},  // USD to USD, EUR, GBP, JPY
            {1.1, 1.0, 0.88, 122.0}, // EUR to USD, EUR, GBP, JPY
            {1.25, 1.14, 1.0, 138.0},// GBP to USD, EUR, GBP, JPY
            {0.009, 0.008, 0.007, 1.0} // JPY to USD, EUR, GBP, JPY
        };
        if(currencyToInt(from) < 0 || currencyToInt(from) >= 4 ||
           currencyToInt(to) < 0 || currencyToInt(to) >= 4){
            throw std::invalid_argument("Unknown currency");
        }
        return exchangeRates[currencyToInt(from)][currencyToInt(to)];
    }
    Money& Money::operator+=(const Money& a){
        cents += a.getCents()*currencyExchangeRate(a.getCurrency(), c);
        return *this;
    }
    Money& Money::operator-=(const Money& a){
        cents -= a.getCents()*currencyExchangeRate(a.getCurrency(), c);
        return *this;
    }
    Money& Money::operator*=(const Money& a){
        cents = (cents*currencyExchangeRate(a.getCurrency(), c))*(a.getCents()*currencyExchangeRate(a.getCurrency(), c));
        return *this;
    }
    Money& Money::operator/=(const Money& a){
        double result = static_cast<double>(cents*currencyExchangeRate(a.getCurrency(), c))/(a.getCents()*currencyExchangeRate(a.getCurrency(), c));
        cents = round_rule(result);
        return *this;
    }
    std::istream& operator>>(std::istream& iss, Money& m){
        double d;
        iss >> d;
        m = d;
        return iss;
    }
    std::string currencyToString(Currency c){
        switch(c){
            case Currency::USD: return "USD";
            case Currency::EUR: return "EUR";
            case Currency::GBP: return "GBP";
            case Currency::JPY: return "JPY";
            default: throw std::invalid_argument("Unknown currency");
        }
    }
    std::ostream& operator<<(std::ostream& oss, Money& m){
        oss << currencyToString(m.getCurrency()) << " ";

        long int amount = m.getCents();
        //std::cout << "amount $: " << amount/100 << "\n";
        //std::cout << "amount cents: " << std::abs(amount%100) << "\n";
         oss << amount/100 << "." << std::abs(amount%100);
        return oss;
    }
}