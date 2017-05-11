// ParkingLot.h
// by Oles Bober and Roderic Deichler
// 05-08-17

// prevent multiple inclusions of header
#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Student.h"
#include "ParkingSpot.h"
using namespace std;

class ParkingLot {
private:
	// name of parking lot
	string name;

	// every parking lot is a rectangle
	// length is number of spots lengthwise
	// height is number of spots from top to bottom
	// instead of using a 2-D array, we are going to simulate a 2-D array with a 1-D array
	int length, height;
	ParkingSpot* lot;
	void copy(const ParkingLot &); // deep copy
public:
	ParkingLot();										// default constructor
	ParkingLot(string, int, int);						// parameterized constructor
	ParkingLot(const ParkingLot &);						// copy constructor
	~ParkingLot() { delete[] lot; }						// destructor
	ParkingLot& operator=(const ParkingLot &);			// assignment operator
	ParkingSpot& at(int row, int col);					// this functions acts like [][] in a 2-D array
	// getters
	string getLotName() const { return name; }			// returns name of lot
	int getLotLength() const { return length; }			// returns length of lot
	int getLotHeight() const { return height; }			// returns height of lot
	ParkingSpot* operator[](int row) { return lot; }	// returns lot array pointer
	// setters
	void setLotName(const string n) { name = n; }		// changes the name of the lot
	// the length and width of the lots cannot be changed.
};

// deep copy private function
void ParkingLot::copy(const ParkingLot &pL) {
	name = pL.name;
	length = pL.length;
	height = pL.height;
	lot = new ParkingSpot[length * height];
	for (unsigned int i = 0; i < length * height; i++)
		lot[i] = pL.lot[i];
}

// implementation of default constructor
// creates a 25-spot lot with name NULL
ParkingLot::ParkingLot() {
	name = "NULL";
	length = 5;
	height = 5;
	// allocate memory for ParkingSpots
	lot = new ParkingSpot[length * height];
}

// implementation of parameterized constructor
ParkingLot::ParkingLot(string n, int l, int h) {
	name = n;
	length = l;
	height = h;
	// allocate memory for ParkingSpots
	lot = new ParkingSpot[length * height];
}

// copy constructor. Following the Rule of Three:
// must use deep copy
ParkingLot::ParkingLot(const ParkingLot &pL) {
	lot = NULL;
	copy(pL);
}

// assignment operator

// 
ParkingSpot& ParkingLot::at(int row, int col) {
	return lot[row * length + col];
}
#endif