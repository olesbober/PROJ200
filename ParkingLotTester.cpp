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
	ParkingLot overflow(420, 14, 76);
	cout << "ParkingLot overflow created with parameterized constructor." << endl;
	printLine();
	cout << "Number of ParkingLot useless: " << useless.getLotNumber() << endl;
	cout << "Number of ParkingLot overflow: " << overflow.getLotNumber() << endl;
	printLine();
	cout << "Length of ParkingLot useless: " << useless.getLotLength() << endl;
	cout << "Length of ParkingLot overflow: " << overflow.getLotLength() << endl;
	printLine();
	cout << "Height of ParkingLot useless: " << useless.getLotHeight() << endl;
	cout << "Height of ParkingLot overflow: " << overflow.getLotHeight() << endl;
	printLine();
	cout << "Setting the number of lot useless to 20... ";
	useless.setLotNumber(20);
	cout << "Done." << endl;
	cout << "Setting the number of lot overflow to 10... ";
	overflow.setLotNumber(10);
	cout << "Done." << endl;
	cout << "Number of ParkingLot useless: " << useless.getLotNumber() << endl;
	cout << "Number of ParkingLot overflow: " << overflow.getLotNumber() << endl;
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
	cout << "Is lot useless full?" << endl;
	if (useless.isFull())
		cout << "Yes." << endl;
	else
		cout << "No." << endl;
	cout << "Is lot overflow full?" << endl;
	if (overflow.isFull())
		cout << "Yes." << endl;
	else
		cout << "No." << endl;
	printLine();
	cout << "We will now fill both lots in order to further test the functio isFull()." << endl;
	cout << "Filling ParkingLot useless... ";
	for (int i = 0; i < useless.getLotHeight(); i++) {
		for (int j = 0; j < useless.getLotLength(); j++) {
			useless.lot[i][j].setInUse(true);
		}
	}
	cout << "Done. Is ParkingLot useless full?" << endl;
	if (useless.isFull())
		cout << "Yes." << endl;
	else
		cout << "No." << endl;
	cout << "Filling ParkingLot overflow... ";
	for (int i = 0; i < overflow.getLotHeight(); i++) {
		for (int j = 0; j < overflow.getLotLength(); j++) {
			overflow.lot[i][j].setInUse(true);
		}
	}
	cout << "Done. Is ParkingLot overflow full?" << endl;
	if (overflow.isFull())
		cout << "Yes." << endl;
	else
		cout << "No." << endl;
	printLine();
}