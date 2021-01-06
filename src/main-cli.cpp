#include <fstream>
#include <iostream>
#include <vector>

#include "Randomizer.hpp"

// create a vector for dynamically storing the pokemon names
std::vector<std::string> pkmn_names;
std::vector<std::string> item_names;
std::vector<std::string> move_names;

std::ifstream romfile;

void dump_trainer(int offset) {
	unsigned char * buffer = new unsigned char[24];
	romfile.seekg(offset);
	for (int i = 0; i < 6; i++) {
	romfile.read((char*)buffer,24);
		std::cout << "Lv" << (int)buffer[0] << ":" 
			<< pkmn_names[(int)buffer[1]] << ":" 
			<< item_names[(int)buffer[2]] << ":" 
			<< move_names[(int)buffer[4]] << "/" 
			<< move_names[(int)buffer[5]] << "/" 
			<< move_names[(int)buffer[6]] << "/" 
			<< move_names[(int)buffer[7]] << '\n';

	}
	std::cout << '\n';
	delete[] buffer;	
}

int main(int argc, char* argv[]) {
	
	// create our randomizer object
	Randomizer* r = new Randomizer("ps2.z64");
	
	// verify the rom is good
	if ( r->verify_rom() ) {
		puts("Good rom!");
		
		// let's open up the file separately for some experiments...
		romfile.open("ps2.z64");
		if (romfile.is_open() ) {
			puts("file is open");
			
			// seek to where the names are stored
			romfile.seekg(0x1D718B8);
			
			// some buffer space for a name
			char name[20];
			
			// we want the pokemon names to start at 1, fill position 0
			pkmn_names.push_back("MissingNo.");

			// read a few names
			for (int i = 0; i <= 251; i++) {
				// read as cstr
				romfile.getline(name,20,'\0');
				// push on to the vector
				pkmn_names.push_back(name);
			}
			
			// write the stored names back out
			/*
			for (int i = 0; i <= 251; i++) {
				std::cout << i << ":" << pkmn_names[i] << '\n';
			}
			*/

			// seek to where the item names are stored
			romfile.seekg(0x1D870BC);

			// want the items to start at 1, so fill in position 0
			item_names.push_back("No item");

			// read the names
			for (int i = 0x0; i < 0xF9; i++) {
				// read a cstr
				romfile.getline(name,20,'\0');
				// push on to the vector
				item_names.push_back(name);
			}

			// print out the names
			/*
			for (int i = 0; i < item_names.size(); i++) {
				std::cout << i << ":" << item_names[i] << "\n";
			}
			*/
			

			// seek to where the move names are stored
			romfile.seekg(0x1D80DA0);

			// want to start at position 1, so fill position 0
			move_names.push_back("-");

			// read the names
			for (int i = 0; i < 251; i++) { 
				// read a cstr
				romfile.getline(name,20,'\0');
				// push onto the vector
				move_names.push_back(name);
			}

			// print out the move names
			/*
			for (int i = 0; i < move_names.size(); i++) {
				std::cout << i << ":" << move_names[i] << "\n";
			}
			*/
			
			// trainer classes
			romfile.seekg(0x1D9535C);

			// trainer names
			romfile.seekg(0x1D9570C); 

			// Camper Cole's pokemon
			std::cout << "Camper Cole\n";
			dump_trainer(0x1716C04);

			// Player vs. Camper Cole
			std::cout << "vs. Camper Cole\n";
			dump_trainer(0x1716B6C);

			// Super Nerd Melvin
			std::cout << "Super Nerd Melvin\n"; 
			dump_trainer(0x1716D34);

			// Player vs Super Nerd Melvin
			std::cout << "vs. Super Nerd Melvin\n";
			dump_trainer(0x1716C9C);

			// Player vs Swimmer Clayton
			std::cout << "vs. Swimmer Clayton\n";
			dump_trainer(0x1716EFC);

			// Player vs Schoolboy Carson
			std::cout << "vs. Schoolboy Carson\n";
			dump_trainer(0x1716DCC);

			// done, close file
			romfile.close();

		}
	
	// don't bother if the rom doesn't match
	} else {
		puts("Bad rom!");
	}
	
	return 0;
}
