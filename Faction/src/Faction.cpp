#include "Faction.hpp"

namespace sgt
{
    Faction::Faction(std::string name)
        : name_(name)
    {
    }

    Faction::~Faction()
    {
    }

    void Faction::AddAsset(Asset& asset)
    {
        assetlist_.push_back(asset);
    }
}
