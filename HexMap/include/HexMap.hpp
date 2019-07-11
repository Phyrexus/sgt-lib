#ifndef HEX_MAP_HPP
#define HEX_MAP_HPP

#include <unordered_set>

#include "Hex.hpp"

namespace hexmap
{
    using uint = unsigned int;
    using hex_set = std::unordered_set<Hex>;

    hex_set CreateFTRVMap(uint width, uint height);
}

#endif
