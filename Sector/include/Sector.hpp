#ifndef SECTOR_HPP
#define SECTOR_HPP

#include <string>
#include <vector>

#include "Hex.hpp"
#include "HexMap.hpp"

namespace sgt
{
    using uint = unsigned int;

    const uint STD_MAP_WIDTH = 8U;
    const uint STD_MAP_HEIGHT = 10U;
    const uint MIN_STAR_MOD = 20U;

    struct Planet
    {
        std::string name;
    };

    struct System
    {
        hexmap::Hex hex;
        std::string name;
        std::vector<Planet> planetlist;
    };

    class Sector
    {
        public:
            Sector(uint width = STD_MAP_WIDTH, uint height = STD_MAP_HEIGHT);
            ~Sector() = default;

            void GenerateSector(uint width, uint height);

            std::size_t GetMapSize() const;
            std::size_t GetSystemListSize() const;

        private:
            hexmap::hex_set sectormap_;
            std::vector<System> systemlist_;
    };
}

#endif // SECTOR_HPP
