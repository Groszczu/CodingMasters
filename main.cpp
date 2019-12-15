#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <chrono>


// plansza, po ktorej mozna sie poruszac
// znak '-' oznacza ze dane pole jest niedozwolone (krok nie moze sie na nim skonczyc)
std::vector<std::vector<char>> const board{
        std::vector{
                std::vector{'-', '-', '-', 'A', '-', '-', '-'},
                std::vector{'-', '-', 'B', 'C', 'D', '-', '-'},
                std::vector{'-', 'E', '-', 'F', 'G', 'H', '-'},
                std::vector{'I', 'J', 'K', 'L', 'M', '-', 'N'},
                std::vector{'-', 'O', 'P', '-', 'Q', 'R', '-'},
                std::vector{'-', '-', 'S', 'T', 'U', '-', '-'},
                std::vector{'-', '-', '-', 'V', '-', '-', '-'}
        }
};

// struktura przedstawiajaca punkt w dwuwymiarowym ukladzie wspolzednych
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

struct TupleHash {
    std::size_t operator()(std::tuple<Position, bool, int> const &tuple) const noexcept {
        std::size_t h1 = PositionHash{}(std::get<0>(tuple));
        std::size_t h2 = std::hash<bool>{}(std::get<1>(tuple));
        std::size_t h3 = std::hash<int>{}(std::get<2>(tuple));

        return h1 ^ h2 ^ h3;
    }
};

// mapa do przechowywania tablic pozycji, do ktorych mozna wykonac krotki krok, startujac z pocycji bedacej kluczem
std::unordered_map<Position, std::vector<Position>, PositionHash> short_moves_map;
// mapa do przechowywania tablic pozycji, do ktorych mozna wykonac dlugi krok, startujac z pocycji bedacej kluczem
std::unordered_map<Position, std::vector<Position>, PositionHash> long_moves_map;

// mapa przechowywujaca obliczone wyniki,
// w kluczu zapisywana jest pozycja startowa, flaga mowiaca o dlugosci kroku (true->krok krotki, false->krok dlugi)
// oraz liczba krokow pozostalych do wykonania jako std::tuple<Position, bool, int>
// wartosci mapy to liczba unikalnych ciagow znakow mozliwych do uzyskania dla danych parametrow
std::unordered_map<std::tuple<Position, bool, int>, uint64_t, TupleHash> calculated_results;

uint64_t get_result(char start_char, int steps);

Position get_position_of_char(char c);

uint64_t calculate_unique_sequences_count(Position start_position, int steps_left, bool is_short_move = false);

std::vector<Position> get_valid_moves(Position start_position, bool is_short_move);

std::vector<Position> get_all_moves(Position start_position, bool is_short_move);

bool is_out_of_board(Position pos);

bool is_empty_square(Position pos);

int main() {
    auto start_char{'L'};
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    auto result{get_result(start_char, 39)};
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << start_char << ": " << result << '\n';
    std::cout << "time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]";
    return 0;
}


uint64_t get_result(char start_char, int steps) {
    auto pos_of_char = get_position_of_char(start_char);
    return calculate_unique_sequences_count(pos_of_char, steps);
}

Position get_position_of_char(char c) {
    for (auto i = 0; i < board.size(); i++) {
        for (auto j = 0; j < board[0].size(); j++) {
            if (board[i][j] == c) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

uint64_t calculate_unique_sequences_count(Position start_position, int steps_left, bool is_short_move) {
    auto parameters = std::make_tuple(start_position, is_short_move, steps_left);
    // zwrocenie wartosci dla danych parametrow, jezeli zostala ona juz wczesniej wyliczona
    if (calculated_results.find(parameters) != calculated_results.end()) {
        return calculated_results.at(parameters);
    }

    uint64_t result;
    // jezeli pozostala liczba krokow jest rowna 1 zwrocona zosaje dlugosc tablicy z prawidlowymi krokami dla danych parametrow
    if (steps_left == 1) {
        result = get_valid_moves(start_position, is_short_move).size();
        calculated_results.insert({parameters, result});

        return result;
    }

    auto all_valid_moves{get_valid_moves(start_position, is_short_move)};
    result = std::accumulate(std::begin(all_valid_moves), std::end(all_valid_moves), (uint64_t) 0,
                             [steps_left, is_short_move](uint64_t acc, auto pos) {
                                 return acc + calculate_unique_sequences_count(pos, steps_left - 1, !is_short_move);
                             });

    calculated_results.insert({parameters, result});

    return result;
}

std::vector<Position> get_valid_moves(Position start_position, bool is_short_move) {
    // referencja do odpowiedniej mapy krokow
    auto &moves_map{is_short_move ? short_moves_map : long_moves_map};
    // sprawdzenie czy wyznaczono wczesniej prawidlowe kroki zaczynajace sie z danej pozycji
    if (moves_map.find(start_position) != moves_map.end()) {
        return moves_map.at(start_position);
    }

    auto all_valid_moves{get_all_moves(start_position, is_short_move)};

    // usuniecie z wszystkich krokow (get_all_moves), tych ktore sa poza plansza lub koncza sie na czarnym polu ('-')
    all_valid_moves.erase(
            std::remove_if(std::begin(all_valid_moves), std::end(all_valid_moves),
                           [](auto pos) {
                               return is_out_of_board(pos)
                                      || is_empty_square(pos);
                           }
            ), std::end(all_valid_moves)
    );

    // dodanie do mapy pary gdzie klucz jest pozycja poczatkowa a wartosc to wektor wyznaczonych krokow
    moves_map.insert({start_position, all_valid_moves});
    return all_valid_moves;
}

std::vector<Position> get_all_moves(Position start_position, bool is_short_move) {
    auto start_row = start_position.row;
    auto start_column = start_position.column;
    return {is_short_move ?
            std::vector<Position>{
                    // one step up, one left
                    {start_row - 1, start_column - 1},
                    // one step up, one right
                    {start_row - 1, start_column + 1},
                    // one step down, one left
                    {start_row + 1, start_column - 1},
                    // one step right, one right
                    {start_row + 1, start_column + 1},
            }
                          :
            std::vector<Position>{
                    // two steps up, one left
                    {start_row - 2, start_column - 1},
                    // two steps up, one right
                    {start_row - 2, start_column + 1},
                    // two steps right, one up
                    {start_row - 1, start_column + 2},
                    // two steps right, one down
                    {start_row + 1, start_column + 2},
                    // two steps down, one right
                    {start_row + 2, start_column + 1},
                    // two steps down, one left
                    {start_row + 2, start_column - 1},
                    // two steps left, one down
                    {start_row + 1, start_column - 2},
                    // two steps left, one up
                    {start_row - 1, start_column - 2},
            }};
}

bool is_out_of_board(Position pos) {
    return pos.row < 0
           || pos.row >= board.size()
           || pos.column < 0
           || pos.column >= board[pos.row].size();
}

bool is_empty_square(Position pos) {
    return board[pos.row][pos.column] == '-';
}
