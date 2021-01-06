#include <fstream>
#include <iostream>
#include <vector>

#include "Randomizer.hpp"

int main(int argc, char* argv[]) {
	
	// create a vector for dynamically storing the pokemon names
	std::vector<std::string> pkmn_names;
	std::vector<std::string> item_names;
	std::vector<std::string> move_names;

	// create our randomizer object
	Randomizer* r = new Randomizer("ps2.z64");
	
	// verify the rom is good
	if ( r->verify_rom() ) {
		puts("Good rom!");
		
		// let's open up the file separately for some experiments...
		std::ifstream romfile ("ps2.z64");
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
			for (int i = 0; i <= 251; i++) {
				std::cout << i << ":" << pkmn_names[i] << '\n';
			}

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
			for (int i = 0; i < item_names.size(); i++) {
				std::cout << i << ":" << item_names[i] << "\n";
			}
			

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
			for (int i = 0; i < move_names.size(); i++) {
				std::cout << i << ":" << move_names[i] << "\n";
			}

			// done, close file
			romfile.close();
			
		}
	
	// don't bother if the rom doesn't match
	} else {
		puts("Bad rom!");
	}
	
	return 0;
}
