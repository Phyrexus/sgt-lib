#include <string>

#include <catch2/catch.hpp>

#include "Faction.hpp"

using namespace sgt;

namespace tests
{
    TEST_CASE("FactionTests")
    {
        SECTION("Create faction")
        {
            std::string name("test");
            Faction faction(name);

            REQUIRE(faction.GetName() == name);
        }
    }
}
