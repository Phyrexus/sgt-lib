#include "Hex.hpp"

#include <cmath>
#include <vector>

namespace hexmap
{
    const std::vector<Hex> hex_directions =
    {
        Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
        Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
    };

    constexpr bool operator==(const Hex& a, const Hex& b)
    {
        return a.q() == b.q() && a.r() == b.r() && a.s() == b.s();
    }

    constexpr bool operator!=(const Hex& a, const Hex& b)
    {
        return !(a==b);
    }

    Hex hex_add(const Hex& a, const Hex& b)
    {
        return Hex(a.q() + b.q(), a.r() + b.r(), a.s() + b.s() );
    }

    Hex hex_subtract(const Hex& a, const Hex& b)
    {
        return Hex(a.q() - b.q(), a.r() - b.r(), a.s() - b.s() );
    }

    Hex hex_multiply(const Hex& a, const Hex& b)
    {
        return Hex(a.q() * b.q(), a.r() * b.r(), a.s() * b.s() );
    }

    int hex_length(const Hex& hex)
    {
        return int((std::abs(hex.q() + std::abs(hex.r() + std::abs(hex.s() ) ) ) ) / 2);
    }

    int hex_distance(const Hex& a, const Hex& b)
    {
        return hex_length(hex_subtract(a, b) );
    }

    Hex hex_direction(int direction)
    {
        return hex_directions[direction];
    }

    Hex hex_neighbor(const Hex& hex, int direction)
    {
        return hex_add(hex, hex_direction(direction));
    }
}
