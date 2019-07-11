#include "Sector.hpp"

#include "Random.hpp"

namespace swngmtool
{
    Sector::Sector(uint width, uint height)
    {
        this->GenerateSector(width, height);
    }

    void Sector::GenerateSector(uint width, uint height)
    {
        sectormap_ = hexmap::CreateFTRVMap(width, height);

        std::uniform_int_distribution<int> star_dist {MIN_STAR_MOD, MIN_STAR_MOD + 10};

        int total_stars = star_dist(prng() );

        for(int i = 0; i < total_stars; i++)
        {
            std::uniform_int_distribution<int> q_dist {0, int(width)};   
            int q = q_dist(prng() );
            
            int q_offset = std::floor( (q+1)/2);
            
            std::uniform_int_distribution<int> r_dist {-q_offset, int(height) - q_offset};
            int r = r_dist(prng() );

            auto hex = sectormap_.find(hexmap::Hex(q, r) );

            if(hex != sectormap_.end() )
            {
                systemlist_.push_back(System { *hex } );
            }
        }

        for(auto system : systemlist_)
        {
            std::uniform_int_distribution<int> planet_dist {1, 4};
            int planets = planet_dist(prng() );

            for(int i = 0; i < planets; i++)
            {
                system.planetlist_.push_back(Planet() );
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
