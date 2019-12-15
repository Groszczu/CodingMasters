#include "UniqueSequencesCounter.hpp"


// plansza, po ktorej mozna sie poruszac
// znak '-' oznacza ze dane pole jest niedozwolone (krok nie moze sie na nim skonczyc)
const std::vector<std::vector<char>> UniqueSequencesCounter::board{
        {
                {'-', '-', '-', 'A', '-', '-', '-'},
                {'-', '-', 'B', 'C', 'D', '-', '-'},
                {'-', 'E', '-', 'F', 'G', 'H', '-'},
                {'I', 'J', 'K', 'L', 'M', '-', 'N'},
                {'-', 'O', 'P', '-', 'Q', 'R', '-'},
                {'-', '-', 'S', 'T', 'U', '-', '-'},
                {'-', '-', '-', 'V', '-', '-', '-'},
        }
};


