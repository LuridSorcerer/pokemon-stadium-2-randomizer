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
    void randomize_pokemon(int offset, int count, bool randpoke=false);
    void randomize_rentals();
    void randomize_trainers();
    void dump_pokemon(int offset, int count);
    void dump_rentals();
    void dump_trainers();
private:
    std::fstream rom;
    std::fstream logfile;
};

#endif