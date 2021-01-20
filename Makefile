CC = g++
HEADERS = src/Constants.hpp src/Items.hpp src/LittleCup.hpp src/Moves.hpp src/PokeCup.hpp src/PokemonNames.hpp src/PrimeCup.hpp src/Randomizer.hpp
EXE = bin/ps2rand
CXXFLAGS = `wx-config --cxxflags`
LIBS = `wx-config --libs`

all: $(EXE)

$(EXE): obj/main.o
	$(CC) -o $(EXE) obj/main.o obj/Randomizer.o $(LIBS)
	
obj/main.o: src/main.cpp obj/Randomizer.o
	$(CC) -c $< -o $@ $(CXXFLAGS)
	
obj/Randomizer.o : src/Randomizer.cpp $(HEADERS)
	$(CC) -c $< -o $@

clean:
	rm -rf obj/*.o $(EXE)
