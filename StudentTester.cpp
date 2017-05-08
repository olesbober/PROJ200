// StudentTester.cpp
// by Oles Bober
// 05-08-17

#include "Student.h"
#include <iostream>
using namespace std;

void printLine() {
	cout << "-------------------------------------------------------" << endl;
}

int main() {
	string newArrivals[] = { "10:20", "20:00", "13:00", "08:00", "0" };
	cout << "This here program tests the Student header file." << endl;
	printLine();
	cout << "Creating new Student via default constructor... ";
	Student useless;
	cout << "Done." << endl;
	cout << "Student useless: " << endl;
	cout << "isStudent: ";
	if (useless.getIsStudent())
		cout << "true";
	else
		cout << "false";
	cout << endl << "arrivalTimes: ";
	for (int i = 0; i < 5; i++)
		cout << *(useless.getArrivalTimesPtr() + i) << " ";
	cout << endl;
	cout << "Testing setArrivalTimes... " << endl;
	useless.setArrivalTimes(newArrivals);
	for (int i = 0; i < 5; i++)
		cout << *(useless.getArrivalTimesPtr() + i) << " ";
	cout << endl;
}