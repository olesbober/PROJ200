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
	lots[8].printLot(150, 30);
	lots[2].printLot(0, 45);
	lots[1].printLot(46, 45);
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

void percentDrop(vector<Student> &s, int size, double percent) {
	double newPercent = (100.0 - percent) / 100.0;

	// create new size of student array
	int newSize = size * newPercent;

	// make a useless Student
	Student student;

	// create new array with useless Students
	vector<Student> temp(newSize, student);

	// copy over the first newSize Students from students to temp
	for (int index = 0; index < temp.size(); index++) {
		temp[index] = s[index];
	}

	// assign temp to students
	s = temp;
}

// this function parses the file 'students.txt' and returns a vector with the information
vector<Student> readStudentSchedule(ifstream& inFile) {

	// for parsing the inputfile
	// char pointer to make tokens (substr)
	// array of char for addressing
	// const pointer to find tabs in file
	char* token;
	char buf[1000];
	const char* const tab = "\t";

	// ints to hold the lines counted and the
	// size of the vector as the function runs
	int lineCount = 0;
	int vecCount = 0;

	// check if file can be opened
	if (!inFile.good()) throw "I/O error";

	// vector of students (dynamic needed to expand as it increases)
	vector <Student> stuVec;

	// read the input file
	while (inFile.good()) {

		// read the whole line
		string line;
		getline(inFile, line);
		strcpy_s(buf, line.c_str());
		if (buf[0] == 0) continue;

		// enter this if statement when parsing arrival times
		// this happens once every three lines starting at the first line
		if ((lineCount - 1) % 3 == 0) {

			// array of strings to hold the 5 different arrival times
			// each arrival time corresponds to a day of the week
			// 0 - M   1 - T   2 - W   3 - Th   4 - Fr
			string arrivalTimes[5];


			// parses the line and makes 5 strings for each arrival time
			const string a1(token = strtok(buf, tab));
			const string a2(token = strtok(0, tab));
			const string a3(token = strtok(0, tab));
			const string a4(token = strtok(0, tab));
			const string a5(token = strtok(0, tab));

			// assign each string of arrival times to the different
			// days of the week within the array
			arrivalTimes[0] = a1;
			arrivalTimes[1] = a2;
			arrivalTimes[2] = a3;
			arrivalTimes[3] = a4;
			arrivalTimes[4] = a5;

			// create a student and set their arrival times to the
			// array just created then push the student back into
			// the vector of all students and increment the count
			Student s;
			s.setIsStudent(true);
			s.setArrivalTimes(arrivalTimes);
			stuVec.push_back(s);
			vecCount++;

		}

		// enter this if statement when parsing departure times
		// this happens once every three lines starting at the second line
		else if ((lineCount - 2) % 3 == 0) {

			// array of strings to hold the 5 different departure times
			// each departure time corresponds to a day of the week
			// 0 - M   1 - T   2 - W   3 - Th   4 - Fr
			string departureTimes[5];

			// parse the line and make 5 strings for departure times
			const string d1(token = strtok(buf, tab));
			const string d2(token = strtok(0, tab));
			const string d3(token = strtok(0, tab));
			const string d4(token = strtok(0, tab));
			const string d5(token = strtok(0, tab));

			// assign each stringof departure times to a different
			// day of the week within the array
			departureTimes[0] = d1;
			departureTimes[1] = d2;
			departureTimes[2] = d3;
			departureTimes[3] = d4;
			departureTimes[4] = d5;

			// modify the existing student created in the first if statement
			// in the vector to add the departure times
			stuVec[vecCount - 1].setDepartureTimes(departureTimes);

		}

		// enter this if statement when parsing classroom/building
		// this happens once every three lines starting at the third line
		else if (lineCount % 3 == 0 && lineCount != 0) {

			// create an array of classrooms to hold the location
			// of the student's first class (aka where to park closest to)
			Classroom buildings[5];

			// create 5 classrooms to hold the information that will be
			// parsed and placed into the array of classrooms
			Classroom c1;
			Classroom c2;
			Classroom c3;
			Classroom c4;
			Classroom c5;

			// create a token or substring for the room and building
			// and then split that up into two smaller substrings
			// one for the building code and one for the room number
			// these codes are separated by
			const string room1(token = strtok(buf, tab));
			const string b1(room1.begin(), room1.begin() + room1.find('-'));
			const string r1(room1.begin() + room1.find('-') + 1, room1.end());

			// continue the same procedure as above starting after the tab
			// for the next room and building
			const string room2(token = strtok(0, tab));
			const string b2(room2.begin(), room2.begin() + room2.find('-'));
			const string r2(room2.begin() + room2.find('-') + 1, room2.end());

			// continue the same procedure as above starting after the tab
			// for the next room and building
			const string room3(token = strtok(0, tab));
			const string b3(room3.begin(), room3.begin() + room3.find('-'));
			const string r3(room3.begin() + room3.find('-') + 1, room3.end());

			// continue the same procedure as above starting after the tab
			// for the next room and building
			const string room4(token = strtok(0, tab));
			const string b4(room4.begin(), room4.begin() + room4.find('-'));
			const string r4(room4.begin() + room4.find('-') + 1, room4.end());

			// continue the same procedure as above starting after the tab
			// for the next room and building
			const string room5(token = strtok(0, tab));
			const string b5(room5.begin(), room5.begin() + room5.find('-'));
			const string r5(room5.begin() + room5.find('-') + 1, room5.end());

			// set the parsed values for the first classroom to be placed
			// into the array and then call the bestLot function so that the
			// classroom is ready to be assigned to a student
			c1.setBuilding(b1);
			c1.setRoom(stoi(r1));
			c1.bestLot(b1);

			// continue the same procedure as above for the next classroom
			c2.setBuilding(b2);
			c2.setRoom(stoi(r2));
			c2.bestLot(b2);

			// continue the same procedure as above for the next classroom
			c3.setBuilding(b3);
			c3.setRoom(stoi(r3));
			c3.bestLot(b3);

			// continue the same procedure as above for the next classroom
			c4.setBuilding(b4);
			c4.setRoom(stoi(r4));
			c4.bestLot(b4);

			// continue the same procedure as above for the next classroom
			c5.setBuilding(b5);
			c5.setRoom(stoi(r5));
			c5.bestLot(b5);

			// assign the classrooms created above to the array of classrooms
			buildings[0] = c1;
			buildings[1] = c2;
			buildings[2] = c3;
			buildings[3] = c4;
			buildings[4] = c5;

			// modify the student created in the vector in the first if statement
			// by setting their first classes (and what lots to park in)
			stuVec[vecCount - 1].setFirstClass(buildings);
		}

		// one line has been read so increment the lineCount
		lineCount++;
	}
	return stuVec;
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

	// print lot 2
	CursorPosition.X = 84;
	CursorPosition.Y = 45;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "Parking Lot #2";
	CursorPosition.X = 95;
	CursorPosition.Y += 5;
	SetConsoleCursorPosition(console, CursorPosition);
	cout << "STAFF   ONLY";

	//// make a student and put him in the students vector 12000 times for testing purposes
	//string arrivalTimes[] = { "08:00", "08:00", "08:00", "08:00", "12:00" };
	//string departureTimes[] = { "12:00", "12:00", "12:00", "12:00", "15:00" };
	//Classroom c1("H", 140);
	//Classroom c2("MA", 160);
	//Classroom firstClass[] = { c1, c2, c1, c2, c2 };
	//Student s1(arrivalTimes, departureTimes, firstClass);
	//for (int i = 0; i < 4000; i++) {
	//	students.push_back(s1);
	//}

	ifstream inFile;
	inFile.open("students.txt");
	students = readStudentSchedule(inFile);

	bool flag;

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
		CursorPosition.X = 0;
		CursorPosition.Y = 5;
		SetConsoleCursorPosition(console, CursorPosition);
		cout << "Current number of students: " << students.size();

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
				studentClassroom.bestLot(studentClassroom.getBuilding());

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

		// Now we must go through all the ParkingSpots and decrement the hours
		for (int i = 0; i < NUM_LOTS; i++) { // for every ParkingLot in dvcParking
											 // if the lot is empty, go to the next lot
			if (!dvcParking[i].isEmpty()) {
				// for every spot in the lot
				for (int j = 0; j < dvcParking[i].getLotHeight(); j++) {
					for (int k = 0; k < dvcParking[i].getLotLength(); k++) {
						// decrement the hours
						dvcParking[i].lot[j][k].decHours();
					}
				}
			}
		}

		// after two weeks, fifteen percent of Students drop
		if (hour == 140) {
			percentDrop(students, students.size(), 15);
		}

		// every week after that until week 12, 1 percent of students drop
		if (hour == 210 || hour == 280 || hour == 350 || hour == 420 || hour == 490 || hour == 560 || hour == 630 || hour == 700 || hour == 770)
			percentDrop(students, students.size(), 1);

		// after 12 weeks, twenty percent of students drop
		if (hour == 840)
			percentDrop(students, students.size(), 20);

		// print all the lots
		printAllLots(dvcParking);
		hour++; // increment hour
		//this_thread::sleep_for(chrono::milliseconds(1000)); // pause execution for half a second
	} while (hour <= 1275);

	// close the file
	inFile.close();
}