CC=g++
EXE_FILE=explore

$(EXE_FILE): econdata.hpp explore_econdata.cpp econdata.cpp
	$(CC) econdata.cpp explore_econdata.cpp -o $(EXE_FILE)
