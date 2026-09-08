#include "Book.h"
using namespace Book_Library;

int main() {
    // 1. invalid genre string
    try {
        Book b("123-456-789-A", "T", "A", "2024", string_to_genre("Horror"));
        std::cout << "constructed OK (unexpected)\n";
    } catch (const std::exception& e) {
        std::cout << "[1] caught: " << e.what() << '\n';
    }

    // 2. wrong case
    try {
        Book b("123-456-789-A", "T", "A", "2024", string_to_genre("fiction"));
        std::cout << "constructed OK (unexpected)\n";
    } catch (const std::exception& e) {
        std::cout << "[2] caught: " << e.what() << '\n';
    }

    // 3. bad ISBN *and* bad genre - which error wins?
    try {
        Book b("nonsense", "T", "A", "2024", string_to_genre("Horror"));
        std::cout << "constructed OK (unexpected)\n";
    } catch (const std::exception& e) {
        std::cout << "[3] caught: " << e.what() << '\n';
    }

    // 4. out-of-range Genre forced past the enum
    Genre bogus = static_cast<Genre>(99);
    std::cout << "[4] genre_to_string(99) = " << genre_to_string(bogus) << '\n';
}
