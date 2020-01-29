#include "Random.hpp"

namespace util
{
    std::mt19937& prng()
    {
        thread_local std::random_device rd;
        thread_local std::mt19937 mt(rd() );
        return mt;
    }
}
