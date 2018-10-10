#include "Randomizer.hpp"
#include <algorithm>
#include <iostream>

Randomizer::Randomizer(std::string filename) {
    rom.open(filename, std::ios::in | std::ios::out | std::ios::binary);
    logfile.open("log.txt", std::ios::out );
}

Randomizer::~Randomizer() {
    rom.close();
    logfile.close();
}

bool Randomizer::verify_rom() {
    
    // allocate some space to read the title
    char title[0x15];
    
    // read the title from the ROM
    rom.seekg(0x20);
    rom.read(title,0x15);

    // if it matches, return true
    if (strcmp(title,"POKEMON STADIUM 2   ") == 0) {
        return true;
    }
    return false;


}

void Randomizer::randomize_pokemon(int cup, int count, bool randpoke) {

    for (int j = 0; j < count; j++ ) { 

        // if we are randomizing species, choose random species
        if (randpoke) {
            rom.seekg(cup + (SIZE_OF_POKEMON*j) + SPECIES);
            uint8_t species = (rand() % POKEMON_COUNT) + 1;
            rom.write((char*)&species,sizeof(species));
        }

        // go to pokemon's first move
        rom.seekg(cup + (SIZE_OF_POKEMON*j) + MOVE1);

        // for each move
        for (int i = 0; i < 4; i++) { 

            // banned moves
            uint8_t BannedMoves[] = {
                STRUGGLE,
                SONICBOOM,
                DRAGONRAGE,
            };

            // randomly pick a move and insert it
            uint8_t move = rand() % MOVES_COUNT + 1;

            // if a banned move is selected, pick another
            while (std::find(std::begin(BannedMoves),std::end(BannedMoves),move) != std::end(BannedMoves) ) {
                move = rand() % MOVES_COUNT + 1;
            }

            rom.write((char*)&move,sizeof(move));
        }

    } 
}

void Randomizer::randomize_rentals() {
    randomize_pokemon(LITTLE_CUP_RENTALS,LITTLE_CUP_COUNT);
    randomize_pokemon(POKE_CUP_RENTALS,POKE_CUP_COUNT);
    randomize_pokemon(PRIME_CUP_RENTALS,PRIME_CUP_COUNT);
}

void Randomizer::randomize_trainers() {
    /* LITTLE CUP */
    randomize_pokemon(LITTLE_CUP_BERNIE,PARTY_SIZE,true);
    randomize_pokemon(LITTLE_CUP_STACY,PARTY_SIZE,true);
    randomize_pokemon(LITTLE_CUP_GRANT,PARTY_SIZE,true);
    randomize_pokemon(LITTLE_CUP_JANET,PARTY_SIZE,true);
    randomize_pokemon(LITTLE_CUP_CLARK,PARTY_SIZE,true);
    randomize_pokemon(LITTLE_CUP_CORA,PARTY_SIZE,true);
    randomize_pokemon(LITTLE_CUP_TINA,PARTY_SIZE,true);
    randomize_pokemon(LITTLE_CUP_REX,PARTY_SIZE,true);

    // PokeCup, PokeBall
    randomize_pokemon(POKECUP_POKEBALL_BATTLE1,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_POKEBALL_BATTLE2,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_POKEBALL_BATTLE3,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_POKEBALL_BATTLE4,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_POKEBALL_BATTLE5,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_POKEBALL_BATTLE6,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_POKEBALL_BATTLES,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_POKEBALL_BATTLEF,PARTY_SIZE,true);

    // PokeCup, GreatBall
    randomize_pokemon(POKECUP_GREATBALL_BATTLE1,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_GREATBALL_BATTLE2,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_GREATBALL_BATTLE3,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_GREATBALL_BATTLE4,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_GREATBALL_BATTLE5,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_GREATBALL_BATTLE6,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_GREATBALL_BATTLES,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_GREATBALL_BATTLEF,PARTY_SIZE,true);

    // PokeCup, UltraBall
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE1,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE2,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE3,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE4,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE5,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE6,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLES,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLEF,PARTY_SIZE,true);

    // PokeCup, MasterBall
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE1,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE2,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE3,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE4,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE5,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLE6,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLES,PARTY_SIZE,true);
    randomize_pokemon(POKECUP_ULTRABALL_BATTLEF,PARTY_SIZE,true);

    // PrimeCup
    randomize_pokemon(PRIMECUP_BATTLE1,PARTY_SIZE,true);
    randomize_pokemon(PRIMECUP_BATTLE2,PARTY_SIZE,true);
    randomize_pokemon(PRIMECUP_BATTLE3,PARTY_SIZE,true);
    randomize_pokemon(PRIMECUP_BATTLE4,PARTY_SIZE,true);
    randomize_pokemon(PRIMECUP_BATTLE5,PARTY_SIZE,true);
    randomize_pokemon(PRIMECUP_BATTLE6,PARTY_SIZE,true);
    randomize_pokemon(PRIMECUP_BATTLES,PARTY_SIZE,true);
    randomize_pokemon(PRIMECUP_BATTLEF,PARTY_SIZE,true);
}

void Randomizer::dump_pokemon(int cup, int count) {
    // read and print level and species
    uint8_t level = 0;
    uint8_t species = 0;
    uint8_t item = 0;

    logfile << "------------------" << std::endl;

    // go to first LittleCup Pokemon
    for (int i = 0; i < count;  i++) {

        // seek to pokemon
        rom.seekg(cup + (SIZE_OF_POKEMON * i));

        // read level, species, and held item
        rom.read((char*)&level,sizeof(level));
        rom.read((char*)&species,sizeof(species));
        rom.read((char*)&item,sizeof(item));

        // write level and name
        logfile << "Level " << (int)level << " " 
            << (int)species << ":" << PokemonNames[species] 
            <<  " (" << ItemNames[item] << ")" << std::endl;
        
        // write out moveset
        rom.seekg(cup + (SIZE_OF_POKEMON * i) + MOVE1);
         logfile << "\t";
        for (int j = 0; j < 4; j++) {
            uint8_t move = 0;
            rom.read((char*)&move,sizeof(move));
            logfile << MoveName[move];
            if (j < 3) { logfile << " / "; }
        }
        logfile << std::endl;
    }
}

void Randomizer::dump_rentals() {
    dump_pokemon(LITTLE_CUP_RENTALS,LITTLE_CUP_COUNT);
    dump_pokemon(POKE_CUP_RENTALS,POKE_CUP_COUNT);
    dump_pokemon(PRIME_CUP_RENTALS,PRIME_CUP_COUNT);
}

void Randomizer::dump_trainers() {
    /* LITTLE CUP */
    dump_pokemon(LITTLE_CUP_BERNIE,PARTY_SIZE);
    dump_pokemon(LITTLE_CUP_STACY,PARTY_SIZE);
    dump_pokemon(LITTLE_CUP_GRANT,PARTY_SIZE);
    dump_pokemon(LITTLE_CUP_JANET,PARTY_SIZE);
    dump_pokemon(LITTLE_CUP_CLARK,PARTY_SIZE);
    dump_pokemon(LITTLE_CUP_CORA,PARTY_SIZE);
    dump_pokemon(LITTLE_CUP_TINA,PARTY_SIZE);
    dump_pokemon(LITTLE_CUP_REX,PARTY_SIZE);
}