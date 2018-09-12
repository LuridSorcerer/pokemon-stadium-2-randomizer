CC = g++
SOURCE = main.cpp
OBJ = main.o
EXE = ps2rand

all: $(OBJ)
	$(CC) -o $(EXE) $(OBJ)
%.o: %.cpp 
	$(CC) -c main.cpp -fpermissive

clean:
	rm -rf $(OBJ) $(EXE)