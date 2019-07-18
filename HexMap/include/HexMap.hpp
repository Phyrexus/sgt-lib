#ifndef HEX_MAP_HPP
#define HEX_MAP_HPP

#include <cstddef>
#include <unordered_set>

#include "Hex.hpp"

namespace hexmap
{
    using hex_set = std::unordered_set<Hex>;
    using size_t = std::size_t;

    // Create flat-topped, rectangular, vertical hex map
    hex_set CreateFTRVMap(size_t width, size_t height);
}

#endif
