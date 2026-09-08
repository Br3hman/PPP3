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
using namespace Book_Library;
int main(){
    try
    {
        Book myBook("123-456-789-A", "My Title", "My Author", "2024");
        myBook.check_out();
        myBook.check_in();
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

}