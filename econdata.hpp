/*********************************************************************
** Program Filename: econdata.hpp
** Author: Jackson Perry
** Date: 1/11/19
** Description: Contains struct definitions and function prototypes to be used in explore
*********************************************************************/

struct county {
	std::string name;
	float unemployed_2007;
	float unemployed_2015;
	int med_income;
};

struct state {
	std::string name;
	float unemployed_2007;
	float unemployed_2015;
	int med_income;
	struct county* counties;
	int n_counties;
};

struct state* allocate_states(int);
void read_state_data(struct state*, int, std::ifstream&);
struct county* allocate_counties(int);
void read_county_data(struct county*, int, std::ifstream&);
void free_state_data(struct state*, int);