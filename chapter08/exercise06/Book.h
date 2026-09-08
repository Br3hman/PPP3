/*
exercise 06
[6] Add operators for the Book class.
Have the == operator check whether the ISBN numbers are the same for two books.
Have != also compare the ISBN numbers.
Have a << print out the title, author, and ISBN on separate lines.
*/
#include <iostream>
#include <ostream>
#include <sstream>
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

namespace Book_Library {
    class Book {
    public:
        Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& copyright_date):
        isbn(isbn), title(title), author(author), copyright_date(copyright_date), checked_out(false) {
            if (!valid_isbn(isbn))
			throw std::runtime_error{"Invalid ISBN format"};
        };
        std::string get_isbn() const { return isbn; }; // Returns the ISBN of the book
        std::string get_title() const { return title; }; // Returns the title of the book
        std::string get_author() const { return author; }; // Returns the author of the book
        std::string get_copyright_date() const { return copyright_date; }; // Returns the copyright date of the book
        bool is_checked_out() const { return checked_out; }; // Returns true if the book is checked out, false otherwise
        void check_out(); // Marks the book as checked out
        void check_in(); // Marks the book as checked in
        bool valid_isbn(const std::string& isbn_in);
    private:
        std::string isbn; // ISBN of the book: formate n−n−n−x, where n is an integer and x is a digit or a letter.
        std::string title;
        std::string author;
        std::string copyright_date;
        bool checked_out;
    };
    inline bool operator==(const Book& lhs, const Book& rhs) {
        return lhs.get_isbn() == rhs.get_isbn();
    }

    inline bool operator!=(const Book& lhs, const Book& rhs) {
        return !(lhs == rhs);
    }

    inline std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Title: " << book.get_title() << "\n"
           << "Author: " << book.get_author() << "\n"
           << "ISBN: " << book.get_isbn() << "\n";
        return os;
    }
}