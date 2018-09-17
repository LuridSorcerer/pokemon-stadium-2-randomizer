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
    void randomize_rentals(int cup, int count, bool randpoke=false);
    void dump_rentals(int cup, int count);
private:
    std::fstream rom;
    std::fstream logfile;
};

#endif