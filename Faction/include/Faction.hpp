#ifndef FACTION_HPP
#define FACTION_HPP

#include <cstddef>
#include <string>
#include <vector>

namespace sgt
{
    struct Asset
    {
        std::string name;
    };

    class Faction
    {
        public:
            Faction(std::string name);
            ~Faction();

            void AddAsset(Asset& asset);

            inline std::string GetName() const { return name_; }
            inline std::size_t GetAssetCount() const { return assetlist_.size(); }

        private:
            std::string name_;
            std::vector<Asset> assetlist_;
    };
}

#endif // FACTION_HPP
