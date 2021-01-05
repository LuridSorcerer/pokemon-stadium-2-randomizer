#include "Randomizer.hpp"

int main(int argc, char* argv[]) {
	
	Randomizer* r = new Randomizer("ps2.z64");
	if ( r->verify_rom() ) {
		puts("Good rom!");
		//r->dump_pokemon(LITTLE_CUP_RENTALS,LITTLE_CUP_COUNT);
		r->dump_trainers();
	} else {
		puts("Bad rom!");
	}
	
	return 0;
}
