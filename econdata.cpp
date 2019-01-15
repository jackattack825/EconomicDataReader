/*********************************************************************
** Program Filename: econdata.cpp
** Author: Jackson Perry
** Date: 1/11/19
** Description: Contains definitions for functions to be used in explore
*********************************************************************/

#include "econdata.hpp"
#include <iostream>
#include <algorithm>

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

/*********************************************************************
** Function: explore_data
** Description: allows user to explore the inputted data
** Parameters: array and # of states
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void explore_data(struct state* arr, int num) {
	cout << "Here are your options for further evaluation of the data.\n1. State with highest median household income.\n2. State with lowest median household income.\n3. State with highest unemployment in 2015.";
	cout << "\n4. State with the lowest unemployment in 2015.\n5. States in order by change in unemployment from 2007 to 2015.\n6. States in order of median hosuehold income.";
	cout << "\nYou can also select a state for doing the prvious operations on its counties. Type 7 in the slot to choose this option." >> endl;

	cout << "Now select an option" << endl;
	int x;
	cin >> x;

	switch (x) {
		case 1:
			print_highest_median(arr, num);
			break;
		case 2:
			print_lowest_median(arr, num);
			break;
		case 3:
			print_highest_2015(arr, num);
			break;
		case 4:
			print_lowest_2015(arr, num);
			break;
		case 5:
			sort_unemployment(arr, num);
			break;
		case 6:
			sort_median(arr, num);
			break;
		case 7:
			choose_state(arr, num);
			break;
	}
}

/*********************************************************************
** Function: print_highest_median
** Description: prints highest median household income from state
** Parameters: states and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void print_highest_median(state* arr, int num) {
	int med;
	string name;
	med = arr[0].med_income;
	for (int i = 0; i < num; i++) {
		if (arr[i].med_income > med) {
			med = arr[i].med_income;
			name = arr[i].name;
		}
	}
	cout << "State with the highest median household income is " << name << " with a value of " << med << endl;
}

/*********************************************************************
** Function: print_lowest_median
** Description: prints lowest median household income from state
** Parameters: states and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void print_lowest_median(state* arr, int num) {
	int med;
	string name;
	med = arr[0].med_income;
	for (int i = 0; i < num; i++) {
		if (arr[i].med_income < med) {
			med = arr[i].med_income;
			name = arr[i].name;
		}
	}
	cout << "State with the lowest median household income is " << name << " with a value of " << med << endl;
}

/*********************************************************************
** Function: print_highest_2015
** Description: prints highest unenmployment in 2015 from state
** Parameters: states and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void print_highest_2015(state* arr, int num) {
	int ue;
	string name;
	med = arr[0].unemployed_2015;
	for (int i = 0; i < num; i++) {
		if (arr[i].unemployed_2015 > med) {
			ue = arr[i].unemployed_2015;
			name = arr[i].name;
		}
	}
	cout << "State with the highest 2015 unemployment rate is " << name << " with a value of " << ue << endl;
}

/*********************************************************************
** Function: print_lowest_2015
** Description: prints lowst unenmployment in 2015 from state
** Parameters: states and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void print_lowest_2015(state* arr, int num) {
	int ue;
	string name;
	ue = arr[0].unemployed_2015;
	for (int i = 0; i < num; i++) {
		if (arr[i].unemployed_2015 < ue) {
			ue = arr[i].unemployed_2015;
			name = arr[i].name;
		}
	}
	cout << "State with the lowest 2015 unemployment rate is " << name << " with a value of " << ue << endl;
}

/*********************************************************************
** Function: sort_unemployent
** Description: prints states in order of change in unemployment
** Parameters: states and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void sort_unemployment(state* arr, int num) {
	float data[num];
	string names[num];
	for (int i = 0; i < num; i++) {
		data[i] = arr[i].unemployed_2015 - arr[i].unemployed_2007;
		names[i] = arr[i].name;
	}
	float temp;
	string temp1;
	for (int i = 0; i < num-1; i++) {
		if (data[i] > data[i + 1]) {
			temp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = temp;
			temp1 = names[i];
			names[i] = names[i + 1];
			names[i + 1] = temp1;
		}
	}

	cout << "Order of states by change in unemployment is: " << endl;
	for (int i = 0; i < num; i++) {
		cout << names[i] << " ";
	}
}

/*********************************************************************
** Function: sort_median
** Description: prints states in order of median hosuehold income
** Parameters: states and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void sort_median(state* arr, int num) {
	int data[num];
	string names[num];
	for (int i = 0; i < num; i++) {
		data[i] = arr[i].med_income;
		names[i] = arr[i].name;
	}
	int temp;
	string temp1;
	for (int i = 0; i < num - 1; i++) {
		if (data[i] > data[i + 1]) {
			temp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = temp;
			temp1 = names[i];
			names[i] = names[i + 1];
			names[i + 1] = temp1;
		}
	}

	cout << "Order of states by median hosuehold income is: " << endl;
	for (int i = 0; i < num; i++) {
		cout << names[i] << " ";
	}
}

/*********************************************************************
** Function: choose_state
** Description: sorting of different county stuff
** Parameters: states and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void choose_state(state* arr, int num) {
	int ans;
	cout << "Choose one of the following states by number:" << endl;
	for (int i = 0; i < num; i++) {
		cout << i << ". " << arr[i].name;
	}
	cin >> ans;
	cout << "Now choose the operation to perform.";

	switch (ans) {
	case 1:
		print_highest_median_county(arr[ans].counties, num);
		break;
	case 2:
		print_lowest_median_county(arr[ans].counties, num);
		break;
	case 3:
		print_highest_2015_county(arr[ans].counties, num);
		break;
	case 4:
		print_lowest_2015_county(arr[ans].counties, num);
		break;
	case 5:
		sort_unemployment_county(arr[ans].counties, num);
		break;
	case 6:
		sort_median_county(arr[ans].counties, num);
		break;
	}
}

/*********************************************************************
** Function: print_highest_median_county
** Description: prints highest median household income from county
** Parameters: county and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void print_highest_median_county(county* arr, int num) {
	int med;
	string name;
	med = arr[0].med_income;
	for (int i = 0; i < num; i++) {
		if (arr[i].med_income > med) {
			med = arr[i].med_income;
			name = arr[i].name;
		}
	}
	cout << "County with the highest median household income is " << name << " with a value of " << med << endl;
}

/*********************************************************************
** Function: print_lowest_median_county
** Description: prints lowest median household income from county
** Parameters: county and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void print_lowest_median(county* arr, int num) {
	int med;
	string name;
	med = arr[0].med_income;
	for (int i = 0; i < num; i++) {
		if (arr[i].med_income < med) {
			med = arr[i].med_income;
			name = arr[i].name;
		}
	}
	cout << "County with the lowest median household income is " << name << " with a value of " << med << endl;
}

/*********************************************************************
** Function: print_highest_2015_county
** Description: prints highest unenmployment in 2015 from county
** Parameters: county and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void print_highest_2015_county(county* arr, int num) {
	int ue;
	string name;
	med = arr[0].unemployed_2015;
	for (int i = 0; i < num; i++) {
		if (arr[i].unemployed_2015 > med) {
			ue = arr[i].unemployed_2015;
			name = arr[i].name;
		}
	}
	cout << "County with the highest 2015 unemployment rate is " << name << " with a value of " << ue << endl;
}

/*********************************************************************
** Function: print_lowest_2015_county
** Description: prints lowst unenmployment in 2015 from county
** Parameters: county and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void print_lowest_2015_county(county* arr, int num) {
	int ue;
	string name;
	ue = arr[0].unemployed_2015;
	for (int i = 0; i < num; i++) {
		if (arr[i].unemployed_2015 < ue) {
			ue = arr[i].unemployed_2015;
			name = arr[i].name;
		}
	}
	cout << "County with the lowest 2015 unemployment rate is " << name << " with a value of " << ue << endl;
}

/*********************************************************************
** Function: sort_unemployent_county
** Description: prints counties in order of change in unemployment
** Parameters: countys and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void sort_unemployment_county(county* arr, int num) {
	float data[num];
	string names[num];
	for (int i = 0; i < num; i++) {
		data[i] = arr[i].unemployed_2015 - arr[i].unemployed_2007;
		names[i] = arr[i].name;
	}
	float temp;
	string temp1;
	for (int i = 0; i < num - 1; i++) {
		if (data[i] > data[i + 1]) {
			temp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = temp;
			temp1 = names[i];
			names[i] = names[i + 1];
			names[i + 1] = temp1;
		}
	}

	cout << "Order of counties by change in unemployment is: " << endl;
	for (int i = 0; i < num; i++) {
		cout << names[i] << " ";
	}
}

/*********************************************************************
** Function: sort_median_county
** Description: prints counties in order of median hosuehold income
** Parameters: counties and num
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
void sort_median_county(county* arr, int num) {
	int data[num];
	string names[num];
	for (int i = 0; i < num; i++) {
		data[i] = arr[i].med_income;
		names[i] = arr[i].name;
	}
	int temp;
	string temp1;
	for (int i = 0; i < num - 1; i++) {
		if (data[i] > data[i + 1]) {
			temp = data[i];
			data[i] = data[i + 1];
			data[i + 1] = temp;
			temp1 = names[i];
			names[i] = names[i + 1];
			names[i + 1] = temp1;
		}
	}

	cout << "Order of counties by median hosuehold income is: " << endl;
	for (int i = 0; i < num; i++) {
		cout << names[i] << " ";
	}
}