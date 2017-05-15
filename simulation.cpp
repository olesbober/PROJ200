// simulation.cpp
// by Oles Bober & Rod Deichler
// COMSC-200 Semester Project
// 05-12-17

/* 
   This is a simulation of the DVC parking lots from Week 1 of the semester until right
   before finals week. There are four classes included: Classroom, Student, ParkingSpot,
   and ParkingLot. A Student's schedule will be parsed from a file named students.txt,
   and a vector of Students will be created. Each Student will arrive on campus at a given
   time and they will find a ParkingSpot based on their first classroom. The map will be
   updated every half second. Every half second respresents one hour.
*/

#include "ParkingLot.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

const int NUM_LOTS = 10; // number of parking lots at DVC

// a function that prints all the DVC parking lots
// this function will be used to refresh the map every step
void printAllLots(ParkingLot lots[]) {
	lots[4].printLot(0, 9);
	lots[5].printLot(36, 6);
	lots[6].printLot(76, 0);
	lots[7].printLot(128, 0);
	lots[9].printLot(198, 0);
	lots[3].printLot(0, 30);
	// print DVC logo and Viking!
	CursorPosition.X = 55;
	CursorPosition.Y = 30;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << " _______      _______ \t\t       ,   |\\ ,__";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "|  __ \\ \\    / / ____|\t\t       |\\   \\/   `.";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "| |  | \\ \\  / / |     \t\t       \\ `-.:.     `\\";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "| |  | |\\ \\/ /| |     \t\t        `-.__ `\\=====|";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "| |__| | \\  / | |____ \t\t           /=`'/   ^_\\";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "|_____/   \\/   \\_____|\t\t         .'   /\\   .=)";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "                     \t\t      .-'  .'|  '-(/_|";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "                                     .'  __(  \\  .'`";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << " \t\t                   /_.'`  `.  |`";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << " \t\t                            \\ |";
	CursorPosition.Y++;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "    \t\t\t\t             |/";
	lots[8].printLot(150, 30);
	lots[2].printLot(0, 45);
	lots[1].printLot(46, 45);
	CursorPosition.X = 84;
	CursorPosition.Y = 45;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "Parking Lot #2";
	CursorPosition.X = 95;
	CursorPosition.Y += 5;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "STAFF   ONLY";
	lots[0].printLot(120, 45);
	cout << "\t\t";
}

// tested, works
int getStudentHours(string s) {
	string delimeter = ":";
	return stoi(s.substr(0, s.find(delimeter)));
}

// tested, works
int getStudentMins(string s) {
	string delimeter = ":";
	return stoi(s.substr(s.find(delimeter) + 1, s.size()));
}

