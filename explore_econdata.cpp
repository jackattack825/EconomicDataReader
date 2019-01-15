#include "econdata.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Missing filename.txt" << endl;
		exit(0);
	}

	ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile) {
		cerr << "Unable to open file " << argv[1] << endl;
		exit(0);
	}

	int numStates;
	inFile >> numStates;
	state* st = allocate_states(numStates);
	read_state_data(st, numStates, inFile);

	cout << "Sucessfully read file. Now select a menu option for further evaluation of the data inputted" << endl;
	int ans;
	do {
		ans= explore_data(st, numStates);
	} while (ans);
	
	
	free_state_data(st, numStates);
}
