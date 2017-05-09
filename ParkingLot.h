// ParkingLot.h
// by Oles Bober and Roderic Deichler
// 05-08-17

#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Student.h"
#include "ParkingSpot.h"
using namespace std;

class ParkingLot {
private:
	const int LENGTH, HEIGHT;
	ParkingSpot lot[LENGTH][HEIGHT];
};

#endif