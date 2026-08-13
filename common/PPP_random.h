#pragma once
#include <random>

namespace PPP {

    inline std::default_random_engine& get_rand()
    {
        static std::default_random_engine ran;
        return ran;
    }

    inline void seed(int s) { get_rand().seed(s); }
    inline void seed()      { get_rand().seed(); }

    inline int random_int(int min, int max) { return std::uniform_int_distribution<>{min, max}(get_rand()); }
    inline int random_int(int max)          { return random_int(0, max); }

} // namespace PPP
