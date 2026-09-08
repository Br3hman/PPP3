/*
exercise 07
[7] Create an enumerated type for the Book class called Genre.
Have the types be fiction, nonfiction, periodical, biography, and children.
Give each book a Genre and make appropriate changes to the Book constructor
and member functions.
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

namespace PPP_Lib {
    enum class Genre{Fiction, NonFiction, Mystery, ScienceFiction, Biography};
    class Book {
    public:
        Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& copyright_date, Genre genre):
        isbn(isbn), title(title), author(author), copyright_date(copyright_date), checked_out(false), genre(genre) {
            if (!valid_isbn(isbn))
			throw std::runtime_error{"Invalid ISBN format"};
        };
        std::string get_isbn() const { return isbn; }; // Returns the ISBN of the book
        std::string get_title() const { return title; }; // Returns the title of the book
        std::string get_author() const { return author; }; // Returns the author of the book
        std::string get_copyright_date() const { return copyright_date; }; // Returns the copyright date of the book
        Genre get_genre() const { return genre; }; // Returns the genre of the book
        bool is_checked_out() const { return checked_out; }; // Returns true if the book is checked out, false otherwise
        void check_out(); // Marks the book as checked out
        void check_in(); // Marks the book as checked in
        static bool valid_isbn(const std::string& isbn_in);
    private:
        std::string isbn; // ISBN of the book: formate n−n−n−x, where n is an integer and x is a digit or a letter.
        std::string title;
        std::string author;
        std::string copyright_date;
        bool checked_out;
        Genre genre; // Genre of the book
    };

    inline std::string genre_to_string(Genre genre) {
        switch (genre) {
            case Genre::Fiction: return "Fiction";
            case Genre::NonFiction: return "NonFiction";
            case Genre::Mystery: return "Mystery";
            case Genre::ScienceFiction: return "ScienceFiction";
            case Genre::Biography: return "Biography";
        }
        return "Unknown"; // only reachable for a value cast in from outside the enum
    }

    inline Genre string_to_genre(const std::string& genre_str) {
        if (genre_str == "Fiction")        return Genre::Fiction;
        if (genre_str == "NonFiction")     return Genre::NonFiction;
        if (genre_str == "Mystery")        return Genre::Mystery;
        if (genre_str == "ScienceFiction") return Genre::ScienceFiction;
        if (genre_str == "Biography")      return Genre::Biography;
        throw std::runtime_error{"Unknown genre"};
    }

    inline bool operator==(const Book& lhs, const Book& rhs) {
        return lhs.get_isbn() == rhs.get_isbn();
    }

    inline bool operator!=(const Book& lhs, const Book& rhs) {
        return !(lhs == rhs);
    }

    inline std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Title: " << book.get_title() << "\n"
           << "Author: " << book.get_author() << "\n"
           << "ISBN: " << book.get_isbn() << "\n"
           << "Genre: " << genre_to_string(book.get_genre()) << "\n";
        return os;
    }
} // namespace PPP_Lib