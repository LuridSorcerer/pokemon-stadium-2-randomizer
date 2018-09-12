#include <iostream>
#include <fstream>
#include <time.h>

#include "PokemonNames.hpp"
#include "Moves.hpp"
#include "Constants.hpp" 

using namespace std;

fstream rom;
fstream logfile;

void randomize_little_cup_rentals();
void dump_little_cup_rentals();

int main() {

    // open the ROM
    rom.open("rom.z64", ios::in | ios::out | ios::binary);
    if (!rom.is_open()) {
        cout << "Failed to open ROM" << endl;
        return 1;
    }

    // open log file
    logfile.open("log.txt", ios::out);
    if (!logfile.is_open()) {
        cout << "Failed to open log file" << endl;
        return 2;
    }

    randomize_little_cup_rentals();
    dump_little_cup_rentals();
    
    // close 
    rom.close();

    // exit
    return 0;
}

void randomize_little_cup_rentals() {

    // seed the random number generator
    srand(time(NULL));

    for (int j = 0; j < LITTLE_CUP_COUNT; j++ ) { 

        // go to pokemon
        rom.seekg(LITTLE_CUP_RENTALS + (SIZE_OF_POKEMON*j) + MOVE1);

        // for each move
        for (int i = 0; i < 4; i++) { 

            // randomly pick a move and insert it
            uint8_t move = (rand() % MOVES_COUNT) + 1;
            //rom << move;
            rom.write(&move,sizeof(move));
        }

    }
}

void dump_little_cup_rentals() {
    // read and print level and species
    uint8_t level = 0;
    uint8_t species = 0;

    logfile << "LITTLE CUP RENTALS" << endl
        << "------------------" << endl;

    // go to first LittleCup Pokemon
    // rom.seekg(LITTLE_CUP_RENTALS);
    for (int i = 0; i < LITTLE_CUP_COUNT;  i++) {

        // seek to pokemon
        rom.seekg(LITTLE_CUP_RENTALS + (SIZE_OF_POKEMON * i));

        // read level and species
        //rom >> level;
        //rom >> species;
        rom.read(&level,sizeof(level));
        rom.read(&species,sizeof(species));

        // write level and name
        logfile << "Level " << (int)level << " " 
            << (int)species << ":" << PokemonNames[species] <<  endl;
        
        // write out moveset
        rom.seekg(LITTLE_CUP_RENTALS + (SIZE_OF_POKEMON * i) + MOVE1);
        logfile << "\t";
        for (int j = 0; j < 4; j++) {
            uint8_t move = 0;
            //rom >> move;
            rom.read(&move,sizeof(move));
            logfile << Moves[move];
            if (j < 3) { logfile << " / "; }
        }
        logfile << endl;
    }
}