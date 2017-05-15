// ParkingLot.h
// by Oles Bober and Roderic Deichler
// 05-08-17

// prevent multiple inclusions of header
#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "ParkingSpot.h"
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

// these two variables allow for cursor reposition
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

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
	int getLotNumber() const { return lotNumber; }					// returns name of lot
	int getLotLength() const { return length; }						// returns length of lot
	int getLotHeight() const { return height; }						// returns height of lot

	// setters
	void setLotNumber(const int lN) { lotNumber = lN; }				// changes the name of the lot

	// the length and width of the lots cannot be changed.

	// prints the entire lot to the x, y coordinate 
	void printLot(int, int) const;

	// returns true if the lot is full
	bool isFull() const;

	// returns true if the lot is empty
	bool isEmpty() const;

	// assigns the given Student to the next available ParkingSpot
	// also takes the day of the week index for the ParkingSpot time function
	void nextSpot(Student&, int);
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
// the int arguments print the entire lot x characters to the right and y spots down
void ParkingLot::printLot(int x, int y) const {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "Parking Lot #" << lotNumber;
	CursorPosition.Y++;
	for (int i = 0; i < height; i++) {
		CursorPosition.X = x;
		//CursorPosition.Y = y;
		SetConsoleCursorPosition(console, CursorPosition);
		for (int j = 0; j < length; j++) {
			cout << "|";
			if (lot[i][j].isInUse())
				cout << "X";
			else
				cout << " ";
		}
		cout << "|";
		CursorPosition.Y++;
	}
}

// this function returns true if the lot is full, false otherwise
// starts from the top left because lots get filled the opposite way
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

// this function returns true if the lot is empty, false otherwise
// starts from the bottom left because lots get filled that way
bool ParkingLot::isEmpty() const {
	bool isEmpty = true;
	for (int j = 0; j < length; j++) {
		for (int i = height - 1; i >= 0; i--) {
			if (lot[i][j].isInUse()) {
				isEmpty = false;
				goto end;
			}
		}
	}
end:
	return isEmpty;
}

// This finds the next available parking spot in the lot and assigns the student to it as well as the time remaining
void ParkingLot::nextSpot(Student &s, int day) {

	bool flag = true;

	// look through every ParkingSpot
	for (int i = height - 1; i >= 0 && flag; i--) {
		for (int j = 0; j < length && flag; j++) {
			
			// if the spot is not in use
			if (!lot[i][j].isInUse()) {

				// set the hours remaining in the lot based on the Student's arrival and departure times
				lot[i][j].setHoursRemaining(lot[i][j].Time(s, day));

				// set the spot to in use
				lot[i][j].setInUse(true);

				// break from the loop
				flag = false;
			}
		}
	}
}

#endif