# PROJ200
COMSC-200 Semester Project.
by Oles Bober and Rod Deichler
started May 5th, 2017

This project is a virtual simulation of the DVC parking lot, from Week 1 until Finals Week.
The simulation runs hour-by-hour.
Any notes we need to remember can be written here.

Notes for future reference:
- Add exception handling in Student.h
- Not done with ParkingLot.h. It seems more complicated than I imagined it to be: 2-D array are hard to make.
      ^^^The problem is that 2-D arrays cannot be used for a generic parking lot, because you need to initialize at least one of the 
         arguments (row/column) at time of creation. I think it's row only? You would need a dynamic array ie a vector. We could also use          a dynamic array template from our 210 class.
- Questions about Building.h... I'm wondering about parsing the data. Maybe it would be wiser to make building a class within student, because student will already be parsing all of the data and since it is going line by line we can be sure the data is going to the same place. 1 student = 1 spot = 1 building. This is all from one single course they signed up for. If we parse all of the data only looking for start and end times, then it would be hard to keep track of which building is assigned to which student when we parse all of the data again separately, looking for just buildings.
