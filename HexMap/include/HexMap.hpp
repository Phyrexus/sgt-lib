#ifndef HEX_MAP_HPP
#define HEX_MAP_HPP

#include <unordered_set>

#include "Hex.hpp"

namespace hexmap
{
    using hex_set = std::unordered_set<Hex>;

    // Create flat-topped, rectangular, vertical hex map
    hex_set CreateFTRVMap(int width, int height);
}

#endif
