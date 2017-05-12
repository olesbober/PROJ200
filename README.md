# PROJ200
COMSC-200 Semester Project.
by Oles Bober and Rod Deichler
started May 5th, 2017

This project is a virtual simulation of the DVC parking lot, from Week 1 until Finals Week.
The simulation runs hour-by-hour.
Any notes we need to remember can be written here.

Notes for future reference:
- Add exception handling in Student.h
- ParkingLot.h is NO LONGER done.
Classroom.h needs to know if the parking lot is full or not. We need to make a boolean variable isFull to determine whether or not this lot should be parked in. This will have to draw from the parking spots themselves?

      I had to make the lot vector public in order to be able to access it in a main function. An example is in ParkingLotTester.cpp. This  is actually okay because all the other variables are private, including the ones in ParkingSpot.h.
      
- Deleted DynamicArray.h and PriorityQueue.h. We do not need them for now. I was also thinking it would be better to use the STL priority queue because this is how we learned about it in class.

-No more questions about Building.h. Replaced it with Classroom.h. Classroom.h now needs to pull information from ParkingLot.h. 
