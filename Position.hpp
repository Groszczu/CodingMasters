#pragma once

#include <cstddef>
#include <memory>


struct Position {
    int row;
    int column;

    Position(int row, int column) : row{row}, column{column} {}

    bool operator==(Position const &other) const {
        return row == other.row && column == other.column;
    }
};


