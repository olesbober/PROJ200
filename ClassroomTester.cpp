// ClassroomTester.cpp
// by Roderic Deichler and Oles Bober
// 05-10-17

#include <iostream>
#include "Classroom.h"
#include <string>
using namespace std;

//separates tests with a line of *'s
void SeparationLine()
{
	cout << "\n\n********************************************************************\n" << endl;
}

int main() {
	
	// creating a default classroom and testing the getters
	Classroom c;
	
	cout << "Testing the default constructor for classroom...\n";
	cout << "Expected outcome: \"NULL\" 0\n";
	cout << c.getBuilding() << " " << c.getRoom() << endl;
	
	// testing the default classroom setters
	cout << "\nNow testing the setters for classroo...\n";
	cout << "Expected outcome: \"ET\" 113\n";
	
	// setting to "ET" and 113
	c.setBuilding("ET");
	c.setRoom(113);
	cout << c.getBuilding() << " " << c.getRoom() << endl;
	
	// separation line to denote next test
	SeparationLine();
	
	// creating a paramaterized classroom and testing the getters
	Classroom c1("MA", 245);
	
	cout << "Testing the paramaterized constructor for classroom...\n";
	cout << "Expected outcome: \"MA\" 245\n";
	cout << c1.getBuilding() << " " << c1.getRoom() << endl;
	
	// separation line to denote next test
	SeparationLine();
	
	// object assignment testing (assigning c to c1)
	c1 = c;
	cout << "Testing object assignment for classroom...\n";
	cout << "Expected outcome: \"ET\" 113\n";
	cout << c1.getBuilding() << " " << c1.getRoom() << endl;
	
	// separation line to denote next test
	SeparationLine();
	
	// testing the bestLot function using getBuilding to ensure the
	// bestLot matches the expected order of parking lots
	c1.bestLot(c1.getBuilding());
	cout << "Testing the bestLot function to determine best lots for parking...\n";
	cout << "Expected outcome: 1  3  4  10  5  8  7  9  6  11\n";
	cout << "Actual   outcome: ";
	for (int i = 0; i < 10; i++)
		cout << *(c1.getBestLotArray() + i) << "  ";
	cout << endl;
	
    return 0;
}
