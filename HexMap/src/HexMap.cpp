#include "HexMap.hpp"

#include <cmath>

namespace hexmap
{
    hex_set CreateFTRVMap(uint width, uint height)
    {
        hex_set hexmap;

        for(int q = 0; q < width; ++q)
        {
            int q_offset = std::floor( (q+1)/2);
            
            for(int r = -q_offset; r < height - q_offset; ++r)
            {
                hexmap.insert(Hex(q, r, -q-r) );
            }
        }

        return hexmap;
    }
}
