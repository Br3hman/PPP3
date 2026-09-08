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
#include "Book.h"
namespace Book_Library{
    bool Book::valid_isbn(const std::string& isbn_in){
        if (isbn_in.size() < 7) // n-n-n-x = 7
            return false;

        std::istringstream  iss(isbn_in);
        int n1,n2,n3;
        char d1,d2,d3,x;
        //        n     -     n     -     n   -     x
        if(iss >> n1 >> d1 >> n2 >> d2 >> n3>> d3 >> x && d1=='-'&& d2=='-'&& d3=='-'){
            return true;
        }else{
            return false;
        }

    }
    void Book::check_out(){
        if(is_checked_out())
            throw std::runtime_error("Book is already checked out");
        std::cout << "Checking out book: " << get_title() << std::endl;
        checked_out = true;
    }
    void Book::check_in(){
        if (!is_checked_out())
            throw std::runtime_error("Book is already checked in");
        std::cout << "Checking in book: " << get_title() << std::endl;
        checked_out = false;
    }

}