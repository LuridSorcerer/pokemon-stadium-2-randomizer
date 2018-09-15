#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <fstream>
using namespace std;

#include "PokemonNames.hpp"
#include "Moves.hpp"
#include "Constants.hpp" 

class Randomizer {
public:
    Randomizer(string filename);
    ~Randomizer();
    void randomize_rentals(int cup, int count);
    void dump_rentals(int cup, int count);
private:
    fstream rom;
    fstream logfile;
};

#endif