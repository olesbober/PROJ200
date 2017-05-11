// Building.h
// by Roderic Deichler and Oles Bober
// 05-10-17

#include <string>

using namespace std;

// ifndef to prevent multiple inclusion
#ifndef Building_h
#define Building_h

// class with attributes for buildings and where to park
// struct for a classroom
class Classroom {
	// building the classroom is in
	string building;
	
	// classroom number
	int room;

	
	
public:
	
	// setter that copies another array's values into bestLot
//	void setBestLot(string s[]) { copy(s, s + 10, bestLot); }
	
	void setBuilding(string b) { building = b; }
	
	void setRoom(int r) { room = r; }
	
	string getBuilding() { return building; }
	
	// getter that returns a pointer to the first element in bestLot
	
//	string* getBestLot() { return bestLot; }
	
	int bestLot(string b);
};

/*int Classroom::bestLot(string b) {
	
			if (b == "ATC")
				if (
	
	
}*/


#endif /* Building_h */
