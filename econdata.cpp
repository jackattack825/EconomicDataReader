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


}

/*********************************************************************
** Function: read_state_data
** Description: reads iostream and parses into given array of states
** Parameters: state array, int num of states, iostream pointer
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void read_state_data(struct state* st, int num, std::ifstream& file) {


}

/*********************************************************************
** Function: allocate_counties
** Description: allocates an array of specified counties
** Parameters: integer num of counties
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
struct county* allocate_counties(int num) {


}

/*********************************************************************
** Function: read_county_data
** Description: reads iostream and parses counties into given array
** Parameters: county array, in num of counties, iostream
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void read_county_data(struct county* ct, int num, std::ifstream& file) {


}

/*********************************************************************
** Function: free_state_data
** Description: frees all allocated data
** Parameters: array of states, num states
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void free_state_data(struct state* arr, int num) {


}