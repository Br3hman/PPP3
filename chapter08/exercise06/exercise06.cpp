/*
exercise 06
*/
#include "Book.h"
using namespace Book_Library;
int main(){
    try
    {
        Book myBook("123-456-789-A", "My Title", "My Author", "2024");
        myBook.check_out();
        myBook.check_in();
        std::cout << myBook << std::endl;
        Book anotherBook("123-456-789-A", "Another Title", "Another Author", "2024");
        if(myBook == anotherBook)
            std::cout << "Books have the same ISBN." << std::endl;
        if(myBook != anotherBook)
            std::cout << "Books have different ISBNs." << std::endl;
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

}