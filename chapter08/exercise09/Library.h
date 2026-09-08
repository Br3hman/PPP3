/*
exercise 09
[9] Create a Library class.
[Done] Include vectors of Books and Patrons.
[Done] Include a struct called Transaction to record when a book is checked out.

[Done] Have it include a Book, a Patron, and a Date.

Make a vector of Transactions to keep a record of which books are out.

[Done] Create functions to add books to the library,
[Done] add patrons to the library, and
[Done] check out books.

[Done] Whenever a user checks out a book, have the library make sure that 
[Done] both the user and the book are in the library.
[Done] If they aren’t, report an error.

[Done] Then check to make sure that the user owes no fees.
[Done] If the user does, report an error.

[Done] If not, create a Transaction, and place it in the vector of Transactions.

Also write a function that will return a vector that contains the names of all Patrons who owe fees.
*/
#pragma once

#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
//#include <fstream>
#include <string>
//#include <vector>
//#include <algorithm>
//#include <numeric> //for accumulate
////#include <map>
//#include <cmath>
//#include <climits>
//#include <limits>
#include "Book.h"
#include "Patron.h"
#include "Date.h"
#include "Transaction.h"
namespace PPP_Lib {
    class Library
    {
        public:
            // I will let compiler create the constructor
            //Library(/* args */);
            //~Library();
            void add_book(const Book& b);
            void add_patron(const Patron& p);
            void check_out(const Book& b, const Patron& p, const Date& d);
            void check_in(const Book& b, const Patron& p, const Date& d);
            void print_library(std::ostream& os) const;
            //return a vector of patrons who owe fees
            std::vector<Patron> patrons_owing_fees() const;
        private:
            //check if patron exists in the library to avoid duplicates
            bool patron_exists(const Patron& p) const;
            //verify if patron exists in the library to throw error if they don't
            void verify_patron(const Patron& p) const;
            //check if book exists in the library
            bool book_exists(const Book& b) const;
            //Verify if book exists in the library to throw error if it doesn't
            void verify_book(const Book& b) const;

            //find and return the patron object from the library
            Patron& find_patron(const Patron& p);
            std::vector<Book> bk;
            std::vector<Patron> pt;
            std::vector<Transaction> tr;
    };

inline std::ostream& operator<<(std::ostream& os, const Library& lib)
{
    lib.print_library(os);
    return os;
}
} // namespace PPP_Lib