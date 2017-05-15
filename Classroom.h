// Classroom.h
// by Roderic Deichler and Oles Bober
// 05-10-17

#include <string>

using namespace std;

// ifndef to prevent multiple inclusion
#ifndef Classroom_h
#define Classroom_h

// class with attributes for buildings and where to park
// struct for a classroom
class Classroom {

private:
	// building the classroom is in
	string building;

	// classroom number
	int room;

	// array that holds a sorted list of lots that
	// are best to park in depending on the building
	// 1 - 11 not including 2(staff only)
	// 11 is overflow parking
	int bestLotArray[10] = { 0 };

public:

	// default constructor
	Classroom();

	// paramaterized constructor to set building and the room
	Classroom(string b, int r);

	// setter that copies another array's values into bestLot
	void setBestLotArray(int i[]) { copy(i, i + 10, bestLotArray); }

	// setter to assign a building to the private string
	void setBuilding(string b) { building = b; }

	// setter to assign a room to the private string
	void setRoom(int r) { room = r; }

	// getter that returns the string in building
	string getBuilding() const { return building; }

	// getter that returns the room number
	int getRoom() const { return room; }

	// getter that returns a pointer to the first element in bestLot
	int* getBestLotArray() { return bestLotArray; }

	// function sets bestLotArray according to what
	// building is passed as an argument
	void bestLot();

};

// implementation of default constructor
Classroom::Classroom() {
	building = "NULL";
	room = 0;
}

// implementation of paramaterized constructor
Classroom::Classroom(string b, int r) {
	setBuilding(b);
	setRoom(r);
}

// implementation of bestLot function
void Classroom::bestLot() {

	// ordered list of best lots to park for the
	// Advanced Technology Center
	if (building == "ATC") {
		int lot[10] = { 5,4,6,3,7,8,1,9,10,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Art Building
	else if (building == "A") {
		int lot[10] = { 8,7,9,6,10,5,1,11,3,4 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Business Foreign Language building
	else if (building == "BFL") {
		int lot[10] = { 7,6,5,8,4,9,3,10,11,1 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Engineering Technology building
	else if (building == "ET") {
		int lot[10] = { 1,3,4,10,5,8,7,9,6,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Gymnasium
	else if (building == "GYM") {
		int lot[10] = { 10,1,9,8,3,7,4,5,6,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Ornamental Horticulture building
	else if (building == "OH") {
		int lot[10] = { 10,9,8,7,1,6,3,5,11,4 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Humanities building
	else if (building == "H") {
		int lot[10] = { 7,6,5,8,3,9,10,11,1,4 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Liberal Arts building
	else if (building == "LA") {
		int lot[10] = { 5,7,6,3,8,4,1,10,9,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Library
	else if (building == "L") {
		int lot[10] = { 3,4,1,5,6,7,10,8,9,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Life and Health Sciences building
	else if (building == "LHS") {
		int lot[10] = { 4,3,5,1,6,7,8,10,9,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Mathematics building
	else if (building == "MA") {
		int lot[10] = { 1,3,8,7,10,4,5,6,9,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Music building
	else if (building == "MM") {
		int lot[10] = { 1,10,3,8,9,4,7,5,6,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Performing Arts Center
	else if (building == "PAC") {
		int lot[10] = { 8,10,9,7,5,6,1,11,3,4 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Physical Science building
	else if (building == "PS") {
		int lot[10] = { 4,3,5,1,6,7,8,10,9,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Planetarium
	else if (building == "PL") {
		int lot[10] = { 4,3,5,6,1,7,10,8,9,11 };
		setBestLotArray(lot);
	}

	// ordered list of best lots to park for the
	// Science Center
	else if (building == "SC") {
		int lot[10] = { 4,3,5,6,1,7,10,8,9,11 };
		setBestLotArray(lot);
	}

}


#endif /* Classroom_h */