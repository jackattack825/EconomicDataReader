CC=g++
EXE_FILE=explore_econdata.cpp

all: $(EXE_FILE)

$(EXE_FILE): econdata.o econdata.hpp explore_econdata.cpp
	$(CC) econdata.o explore_econdata.cpp -o $(EXE_FILE)

econdata.o: econdata.hpp econdata.cpp
	$(CC) -c econdata.cpp
clean:
	rm -f *.o $(EXE_FILE)

