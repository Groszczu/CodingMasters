#include <numeric>
#include "UniqueSequencesCounter.hpp"


UniqueSequencesCounter::UniqueSequencesCounter(const MovesMap &movesMap) : movesMap_{movesMap} {
}


uint64_t UniqueSequencesCounter::calculate(char startChar, int steps) {
    auto startPosition = movesMap_.getPosition(startChar);
    uint64_t result{0};
    if (startPosition) {
        result = calculateUniqueSequencesCount(startPosition.value(), steps);
    }
    return result;
}


uint64_t UniqueSequencesCounter::calculateUniqueSequencesCount(Position startPosition, int steps, bool isShortMove) {
    auto params = std::make_tuple(startPosition, isShortMove, steps);
    if (calculatedResults_.find(params) != calculatedResults_.end()) {
        return calculatedResults_.at(params);
    }

    uint64_t result;
    auto validMoves{isShortMove ? movesMap_.getShortMoves(startPosition) : movesMap_.getLongMoves(startPosition)};
    if (steps == 1) {
        result = validMoves.size();
        calculatedResults_.insert({params, result});

        return result;
    }

    result = std::accumulate(std::begin(validMoves), std::end(validMoves), (uint64_t) 0,
                             [steps, isShortMove, this](uint64_t acc, auto pos) {
                                 return acc + calculateUniqueSequencesCount(pos, steps - 1, !isShortMove);
                             });

    calculatedResults_.insert({params, result});

    return result;
}

