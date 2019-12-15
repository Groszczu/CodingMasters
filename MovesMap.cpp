#include "MovesMap.hpp"


MovesMap::MovesMap(Board const &board) : board_{board} {
    auto rowCount{board_.size()};
    for (auto row{0}; row < rowCount; row++) {
        auto columnCount{board_.at(row).size()};
        for (auto column{0}; column < columnCount; column++) {
            auto validShortMoves = shortMove(row, column);
            auto validLongMoves = longMove(row, column);
            movesMap_.insert({Position(row, column), {validShortMoves, validLongMoves}});
        }
    }
}

std::vector<Position> MovesMap::shortMove(int row, int column) {
    std::vector<Position> validMoves;

    pushBackValidMove(row + 1, column + 1, validMoves);
    pushBackValidMove(row - 1, column + 1, validMoves);
    pushBackValidMove(row + 1, column - 1, validMoves);
    pushBackValidMove(row - 1, column - 1, validMoves);

    return validMoves;
}

std::vector<Position> MovesMap::longMove(int row, int column) {
    std::vector<Position> validMoves;

    pushBackValidMove(row - 2, column - 1, validMoves);
    pushBackValidMove(row - 2, column + 1, validMoves);
    pushBackValidMove(row - 1, column + 2, validMoves);
    pushBackValidMove(row + 1, column + 2, validMoves);
    pushBackValidMove(row + 2, column + 1, validMoves);
    pushBackValidMove(row + 2, column - 1, validMoves);
    pushBackValidMove(row + 1, column - 2, validMoves);
    pushBackValidMove(row - 1, column - 2, validMoves);

    return validMoves;
}

char MovesMap::getValue(int row, int column) {
    if (row >= 0 && row < board_.size()) {
        auto rowVector{board_.at(row)};
        if (column >= 0 && column < rowVector.size()) {
            auto value{rowVector.at(column)};
            return value;
        }
    }

    return EMPTY_CELL;
}

void MovesMap::pushBackValidMove(int row, int column, std::vector<Position>& validMoves) {
    auto value{getValue(row, column)};
    if (value != EMPTY_CELL) {
        validMoves.emplace_back(Position(row, column));
    }
}

std::optional<Position> MovesMap::getPosition(char c) const {
    auto rowCount{board_.size()};
    for (auto row = 0; row < rowCount; row++) {
        auto columnCount{board_.at(row).size()};
        for (auto column = 0; column < columnCount; column++) {
            if (board_.at(row).at(column) == c) {
                return Position(row, column);
            }
        }
    }

    return {};
}

std::vector <Position> MovesMap::getShortMoves(Position pos) const {
    return movesMap_.at(pos).at(0);
}

std::vector <Position> MovesMap::getLongMoves(Position pos) const {
    return movesMap_.at(pos).at(1);
}
