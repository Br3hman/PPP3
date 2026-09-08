#include "Library.h"
namespace PPP_Lib {

bool Library::book_exists(const Book& b) const{
    if(bk.size()>0)
        for (auto bk_en:bk)
            if (bk_en.get_isbn()==b.get_isbn())
                return true;

    return false;
}

bool Library::patron_exists(const Patron& p) const {
    if (pt.size()>0)
        for(auto p_en:pt)
            if (p_en.card_num() == p.card_num())
                return true;
    return false;
}

void Library::verify_patron(const Patron& p) const {
    if (!(patron_exists(p)))
        throw std::runtime_error("Patron does not exist");
}

void Library::verify_book(const Book& b) const {
    //verify if book exists in the library to throw error if it doesn't
    if (!(book_exists(b)))
        throw std::runtime_error("Book does not exist");
}

void Library::add_book(const Book& b) {
    if (book_exists(b))
        throw std::runtime_error("Book already exist");
    bk.push_back(b);
}


void Library::add_patron(const Patron& p) {
    if (patron_exists(p))
        throw std::runtime_error("Patron already exist");
    pt.push_back(p);
}

Patron& Library::find_patron(const Patron& p) {
    for (auto& p_en:pt)
        if (p_en.card_num() == p.card_num())
            return p_en;
    throw std::runtime_error("Patron not found");
}
void Library::check_out(const Book& b, const Patron& p, const Date& d) {
    //Whenever a user checks out a book, have the library make sure that both the user and the book are in the library.
    verify_patron(p);
    verify_book(b);
    //Then check to make sure that the user owes no fees.
    if(owes(p))
        throw std::runtime_error("Patron owes fees");
    find_patron(p).add_fee(10); // Ensure the patron's fee is up-to-date before checking out
    /* Testing internal states
    std::cout << "Checking out book: " << b << " to patron: " << p << " on date: " << d << "\n";
    std::cout<<"Patron current fee: " << find_patron(p).get_fee() << "\n";
     //*/
    tr.emplace_back(Transaction{b, p, d, Transaction::Action::check_out});
}

void Library::check_in(const Book& b, const Patron& p, const Date& d) {
    verify_patron(p);
    verify_book(b);
    //Then check to make sure that the user owes no fees.
    if(owes(p))
        throw std::runtime_error("Patron owes fees");

    int fee = find_patron(p).get_fee();
    if(fee-10 < 0)
        find_patron(p).set_fee(0);
    else
        find_patron(p).set_fee(fee-10); // Ensure the patron's fee is up-to-date before checking in

    //emplace_back create a new object and add to the vector
    tr.emplace_back(Transaction{b, p, d, Transaction::Action::check_in});
}

std::vector<Patron> Library::patrons_owing_fees() const {
    std::vector<Patron> owing;
    for (auto p:pt)
        if (owes(p))
            owing.push_back(p);
    return owing;
}
void Library::print_library(std::ostream& os) const {
    os << "Books in library:\n";
    for (const auto& book : bk) {
        os << book << "\n";
    }
    os << "Patrons in library:\n";
    for (const auto& patron : pt) {
        os << patron << "\n";
    }
    os << "Patrons owing fees:\n";
    for (const auto& patron : patrons_owing_fees()) {
        os << patron << "\n";
    }

}

} // namespace PPP_Lib