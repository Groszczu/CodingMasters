#pragma once


#include <cstddef>
#include "Position.hpp"


struct PositionHash {
    std::size_t operator()(Position const &pos) const noexcept {
        using std::size_t;
        using std::hash;

        size_t h1 = hash<int>{}(pos.row);
        size_t h2 = hash<int>{}(pos.column);

        return h1 ^ (h2 << 1u);
    }
};