#include <catch2/catch.hpp>

#include "Sector.hpp"

using namespace swngmtool;

namespace tests
{
    TEST_CASE("SectorTests")
    {
        SECTION("Sector generates")
        {
            swngmtool::Sector sector;

            REQUIRE(sector.GetMapSize() == STD_MAP_WIDTH * STD_MAP_HEIGHT);

            SECTION("Check generated sector")
            {
                //REQUIRE(sector.GetSystemListSize() > MIN_STAR_MOD);
                REQUIRE(sector.GetSystemListSize() <= STD_MAP_WIDTH * STD_MAP_HEIGHT);
            }
        }
    }
}
