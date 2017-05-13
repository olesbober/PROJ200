// ParkingSpot.h
// by Roderic Deichler and Oles Bober
// 05-08-17

// ifndef to prevent multiple inclusion
#ifndef ParkingSpot_h
#define ParkingSpot_h

#include "Student.h"
#include <string>
#include <math.h>

using namespace std;

// class with attributes for each ParkingSpot
class ParkingSpot {
	
private:
	// bool that determines whether a parking spot is occupied or not
	bool inUse = false;
	
	// unsigned int used to determine how many hours until the spot is empty
	unsigned int hoursRemaining = 0;
	
	
public:
		// default constructor
	ParkingSpot();
	
		// function that returns an int rounded up to nearest hour
		// determining how long a student will be parked in the spot
		// it takes a student and a day as arguments to determine how long
		// the spot will be held up on a given day based on the student's schedule
	int Time(Student &s, int day);
	
		// getter function that returns a bool (inUse)
	bool isInUse() const { return inUse; }
	
		// setter function that sets bool inUse to the argument
	void setInUse(bool b) { inUse = b; }
	
		// function that decrements the hoursRemaining by 1
	void decHours();

};

		// default constructor that just makes sure inUse is false and hours is 0
ParkingSpot::ParkingSpot() {
	inUse = false;
	hoursRemaining = 0;
}

// implementation of Time function (Note: Uses 24:00 time)
int ParkingSpot::Time(Student &s, int day) {
	
	// exception handling for ensuring the student exists
	// if not then the student will not occupy a parking spot
	// so the time returned in hours should be 0
	if (!s.getIsStudent())
		return 0;
	
		// first assigning strings to the values of the strings stored into
		// the arrival time and departure time arrays of the Student class
		// then exception handling for arrival and departure times
		// if either the arrival or departure times are equal to "0"
		// then the student is not going to class that day and the time
		// in hours returned should be 0
	string timeStart = *(s.getArrivalTimesPtr() + day);
	if (timeStart == "0")
		return 0;
	
	string timeEnd = *(s.getDepartureTimesPtr() + day);
	if (timeEnd == "0")
		return 0;
	
		// converting the string value stored in arrival times to floats of
		// hours and minutes respectively in order to calculate how long a
		// parking spot will be in use rounded up to the next hour
		// the colon is used as a delimter to differentiate between hour and minute
		// minutes will always start at position 3 (after the first two digits and ':')
	string delimeter = ":";
	string hoursStart = timeStart.substr(0, timeStart.find(delimeter));
	string minutesStart = timeStart.substr(3);
	
		// calculating the total time in hours to prepare for subtraction later
		// with the departure times
	float totalTimeStart = stof(hoursStart, NULL) + (stof(minutesStart, NULL) / 60);
	
		// converting the string tokens stored in departure times using same procedure as
		// before with arrival times (including using ':' as a delimeter)
	string hoursEnd = timeEnd.substr(0, timeEnd.find(delimeter));
	string minutesEnd = timeEnd.substr(3);
	
	// calculating the total time in hours to prepare for subtraction later
	// with the arrival times
	float totalTimeEnd = stof(hoursEnd, NULL) + (stof(minutesEnd, NULL) / 60);
	
	// performing subtraction and casting the float as an int in order to
	// return the value as an int (because the program will change based on whole
	// numbers for hours and)
	hoursRemaining = int(totalTimeEnd  - totalTimeStart + 0.99);
	
	// return the value stored in timeInHours
	return hoursRemaining;
	
}

// implementing the function that decrements hours by 1
void ParkingSpot::decHours() {
	if (hoursRemaining > 0)
		hoursRemaining--;
}


#endif /* ParkingSpot_h */
