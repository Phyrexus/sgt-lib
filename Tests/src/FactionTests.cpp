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

        SECTION("Add asset to faction")
        {
            Faction faction("test");
            Asset asset { "test" };

            faction.AddAsset(asset);

            REQUIRE(faction.GetAssetCount() == 1);
        }

        SECTION("Add large amounts of assets to a faction")
        {
            Faction faction("Test");
            Asset asset { "Test" };

            for(int i = 0; i < 1000; ++i)
            {
                faction.AddAsset(asset);
            }
        }
    }
}
