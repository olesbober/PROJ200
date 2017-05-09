// ParkingSpot.h
// by Roderic Deichler and Oles Bober
// 05-08-17

#include "Student.h"
#include <string>
#include <math.h>

// ifndef to prevent multiple inclusion
#ifndef ParkingSpot_h
#define ParkingSpot_h

using namespace std;

// class with attributes for each ParkingSpot
class ParkingSpot {
	
		// bool that determines whether a parking spot is occupied or not
private:
	bool inUse = false;
	
		// function that returns an int rounded up to nearest hour
		// determining how long a student will be parked in the spot
		// it takes a student and a day as arguments to determine how long
		// the spot will be held up on a given day based on the student's schedule
public:
	int Time(Student &s, int day);
};



// implementation of Time function (Note: Uses 24:00 time)
ParkingSpot::int Time(Student &s, int day) {
	
		// converting the string value stored in arrival times to floats of
		// hours and minutes respectively in order to calculate how long a
		// parking spot will be in use rounded up to the next hour
		// the colon is used as a delimter to differentiate between hour and minute
		// minutes will always start at position 3 (after the first two digits and ':')
	string timeStart = s.arrivalTimes[day];
	string delimeter = ":";
	string hoursStart = timeStart.substr(0, timeStart.find(delimeter));
	string minutesStart = timeStart.substr(3);
	
		// calculating the total time in hours to prepare for subtraction later
		// with the departure times
	float totalTimeStart = stof(hoursStart, NULL) + (stof(minutesStart, NULL) / 60);
	
	string timeEnd = s.departureTimes[day];
	string delimeter = ":";
	string hoursEnd = timeEnd.substr(0, timeEnd.find(delimeter));
	string minutesEnd = timeEnd.substr(3);
	
	float totalTimeEnd = stof(hoursEnd, NULL) + (stof(minutesEnd, NULL) / 60);
	
	int timeInHours = int(totalTimeEnd - totalTimeStart + 1);
	
	return timeInHours;
		// if the student dropped out he or she will not occupy a parking spot
		// so a value of 0 will be returned for the time
//	if (!s.isStudent)
	//	return 0;
	
	
}


#endif /* ParkingSpot_h */
