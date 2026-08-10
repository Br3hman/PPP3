#pragma once
#include <stdexcept>
#include <string>
#include <sstream>

// Minimal PPP error utilities — no namespace pollution, no extra headers.
// From "Programming: Principles and Practice Using C++ (3rd ed.)" by Stroustrup.

namespace PPP {

    inline void error(const std::string& s)
    {
        throw std::runtime_error(s);
    }

    inline void error(const std::string& s, const std::string& s2)
    {
        throw std::runtime_error(s + s2);
    }

    inline void error(const std::string& s, int i)
    {
        std::ostringstream os;
        os << s << ": " << i;
        throw std::runtime_error(os.str());
    }

    // Alias used in some PPP exercises
    inline void simple_error(const std::string& s)
    {
        throw std::runtime_error(s);
    }

}
