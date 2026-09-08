/*
exercise 06
[6] Add operators for the Book class. Have the == operator check whether the ISBN numbers are the same for two books. Have != also compare the ISBN numbers. Have a << print out the title, author, and ISBN on separate lines.

*/
#include "Book.h"
namespace PPP_Lib{
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

} // namespace PPP_Lib