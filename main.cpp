#include <iostream>
#include <iterator>
#include <string>
#include "Board.hpp"
#include "MovesMap.hpp"
#include "UniqueSequencesCounter.hpp"


int main() {
    std::cout << "Enter start character (uppercase):" << '\n';
    std::string inputChar;
    std::cin >> inputChar;

    std::cout << "Enter number of steps:" << '\n';
    std::string inputSteps;
    std::cin >> inputSteps;
    auto startChar{inputChar.at(0)};
    int steps{std::stoi(inputSteps)};

    auto movesMap{ MovesMap(BOARD) };
    auto calculator{ UniqueSequencesCounter(movesMap) };

    auto result{calculator.calculate(startChar, steps)};
    std::cout << "result" << ": " << result << '\n';
    return 0;
}
