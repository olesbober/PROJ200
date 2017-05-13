// ParkingLot.h
// by Oles Bober and Roderic Deichler
// 05-08-17

// prevent multiple inclusions of header
#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Student.h"
#include "ParkingSpot.h"
#include <iostream>
#include <vector>
using namespace std;

class ParkingLot {
private:
	// number of parking lot
	int lotNumber;

	// every parking lot is a rectangle
	// length is number of columns in the lot
	// height is number of rows in the lot
	int length, height;

public:
	// a 2D vector to represent the parking lot
	// the lot is public in order to be able to change the inUse variable or not
	vector<vector<ParkingSpot>> lot;

	ParkingLot();													// default constructor
	ParkingLot(int, int, int);										// parameterized constructor

	// getters
	int getLotNumber() const { return lotNumber; }						// returns name of lot
	int getLotLength() const { return length; }						// returns length of lot
	int getLotHeight() const { return height; }						// returns height of lot

	// setters
	void setLotNumber(const int lN) { lotNumber = lN; }					// changes the name of the lot

	// the length and width of the lots cannot be changed.
	void printLot() const;
	bool isFull() const;
};

// default constructor
// creates an empty 2D vector of length 5 and height 5
ParkingLot::ParkingLot() {
	ParkingSpot p;
	length = 5;
	height = 5;
	vector<vector<ParkingSpot>> temp(height, vector<ParkingSpot>(length, p));
	lot = temp;
	lotNumber = 0;
}

// parameterized constructor
ParkingLot::ParkingLot(int lN, int l, int h) {
	// create an empty ParkingSpot
	ParkingSpot p;

	// assign length and height
	length = l;
	height = h;

	// create a temporary vector with height h and length l
	// fill the 2D vector with empty ParkingSpots
	vector<vector<ParkingSpot>> temp(height, vector<ParkingSpot>(length, p));

	// assign temporary vector to lot
	lot = temp;

	// assign name
	lotNumber = lN;
}

// a function that prints the lot and shows which spots are taken
void ParkingLot::printLot() const {
	cout << "Parking Lot #" << lotNumber << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			cout << "|";
			if (lot[i][j].isInUse())
				cout << "X";
			else
				cout << " ";
		}
		cout << "|" << endl;
	}
}

// this function returns true if the lot is full, false otherwise
bool ParkingLot::isFull() const {
	bool isFull = true;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			if (!lot[i][j].isInUse()) {
				isFull = false;
				goto end;
			}
		}
	}
	end:
	return isFull;
}

#endif