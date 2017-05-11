// Building.h
// by Roderic Deichler and Oles Bober
// 05-10-17

#include <string>

using namespace std;

// ifndef to prevent multiple inclusion
#ifndef Building_h
#define Building_h

// class with attributes for buildings and where to park
class Building {
	
private:
	
		// array of strings holding the best lot for the building
		// this will be read from a file and inserted already sorted
		// eliminating a need for a function to determine the best lot
	string bestLot[10];
	
	
public:
	
		// setter that copies another array's values into bestLot
	void setBestLot(string s[]) { copy(s, s + 10, bestLot); }
	
		// getter that returns a pointer to the first element in bestLot
	string* getBestLot() { return bestLot; }
	
};

#endif /* Building_h */
