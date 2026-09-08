/*
exercise 08

*/
#include "Book.h"
#include "Patron.h"
using namespace Patron_Library;
using namespace Book_Library;
int main(){
    try
    {
        Book myBook("123-456-789-A", "My Title", "My Author", "2024", string_to_genre("Fiction"));
        myBook.check_out();
        myBook.check_in();
        std::cout << myBook << std::endl;

        Patron myPatron("John Doe", 0);
        myPatron.set_fee(10);
        myPatron.add_fee(5);
        std::cout << myPatron << std::endl;
        Patron anotherPatron("Jane Doe", 0);
        std::cout << anotherPatron << std::endl;
        myPatron.current_cards();
        anotherPatron.current_cards();
        if(ows(myPatron))
            std::cout << "Patron owes a fee." << std::endl;
        Book anotherBook("123-456-789-A", "Another Title", "Another Author", "2024", Genre::NonFiction);
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