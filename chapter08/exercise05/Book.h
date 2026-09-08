/*
exercise 05
[5] This exercise and the next few require you to design and implement a Book class,
such as you can imagine as part of software for a library.
Class Book should have members for the
ISBN, title, author, and copyright date.
Also store data on whether or not the book is checked out.
Create functions for returning those data values.
Create functions for checking a book in and out.
Do simple validation of data entered into a Book;
    for example, accept ISBNs only of the form n−n−n−x
    where n is an integer and x is a digit or a letter. Store an ISBN as a string.
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
}