#include "HexMap.hpp"

#include <cmath>

namespace hexmap
{
    hex_set CreateFTRVMap(size_t width, size_t height)
    {
        hex_set hexmap;

        for(int q = 0; q < width; ++q)
        {
            int q_offset = std::floor( (q+1)/2);
            
            for(int r = -q_offset; r < int(height) - q_offset; ++r)
            {
                hexmap.insert(Hex(q, r, -q-r) );
            }
        }

        return hexmap;
    }
}