int main() {
	// Create all the empty ParkingLots and store them in an array.
	ParkingLot one(1, 17, 17);
//  ParkingLot two(STAFF ONLY);
	ParkingLot three(3, 17, 17);
	ParkingLot four(4, 21, 20);
	ParkingLot five(5, 9, 8);
	ParkingLot six(6, 16, 14);
	ParkingLot seven(7, 18, 17);
	ParkingLot eight(8, 24, 23);
	ParkingLot nine(9, 24, 23);
	ParkingLot ten(10, 6, 5);
	ParkingLot overflow(11, 33, 32);
	ParkingLot dvcParking[] = { one, three, four, five, six, seven, eight, nine, ten, overflow };

	// Create the vector of Students. All the data will be stored here.
	vector<Student> students;
	
	int hour = 0; // the hour variable that will increment in the loop

	// while loop: every half second is an hour
	// number of hours in the semester: (17 weeks) * (5 days/week) * (15 hours/day) = 1275 hours
	// to calculate the week: hour / (days/week * hour/day) -> hour / 75
	// to calculate the day of the week: hour / 15 % 5

	cout << "DVC Parking Simulation" << endl << "By Oles Bober and Roderic Deichler" << endl;

	// simulation loop
	do {
		// Print the information at the top of the screen
		CursorPosition.X = 0;
		CursorPosition.Y = 3;
		SetConsoleCursorPosition(console, CursorPosition);
		int week = hour / 75 + 1;
		cout << "Week " << week << ", ";
		int dayOfWeek = hour / 15 % 5;
		if (dayOfWeek == 4)
			cout << "Friday   ";
		else if (dayOfWeek == 3)
			cout << "Thursday ";
		else if (dayOfWeek == 2)
			cout << "Wednesday";
		else if (dayOfWeek == 1)
			cout << "Tuesday  ";
		else
			cout << "Monday   ";
		cout << " Hour: ";
		int hourPrint = hour % 15 + 8;
		string hourPrintStr = "";
		if (hourPrint < 10)
			hourPrintStr += '0';
		hourPrintStr += to_string(hourPrint) + ":00";
		cout << hourPrintStr;

		// make a student and put him in the students vector 12000 times for testing purposes
		string arrivalTimes[] = { "08:00", "08:00", "08:00", "08:00", "12:00" };
		string departureTimes[] = { "12:00", "12:00", "12:00", "12:00", "15:00" };
		Classroom c1("H", 140);
		Classroom c2("MA", 160);
		Classroom firstClass[] = { c1, c2, c1, c2, c2 };
		Student s1(arrivalTimes, departureTimes, firstClass);
		for (int i = 0; i < 12000; i++) {
			students.push_back(s1);
		}
		
		bool flag;

		// look through the students vector and assign them to spots
		for (int i = 0; i < students.size(); i++) {

			flag = true;

			// get the student arrival string from the student
			string studentArrival = *(students[i].getArrivalTimesPtr() + dayOfWeek);

			// find out the Student's time of arrival. Use a ceiling to determine this
			int studentHrs = getStudentHours(studentArrival);
			int studentMins = getStudentMins(studentArrival);
			if (studentMins != 0)
				studentHrs++;

			// if the Student is to arrive at this time
			if (studentHrs == hourPrint) {

				// dereference the first class for that day of the week
				Classroom studentClassroom = *(students[i].getFirstClassPtr() + dayOfWeek);

				// set the bestLotArray in the Classroom to the best lot
				studentClassroom.bestLot();

				// get the best lot array pointer, and find the best lot that is not full
				int* bestLot = studentClassroom.getBestLotArray();

				// look through all the best lots
				for (int j = 0; j < NUM_LOTS && flag; j++) {

					// dereference the best lot to get the lot number
					int bestLotNumber = *(bestLot + j);

					// look through the DVC parking array to find the lot and check if its full
					for (int k = 0; k < NUM_LOTS && flag; k++) {

						// if the same lot is found
						if (dvcParking[k].getLotNumber() == bestLotNumber) {

							// if it is not full
							if (!dvcParking[k].isFull()) {

								// find the next parking spot in that lot
								// pass it a student to make the spot taken
								dvcParking[k].nextSpot(students[i], dayOfWeek);

								// break from loop
								flag = false;
							}
							// if the lot is full, do nothing and go to the next best lot
						}
					}
				}
			}
		}

	//	// Now we must go through all the ParkingSpots and decrement the hours
	//	for (int i = 0; i < NUM_LOTS; i++) { // for every ParkingLot in dvcParking
	//		// if the lot is empty, go to the next lot
	//		if (dvcParking[i].isEmpty())
	//			goto lotEmpty;
	//		// for every spot in the lot
	//		for (int j = 0; j < dvcParking[i].getLotHeight(); j++) {
	//			for (int k = 0; k < dvcParking[i].getLotLength(); k++) {
	//				dvcParking[i].lot[j][k].decHours();
	//			}
	//		}
	//lotEmpty:
	//	}

		// print all the lots
		printAllLots(dvcParking);
		hour++; // increment hour
		//this_thread::sleep_for(chrono::milliseconds(500)); // pause execution for half a second
	} while (hour <= 1275);
}