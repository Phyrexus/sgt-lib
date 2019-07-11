#include <catch2/catch.hpp>

#include "Sector.hpp"

namespace tests
{
    TEST_CASE("SectorTests")
    {
        SECTION("Sector generates")
        {
            swngmtool::Sector sector;

            REQUIRE(sector.GetMapSize() > 0);
        }
    }
}
