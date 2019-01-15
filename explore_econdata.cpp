#include "econdata.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Missing filename.txt";
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

	explore_data(st, numStates);
	int ans = 1;
	while (ans = 1) {
		cout << "explore more data? if so type 1";
		cin >> ans;
		if (ans)
			explore_data(st, numStates);
	}
}
