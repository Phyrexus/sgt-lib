#include "Sector.hpp"

#include <stdexcept>

#include "Random.hpp"

namespace sgt
{
    Sector::Sector(uint width, uint height)
    {
        this->GenerateSector(width, height);
    }

    void Sector::GenerateSector(uint width, uint height)
    {
        sectormap_ = hexmap::CreateFTRVMap(width, height);

        std::uniform_int_distribution<int> star_dist {MIN_STAR_MOD + 1, MIN_STAR_MOD + 11};

        int total_stars = star_dist(util::prng() );

        for(int i = 0; i < total_stars; i++)
        {
            std::uniform_int_distribution<int> q_dist {0, int(width) - 1};   
            int q = q_dist(util::prng() );
            
            int q_offset = std::floor( (q+1)/2);
            
            std::uniform_int_distribution<int> r_dist {-q_offset, int(height) - q_offset - 1};
            int r = r_dist(util::prng() );

            auto hex = sectormap_.find(hexmap::Hex(q, r, -q-r) );

            if(hex == sectormap_.end() )
            {
                // If the hex is not found, there's an issue with the random distributions
                throw new std::domain_error("Hex not in map");
            }
            
            systemlist_.push_back(System { *hex } );
        }

        for(auto system : systemlist_)
        {
            std::uniform_int_distribution<int> planet_dist {1, 4};
            int planets = planet_dist(util::prng() );

            for(int i = 0; i < planets; i++)
            {
                system.planetlist.push_back(Planet() );
            }
        }
    }

    std::size_t Sector::GetMapSize() const
    {
        return sectormap_.size();
    }

    std::size_t Sector::GetSystemListSize() const
    {
        return systemlist_.size();
    }
}
