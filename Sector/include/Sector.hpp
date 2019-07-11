#ifndef SECTOR_HPP
#define SECTOR_HPP

#include <vector>

#include "Hex.hpp"
#include "HexMap.hpp"

namespace swngmtool
{
    using uint = unsigned int;

    const uint STD_MAP_WIDTH = 8U;
    const uint STD_MAP_HEIGHT = 10U;

    struct System
    {
        hexmap::Hex hex_;
    };

    class Sector
    {
        public:
            Sector(uint width = STD_MAP_WIDTH, uint height = STD_MAP_HEIGHT);
            ~Sector() = default;

            std::size_t GetMapSize() const;

        private:
            hexmap::hex_set sectormap_;
            std::vector<System> systemlist_;
    };
}

#endif // SECTOR_HPP
