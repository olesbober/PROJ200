#include <iostream>
#include <string>
#include "ParkingSpot.h"

using namespace std;

int main() {

	
	Student s;
	s.setIsStudent(true);
	ParkingSpot p;
	
	string toClass[5] = {"08:00" , "10:00", "20:00", "13:00", "0"};
	string fromClass[5] = {"10:30", "12:15", "21:40", "15:00", "0"};
	
	s.setArrivalTimes(toClass);
	s.setDepartureTimes(fromClass);
	
	for (int i = 0; i < 5; i++)
		cout << p.Time(s, i) << endl;

    return 0;
}
