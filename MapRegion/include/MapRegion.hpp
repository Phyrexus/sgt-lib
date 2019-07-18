#ifndef MAP_REGION_HPP
#define MAP_REGION_HPP

#include <cstddef>
#include <string>
#include <vector>

#include "Hex.hpp"
#include "HexMap.hpp"

namespace sgt
{
    using size_t = std::size_t;
    
    const size_t STD_MAP_WIDTH = 8;
    const size_t STD_MAP_HEIGHT = 10;
    const size_t MIN_STAR_MOD = 20;

    struct Feature
    {
    };

    struct Planet : public Feature
    {
        std::string name;
    };

    struct System
    {
        hexmap::Hex hex;
        std::vector<Feature> feature_list;
    };

    class MapRegion
    {
        public:
            MapRegion(size_t width = STD_MAP_WIDTH, size_t height = STD_MAP_HEIGHT);
            ~MapRegion();

            void GenerateRegion();
            void Clear();

            size_t GetMapSize() const;
            size_t GetSystemListSize() const;

        private:
            size_t width_, height_;
            hexmap::hex_set map_;
            std::vector<System> systemlist_;
    };
}

#endif // MAP_REGION_HPP
