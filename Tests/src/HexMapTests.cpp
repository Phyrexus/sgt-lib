#include <catch2/catch.hpp>

#include "HexMap.hpp"

using namespace hexmap;

namespace tests
{
    TEST_CASE("HexMapTests")
    {
        const int MAP_WIDTH = 8;
        const int MAP_HEIGHT = 10;

        SECTION("Create HexMap")
        {
            hex_set map = CreateFTRVMap(MAP_WIDTH, MAP_HEIGHT);

            REQUIRE(map.size() == 80);
        }
    }
}
