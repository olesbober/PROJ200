// readStudentsFunc.cpp
// by Roderic Deichler and Oles Bober
// 05-13-17

#include "Student.h"
#include "Classroom.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// prototype for function
vector <Student> readStudentSchedule(ifstream& inFile);

/*
 *The main is the tester of the readStudentSchedule function
 *it can be deleted or replaced when readStudentSchedule
 *is to be implemented
 */


int main() {
	ifstream inFile;
	inFile.open("students.txt");
	
	vector <Student> stuVec = readStudentSchedule(inFile);
	
	// nested for loops to print the file and test it was read properly
	cout << "Testing that the file was properly read...\n\n";
	for (int i = 0; i < stuVec.size(); i++) {
		for (int j = 0; j < 5; j++) {
			cout << *(stuVec[i].getArrivalTimesPtr() + j) << "\t";
		}
		cout << endl;
		
		for (int j = 0; j < 5; j++) {
			cout << *(stuVec[i].getDepartureTimesPtr() + j) << "\t";
		}
		cout << endl;
		
		for (int j = 0; j < 5; j++) {
			Classroom c = *(stuVec[i].getFirstClassPtr() + j);
			cout << c.getBuilding() << "-" << c.getRoom() << "\t";
		}
		cout << endl;
	}
}

vector <Student> readStudentSchedule(ifstream& inFile) {

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

	// open the input file
	if (!inFile.good()) throw "I/O error";

	// vector of students (dynamic needed to expand as it increases)
	vector <Student> stuVec;

	// read the input file
	while (inFile.good()) {
	
		// read the whole line
		string line;
		getline(inFile, line);
		strcpy(buf, line.c_str());
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
			stuVec[vecCount-1].setDepartureTimes(departureTimes);
		
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
			stuVec[vecCount-1].setFirstClass(buildings);
		}
	
		// one line has been read so increment the lineCount
		lineCount++;
	}
	return stuVec;
}
