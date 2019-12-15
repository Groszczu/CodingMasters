#pragma once


#include <unordered_map>
#include "Board.hpp"
#include "Position.hpp"
#include "PositionHash.hpp"


class MovesMap {
private:
    const Board& board_;
    std::unordered_map<Position, std::vector<std::vector<Position>>, PositionHash> movesMap_;
public:
    explicit MovesMap(const Board& board);

    std::vector<Position> getShortMoves(Position pos) const;
    std::vector<Position> getLongMoves(Position pos) const;
    std::optional<Position> getPosition(char c) const;

private:
    std::vector<Position> shortMove(int row, int column);
    std::vector<Position> longMove(int row, int column);
    char getValue(int row, int column);
    void pushBackValidMove(int row, int column, std::vector<Position>& validMoves);
};


