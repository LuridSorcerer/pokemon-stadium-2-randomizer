CC = g++
SOURCE = Randomizer.cpp main.cpp
OBJ = Randomizer.o main.o
EXE = ps2rand
CXXFLAGS = `wx-config --cxxflags`
LIBS = `wx-config --libs`

all: $(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(LIBS)
%.o: %.cpp 
	$(CC) -c $(SOURCE) $(CXXFLAGS) 

clean:
	rm -rf $(OBJ) $(EXE)