#ifndef MAP_REGION_HPP
#define MAP_REGION_HPP

#include <cstddef>
#include <string>
#include <vector>

#include "Hex.hpp"
#include "HexMap.hpp"

namespace sgt
{
    const int STD_MAP_WIDTH = 8;
    const int STD_MAP_HEIGHT = 10;
    const int MIN_STAR_MOD = 20;

    struct Feature
    {
        std::string name;
    };

    struct MapHex
    {
        hexmap::Hex hex;
        std::vector<Feature> feature_list;
    };

    class MapRegion
    {
        public:
            MapRegion(int width = STD_MAP_WIDTH, int height = STD_MAP_HEIGHT);
            ~MapRegion();

            void GenerateRegion();
            void Clear();

            std::size_t GetMapSize() const;
            std::size_t GetHexListSize() const;

        private:
            int width_, height_;
            hexmap::hex_set map_;
            std::vector<MapHex> hexes_;
    };
}

#endif // MAP_REGION_HPP
