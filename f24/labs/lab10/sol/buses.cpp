#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

//class and struct declarations YOU WILL IMPLEMENT THESE!
struct Rider;
class Bus;

//function declarations
//These functions are for working on vectors of Bus/Rider objects.
//You should make the minor modifications indicated in their definitions.
void readBus(vector<Bus> &buses);
void loadRiders(vector<Rider> &waitingRiders);
void moveBuses(vector<Bus> &buses);
void getOn(vector<Bus> &buses, vector<Rider> &riders);

int main() {
	//TODO: declare an empty vector of type Bus called buses.
	vector<Bus> buses; 
	//read in bus data from file and store in buses
	readBus(buses);
	
	//TODO: declare an empty vector of type Rider called riders.
	vector<Rider> riders;
	//read in rider data from file and store in riders
	loadRiders(riders);

	while (riders.size()) {
		//simulate all buses moving
		moveBuses(buses);
		//try to have riders get on a bus
		getOn(buses, riders);
	}

	cout << "No more waiting riders!" << endl;
	return 0;
}

//TODO: define a class that stores Bus data. 
//Refer to the assignment sheet for a full specificiation of this
class Bus {
public:
	//initializer taking in route name and the stops
	Bus(string name, vector<string> stops_in, int id_in);

	//move forward one stop. Anyone with that destination "gets off"
	//print how many people got off, bus ID, and the location.
	void drive();

	//Three conditions need to be met to get on:
	//1) there is space on the bus
	//2) the Rider is at the right bus stop
	//3) the Rider is going to a location the bus goes to
	//Effects: adds this riders end to riderDestinations
	bool getOn(Rider rider);

private:
	int id;
	string routeName;
	int capacity;
	vector<string> stops;
	int currentStop;
	vector<string> riderDestinations;

	bool stopsAt(string dest);
};

//TODO: Create a Rider struct with two members:
//1) string start location
//2) string end location
struct Rider {
	string start;
	string end;
};

//TODO: Define your Bus initializer taking here as 
//  described in the assignment sheet.
Bus::Bus(string name, vector<string> stops_in, int id_in) {
	routeName = name;
	stops = stops_in;
	id = id_in;	
	capacity = 50;
	currentStop = 0;
	cout << "created bus " << id << " driving route " << name << endl;
}

//Requires three conditions to be true:
//1) there is space on the bus
//2) the Rider is at the same bus stop
//3) the Rider is going to a location the bus goes to
//Effects: 
bool Bus::getOn(Rider rider) {
	if (riderDestinations.size() >= (unsigned)capacity) {
		return false;
	}
	else if (stops.at(currentStop) != rider.start) {
		return false;
	}
	else if (!stopsAt(rider.end)) {
		return false;
	}
	else {
		riderDestinations.push_back(rider.end);
		return true;			
	}
}

//checks if dest is within this bus' stops.
bool Bus::stopsAt(string dest) {
	for (unsigned int i = 0; i < stops.size(); i++) {
		if (dest == stops.at(i)) {
			return true;
		}
	}
	return false;
}

//move forward one stop. Anyone with that destination gets off
//print how many people got off, bus ID, and the location.
//be sure to remove one of the riders (stored in destinations)
void Bus::drive() {
	//"Drive" to the next stop
	currentStop = (currentStop + 1) % stops.size();
	//check for anyone getting off. 
	int gotOff = 0;
	for (unsigned int i = 0; i < riderDestinations.size();) {
		if (riderDestinations.at(i) == stops.at(currentStop)) {
			gotOff++;
			riderDestinations.erase(riderDestinations.begin() + i);
		} else {
			 i++;
		}
	}

	if (gotOff) {
		cout << gotOff << " people got off at " << stops.at(currentStop);
		cout << " from bus " << id << " driving route " << routeName <<endl;
	}
	return;
}

void moveBuses(vector<Bus> &buses) {
	for (unsigned int i = 0; i < buses.size(); ++i) {
		//TODO: pull out a single Bus and call your drive member function.
		buses.at(i).drive();
	}
}

void getOn(vector<Bus> &buses, vector<Rider> &riders) {
	//loop through all waiting riders
	for (unsigned int r = 0; r < riders.size();r++) {
		//Look at a specific Rider in the riders vector
		Rider rider = riders.at(r);

		//loop through all possible buses.
		for (unsigned int b = 0; b < buses.size(); ++b) {
			//TODO: pull out a single Bus and attempt to get the rider on
			// using the getOn member function of Bus.
			//If the rider can get on, remove the rider from riders and
			//  break and move to the next rider
			
			if (buses.at(b).getOn(rider)) {
				//delete the rth element of riders (for fun: 
				//  research vector::begin())
				riders.erase(riders.begin() + r--);
				cout << "a rider got on bus " << b << endl;
				break;
			}
		}
	}

}

void readBus(vector<Bus> &buses) {
	//bus file format: 
	//Routename numStops stop1 stop2 stop3 ...
	//...
	ifstream bus_file("buses.txt");
	if (bus_file.fail()){
		cerr << "failed to open bus file.\n";
		exit(1);
	}

	//declare placeholder variables
	string routeName;
	int numStops;
	int id = 0;	

	while (bus_file >> routeName >> numStops){
		vector<string> stops;
		//read in the list of stops the bus makes and store in stops
		for (int i = 0; i < numStops; ++i) {
			string stop;
			bus_file >> stop;
			stops.push_back(stop);
		}

		//TODO: First implement a Bus initializer taking in a route name, a vector of strings, and an ID
		//then, using the above values, create a new Bus object and add it to your vector of Buses.
		Bus temp(routeName, stops, id);
		buses.push_back(temp);
		//id for next bus will simply increase by one.
		id += 1;
	}

}

void loadRiders(vector<Rider>& waitingRiders) {
	//list of start dest pairs
	ifstream riders_file("riders.txt");
	if (riders_file.fail()){
		cerr << "failed to open riders file.\n";
		exit(1);
	}

	string start, end;
	while (riders_file >> start >> end) {
		Rider tempRider;
		//TODO assign the appropriate members of tempRider
		tempRider.start = start;
		tempRider.end = end;
		waitingRiders.push_back(tempRider);
	}
}

