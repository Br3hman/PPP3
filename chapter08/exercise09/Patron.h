/*
exercise 08
[8] Create a Patron class for the library.
The class will have a
user’s name, library card number, and library fees (if owed).
Have functions that access this data,
as well as a function to set the fee of the user.
Have a helper function that returns a Boolean (bool)
depending on whether or not the user owes a fee.

*/
#pragma once

#include <iostream>
#include <string>

namespace PPP_Lib {
    class Patron {
        public:
        Patron(const std::string& name, int fee):
        n{name}, co{numbers_of_card++}, f{fee} {};
        Patron(const std::string& name):
        Patron(name, 0) {};
        std::string name() const {return n;};
        int card_num() const {return co;};
        int get_fee() const {return f;};
        void set_name(const std::string& name) {n=name;}
        void set_fee(int fees) {f=fees;}
        void add_fee(int fees) {f+=fees;}
        void current_cards() const {std::cout << "Current card number: " << numbers_of_card << std::endl;}
        private:
        // We control card numbers, not user get to set
        inline static int numbers_of_card = 0;
        std::string n;
        int co;
        int f;
    };

    inline bool owes(const Patron& p){
        if (p.get_fee()!=0)
            return true;
        return false;
    }

    inline std::ostream& operator<<(std::ostream& os, const Patron& p) {
        os << "Name: " << p.name() << ", Card Number: "
        << p.card_num() << ", Fee: " << p.get_fee()<<std::endl;
        return os;
    }

} // namespace PPP_Lib
