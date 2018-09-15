#include "Randomizer.hpp"

#include <ctime>

Randomizer::Randomizer(string filename) {
    rom.open(filename, ios::in | ios::out | ios::binary);
    logfile.open("log.txt", ios::out );
}

Randomizer::~Randomizer() {
    rom.close();
    logfile.close();
}

void Randomizer::randomize_rentals(int cup, int count) {

    // seed the random number generator
    srand(time(NULL));

    for (int j = 0; j < count; j++ ) { 

        // go to pokemon
        rom.seekg(cup + (SIZE_OF_POKEMON*j) + MOVE1);

        // for each move
        for (int i = 0; i < 4; i++) { 

            // randomly pick a move and insert it
            uint8_t move = (rand() % MOVES_COUNT) + 1;
            rom.write((char*)&move,sizeof(move));
        }

    }
}

void Randomizer::dump_rentals(int cup, int count) {
    // read and print level and species
    uint8_t level = 0;
    uint8_t species = 0;

    logfile << "------------------" << endl;

    // go to first LittleCup Pokemon
    for (int i = 0; i < count;  i++) {

        // seek to pokemon
        rom.seekg(cup + (SIZE_OF_POKEMON * i));

        // read level and species
        rom.read((char*)&level,sizeof(level));
        rom.read((char*)&species,sizeof(species));

        // write level and name
        logfile << "Level " << (int)level << " " 
            << (int)species << ":" << PokemonNames[species] <<  endl;
        
        // write out moveset
        rom.seekg(cup + (SIZE_OF_POKEMON * i) + MOVE1);
         logfile << "\t";
        for (int j = 0; j < 4; j++) {
            uint8_t move = 0;
            rom.read((char*)&move,sizeof(move));
            logfile << Moves[move];
            if (j < 3) { logfile << " / "; }
        }
        logfile << endl;
    }
}