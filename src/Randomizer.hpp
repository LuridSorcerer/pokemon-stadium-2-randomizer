#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <fstream>
#include <ctime>
#include <string>

#include "PokemonNames.hpp"
#include "Moves.hpp"
#include "Items.hpp"
#include "Constants.hpp" 

class Randomizer {
public:
    Randomizer(std::string filename);
    ~Randomizer();
    bool verify_rom();
    void randomize_pokemon(int offset, int count, bool randpoke=false, bool bannedMoves=false);
    void randomize_rentals(bool bannedMoves);
    void randomize_trainers(bool bannedMoves);
    void dump_pokemon(int offset, int count);
    void dump_rentals();
    void dump_trainers();
private:
    std::fstream rom;
    std::fstream logfile;
};

#endif