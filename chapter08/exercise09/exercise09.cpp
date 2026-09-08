/*
exercise 09
1. I would need to add inventory management for books.
what are their name, author, year of publication, ISBN and Genere?
2. I would need to add inventory management for patrons.
what are their name, ID and fees?
3. I would need to check if a patron can borrow a book.
what are the conditions for borrowing? (e.g., no outstanding fees, book is available)
4. I will also need to track of date when a book is borrowed and returned.

*/
#include "Book.h"
#include "Patron.h"
#include "Library.h"
#include "Date.h"
using namespace PPP_Lib;
template<typename T>
void add_items(Library& lib, const std::vector<T>& items) {
    for (const auto& item : items) {
        if constexpr (std::is_same_v<T, Book>) {
            lib.add_book(item);
        } else if constexpr (std::is_same_v<T, Patron>) {
            lib.add_patron(item);
        }
    }
}

void get_info_owning_fees(const Library& lib) {
    std::cout << "=======================\nPatrons owing fees:\n";
    for (const auto& patron : lib.patrons_owing_fees()) {
        std::cout << patron << "\n";
    }
}
int main(){
    try
    {
        Library lib;
        std::vector<Book> books{{"123-456-789-A", "My Title", "My Author", "2024", string_to_genre("Fiction")},
                                {"321-546-790-F", "The Great Gatsby", "F. Scott Fitzgerald", "1925", string_to_genre("Fiction")},
                                {"521-646-890-N", "The Book B", "Author J", "2025", string_to_genre("NonFiction")}};
        std::vector<Patron> patrons{{"John Doe"},
                                    {"Jane Smith"},
                                    {"Alice Johnson"}};
        add_items(lib, books);
        add_items(lib, patrons);
        // Example of checking out and checking in a book
        Date today{Year{2026}, Month::sep, 8};
        lib.check_out(books[0], patrons[0], today);
        lib.check_in(books[0], patrons[0], today);
        get_info_owning_fees(lib);
        lib.check_out(books[0], patrons[0], today);
        lib.check_out(books[1], patrons[0], today);
        lib.check_out(books[2], patrons[1], today);
        get_info_owning_fees(lib);
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }

}