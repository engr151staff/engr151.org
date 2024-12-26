#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void read_info(int & rows, int & cols, vector< vector<int> > & parking_lot,
		vector< vector<string> > & license_plates);
void print_info(int free_spaces, vector<string> illegal, vector<string> expired);

//DECLARE YOUR FUNCTION HERE//
int parking_police(int rows, int cols, vector<string> & expired,
		vector<string> & illegal, vector< vector<int> > parking_lot,
		vector< vector<string> > license_plates);


int main() {
	vector< vector<int> > parking_lot;
	vector< vector<string> > license_plates;
	int rows, cols;
	int free_spaces;

	vector<string> expired;
	vector<string> illegal;

	//fill vectors with data from input files
	read_info(rows, cols, parking_lot, license_plates);
	
	//CALL YOUR FUNCTION HERE//
	free_spaces = parking_police(rows,cols,expired,illegal,parking_lot,license_plates);

	//print parking info
	print_info(free_spaces, illegal, expired);

	return 0;
}

//DEFINE YOUR FUNCTION HERE//
int parking_police(int rows, int cols, vector<string> & expired,
		vector<string> & illegal, vector< vector<int> > parking_lot,
		vector< vector<string> > license_plates) {
	int spaces = 0;

	for (int i=0; i<rows; ++i) {
		for (int j=0; j<cols; ++j) {
			if (parking_lot.at(i).at(j) == 0) spaces++;
			else if (parking_lot.at(i).at(j) < 0) {
				expired.push_back(license_plates.at(i).at(j));
			}
			else if (parking_lot.at(i).at(j) == 404) {
				illegal.push_back(license_plates.at(i).at(j));
			}
		}
	}
	return spaces;
}

void read_info(int & rows, int & cols, vector< vector<int> > & parking_lot,
		vector< vector<string> > & license_plates) {

	ifstream input1("parking_lot.txt");
	vector<int> init_int;
	vector<string> init_string;

	int car;
	string plate;

	input1 >> rows >> cols;

	for(int i = 0; i < rows; i++) {
		parking_lot.push_back(init_int);
		for(int j = 0; j < cols; j++) {
			input1 >> car;
			parking_lot.at(i).push_back(car);
		}
	}
	
	input1.close();

	ifstream input2("license_plates.txt");
	for(int i = 0; i < rows; i++) {
		license_plates.push_back(init_string);
		for(int j = 0; j < cols; j++) {
			input2 >> plate;
			license_plates.at(i).push_back(plate);
		}
	}
	input2.close();
	return;
}


void print_info(int free_spaces, vector<string> illegal, vector<string> expired) {
	ofstream outfile ("parking_output.txt");
	outfile << "There are " << free_spaces << " empty parking spaces in the lot\n";
	outfile << "There are " << illegal.size() << " cars parked illegally:\n";
	for(int i=0; i<(int)illegal.size(); i++) {
		outfile << '\t' << illegal.at(i) << '\n';
	}
	outfile << "There are " << expired.size() << " cars with expired time:\n";
	for(int i=0; i<(int)expired.size(); i++) {
		outfile << '\t' << expired.at(i) << '\n';
	}
	outfile.close();
	return;
}
