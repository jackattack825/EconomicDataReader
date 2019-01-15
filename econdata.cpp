/*********************************************************************
** Program Filename: econdata.cpp
** Author: Jackson Perry
** Date: 1/11/19
** Description: Contains definitions for functions to be used in explore
*********************************************************************/

#include "econdata.hpp"
#include <iostream>

using namespace std;

/*********************************************************************
** Function: allocate_states
** Description: allocates an array of specified states
** Parameters: integer num of states
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
struct state* allocate_states(int num) {
	state* arr = new state[num];
	return arr;
}

/*********************************************************************
** Function: read_state_data
** Description: reads iostream and parses into given array of states
** Parameters: state array, int num of states, iostream pointer
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void read_state_data(struct state* st, int num, std::ifstream& file) {
	for (int i = 0; i < num; i++) {
		file >> st[i].name;
		file >> st[i].unemployed_2007;
		file >> st[i].unemployed_2015;
		file >> st[i].med_income;
		file >> st[i].n_counties;
		st[i].counties = allocate_counties(st[i].n_counties);
		read_county_data(st[i].counties, st[i].n_counties, file);
	}
}

/*********************************************************************
** Function: allocate_counties
** Description: allocates an array of specified counties
** Parameters: integer num of counties
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
struct county* allocate_counties(int num) {
	county* arr = new county[num];
	return arr;
}

/*********************************************************************
** Function: read_county_data
** Description: reads iostream and parses counties into given array
** Parameters: county array, in num of counties, iostream
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void read_county_data(struct county* ct, int num, std::ifstream& file) {
	for (int i = 0; i < num; i++) {
		file >> ct[i].name;
		file >> ct[i].unemployed_2007;
		file >> ct[i].unemployed_2015;
		file >> ct[i].med_income;
	}

}

/*********************************************************************
** Function: free_state_data
** Description: frees all allocated data
** Parameters: array of states, num states
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void free_state_data(struct state* arr, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < arr[i].n_counties; j++) {
			delete arr[i].counties;
		}
	}
	delete[] arr;

}