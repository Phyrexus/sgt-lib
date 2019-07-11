#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

namespace swngmtool
{
    // Psuedo-random number generator function
    inline std::mt19937& prng()
    {
        thread_local std::random_device rd;
        thread_local std::mt19937 mt(rd() );
        return mt;
    }
}

#endif // RANDOM_HPP
