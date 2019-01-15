#include "econdata.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Missing filename.txt"
		exit(0);
	}

	ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile) {
		cerr << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	int numStates;
	file >> numStates;
	state* st = allocate_states(numStates);
	read_state_data(st, numStates, file);

}