#ifndef FACTION_HPP
#define FACTION_HPP

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
            ~Faction() = default;

            inline std::string GetName() const { return name_; }

        private:
            std::string name_;
            std::vector<Asset> assetlist_;
    };
}

#endif // FACTION_HPP
