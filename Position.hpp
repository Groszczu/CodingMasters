#pragma once

#include <cstddef>
#include <memory>


struct Position {
    int row;
    int column;

    bool operator==(Position const &other) const {
        return row == other.row && column == other.column;
    }
};

struct PositionHash {
    std::size_t operator()(Position const &pos) const noexcept {
        std::size_t h1 = std::hash<int>{}(pos.row);
        std::size_t h2 = std::hash<int>{}(pos.column);

        return h1 ^ (h2 << 1u);
    }
};
