// ParkingLotTester.cpp
// by Oles Bober and Roderic Deichler
// 05-11-17

#include "ParkingLot.h"
#include <iostream>
#include <time.h>
using namespace std;

void printLine() {
	cout << "-------------------------------------------------------" << endl;
}

int main() {
	cout << "This program tests the ParkingLot class." << endl;
	printLine();
	ParkingLot useless;
	cout << "ParkingLot useless created with default constructor." << endl;
	ParkingLot overflow("Overflow", 14, 76);
	cout << "ParkingLot overflow created with parameterized constructor." << endl;
	printLine();
	cout << "Name of ParkingLot useless: " << useless.getLotName() << endl;
	cout << "Name of ParkingLot overflow: " << overflow.getLotName() << endl;
	printLine();
	cout << "Length of ParkingLot useless: " << useless.getLotLength() << endl;
	cout << "Length of ParkingLot overflow: " << overflow.getLotLength() << endl;
	printLine();
	cout << "Height of ParkingLot useless: " << useless.getLotHeight() << endl;
	cout << "Height of ParkingLot overflow: " << overflow.getLotHeight() << endl;
	printLine();
	cout << "Setting the name of lot useless to \"Useless\"... ";
	useless.setLotName("Useless");
	cout << "Done." << endl;
	cout << "Setting the name of lot overflow to \"Lot 10\"... ";
	overflow.setLotName("Lot 10");
	cout << "Done." << endl;
	cout << "Name of ParkingLot useless: " << useless.getLotName() << endl;
	cout << "Name of ParkingLot overflow: " << overflow.getLotName() << endl;
	printLine();
	cout << "We will now randomly fill some spots in the lots." << endl;
	cout << "Randomly filling lot useless... ";
	srand(time(NULL));
	for (int i = 0; i < useless.getLotHeight(); i++) {
		for (int j = 0; j < useless.getLotLength(); j++) {
			bool randomBool = rand() % 2;
			useless.lot[i][j].setInUse(randomBool);
		}
	}
	cout << "Done. Printing lot useless: " << endl;
	useless.printLot();
	cout << "Randomly filling lot overflow... ";
	for (int i = 0; i < overflow.getLotHeight(); i++) {
		for (int j = 0; j < overflow.getLotLength(); j++) {
			bool randomBool = rand() % 2;
			overflow.lot[i][j].setInUse(randomBool);
		}
	}
	cout << "Done. Printing lot overflow: " << endl;
	overflow.printLot();
	printLine();
}