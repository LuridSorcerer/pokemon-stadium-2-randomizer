#include <fstream>
#include <iostream>
#include <vector>

#include "Randomizer.hpp"

int main(int argc, char* argv[]) {
	
	// create a vector for dynamically storing the pokemon names
	std::vector<std::string> pkmn_names;

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
			
			// done, close file
			romfile.close();
			
		}
	
	// don't bother if the rom doesn't match
	} else {
		puts("Bad rom!");
	}
	
	return 0;
}
