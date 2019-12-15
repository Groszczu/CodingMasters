#pragma once


#include <vector>
#include "MovesMap.hpp"
#include "TupleHash.hpp"

class UniqueSequencesCounter {
    using parameters = std::tuple<Position, bool, int>;
private:
    const MovesMap& movesMap_;
    std::unordered_map<parameters , uint64_t, TupleHash> calculatedResults_;

public:
    explicit UniqueSequencesCounter(const MovesMap& movesMap);
    uint64_t calculate(char startChar, int steps);

private:
    uint64_t calculateUniqueSequencesCount(Position startPosition, int steps, bool isShortMove = false);
};


