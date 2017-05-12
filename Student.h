// Student.h
// by Oles Bober and Roderic Deichler
// 05-04-17

#ifndef STUDENT_H
#define STUDENT_H

#include "Classroom.h"
#include <string>
using namespace std;

class Student {

private:
	// boolean that shows if the Student is enrolled or not
	bool isStudent;

	// string vector that holds the arrival times to campus of the student from M-F
	// 0 - Monday, 1 - Tuesday, 2 - Wednesday, 3 - Thursday, 4 - Friday
	// If the student does not have a class on that day, 0 will be the arrival time
	string arrivalTimes[5];

	// string array that holds the departure times from campus of the student M-F
	// 0 - Monday, 1 - Tuesday, 2 - Wednesday, 3 - Thursday, 4 - Friday
	// If the student does not have a class on that day, 0 will be the departure time
	string departureTimes[5];

	// classroom array that holds the first class of the Student M-F
	// 0 - Monday, 1 - Tuesday, 2 - Wednesday, 3 - Thursday, 4 - Friday
	// If the student does not have a class on that day, 0 will be the classroom number
	// and "NULL" will be the building
	Classroom firstClass[5];
public:
	// default constructor
	Student();

	// constructor with all variables
	Student(string[], string[], Classroom[]);

	// getters
	// returns isStudent
	bool getIsStudent() const { return isStudent; }

	// returns the pointer to the first element of arrivalTimes
	string* getArrivalTimesPtr() { return arrivalTimes; }

	// returns the pointer to the first element of departureTimes
	string* getDepartureTimesPtr() { return departureTimes; }

	// returns the pointer to the first element of firstClass
	Classroom* getFirstClassPtr() { return firstClass; }

	// setters
	// sets isStudent to argument
	void setIsStudent(bool b) { isStudent = b; }

	// takes a string array as an argument, and copies all those values into arrivalTimes
	void setArrivalTimes(string s[]) { copy(s, s + 5, arrivalTimes); }

	// takes a string array as an argument, and copies all those values into departureTimes
	void setDepartureTimes(string s[]) { copy(s, s + 5, departureTimes); }

	// takes a classroom array as an argument, and copies all those values into firstClass
	void setFirstClass(Classroom c[]) { copy(c, c + 5, firstClass); }
};

// default constructor
// sets isStudent to false and fills all arrays with 0
// essentially creates a useless Student
Student::Student() {
	isStudent = false;
	Classroom c;
	c.setBuilding("NULL");
	c.setRoom(0);
	for (int i = 0; i < 5; i++) {
		arrivalTimes[i] = "0";
		departureTimes[i] = "0";
		firstClass[i] = c;
	}
}

// parameterized constructor
// sets all the arrays to the argument values
// doesn't need to take boolean argument because if there are classes then it is a Student
Student::Student(string aT[], string dT[], Classroom fC[]) {
	isStudent = true;
	setArrivalTimes(aT);
	setDepartureTimes(dT);
	setFirstClass(fC);
}

#endif