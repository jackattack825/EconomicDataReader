/*********************************************************************
** Program Filename: econdata.hpp
** Author: Jackson Perry
** Date: 1/11/19
** Description: Contains struct definitions and function prototypes to be used in explore
*********************************************************************/
#include <fstream>
#include <iostream>

using namespace std;

struct county {
	string name;
	float unemployed_2007;
	float unemployed_2015;
	int med_income;
};

struct state {
	string name;
	float unemployed_2007;
	float unemployed_2015;
	int med_income;
	struct county* counties;
	int n_counties;
};

struct state* allocate_states(int);
void read_state_data(struct state*, int, ifstream&);
struct county* allocate_counties(int);
void read_county_data(struct county*, int, ifstream&);
void free_state_data(struct state*, int);
int explore_data(state*, int);
void print_highest_median(state*, int);
void print_lowest_median(state*, int);
void print_highest_2015(state*, int);
void print_lowest_2015(state*, int);
void sort_unemployment(state*, int);
void sort_median(state*, int);
void choose_state(state*, int);
void print_highest_median_county(county*, int);
void print_lowest_median_county(county*, int);
void print_highest_2015_county(county*, int);
void print_lowest_2015_county(county*, int);
void sort_unemployment_county(county*, int);
void sort_median_county(county*, int);