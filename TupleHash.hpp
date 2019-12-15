#pragma once


#include <cstddef>
#include <tuple>
#include "Position.hpp"
#include "PositionHash.hpp"


struct TupleHash {
    std::size_t operator()(std::tuple<Position, bool, int> const &tuple) const noexcept {
        using std::size_t;
        using std::hash;
        using std::get;

        size_t h1 = PositionHash{}(get<0>(tuple));
        size_t h2 = hash<bool>{}(get<1>(tuple));
        size_t h3 = hash<int>{}(get<2>(tuple));

        return h1 ^ h2 ^ h3;
    }
};
