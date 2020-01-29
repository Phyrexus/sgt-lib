#include <catch2/catch.hpp>

#include "MapRegion.hpp"

using namespace sgt;

namespace tests
{
    TEST_CASE("MapRegionTests")
    {
        SECTION("Region generates")
        {
            MapRegion region;

            REQUIRE(region.GetMapSize() == STD_MAP_WIDTH * STD_MAP_HEIGHT);

            SECTION("Check generated region")
            {
                REQUIRE(region.GetHexListSize() > MIN_STAR_MOD);
                REQUIRE(region.GetHexListSize() <= STD_MAP_WIDTH * STD_MAP_HEIGHT);
            }
        }
    }
}
