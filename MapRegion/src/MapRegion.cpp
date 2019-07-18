#include "MapRegion.hpp"

#include <stdexcept>

#include "Random.hpp"

namespace sgt
{
    MapRegion::MapRegion(size_t width, size_t height)
        : width_(width), height_(height)
    {
        this->GenerateRegion();
    }

    MapRegion::~MapRegion()
    {
    }

    void MapRegion::GenerateRegion()
    {
        map_ = hexmap::CreateFTRVMap(width_, height_);

        std::uniform_int_distribution<int> star_dist {MIN_STAR_MOD + 1, MIN_STAR_MOD + 11};

        int total_stars = star_dist(util::prng() );

        for(int i = 0; i < total_stars; i++)
        {
            std::uniform_int_distribution<int> q_dist {0, int(width_) - 1};   
            int q = q_dist(util::prng() );
            
            int q_offset = std::floor( (q+1)/2);
            
            std::uniform_int_distribution<int> r_dist {-q_offset, int(height_) - q_offset - 1};
            int r = r_dist(util::prng() );

            auto hex = map_.find(hexmap::Hex(q, r, -q-r) );

            if(hex == map_.end() )
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
                system.feature_list.push_back(Planet() );
            }
        }
    }

    void MapRegion::Clear()
    {
        width_ = height_ = 0;
        map_.clear();
    }

    std::size_t MapRegion::GetMapSize() const
    {
        return map_.size();
    }

    std::size_t MapRegion::GetSystemListSize() const
    {
        return systemlist_.size();
    }
}
