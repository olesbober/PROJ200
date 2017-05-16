' Written by Serhiy Malyy on 05-15-17
' Modified by Oles Bober

Dim strArrivalTitme, strDepartureTime, strBuildingIfo
Dim intNumOfStudents : intNumOfStudents = InputBox("Enter Number of Students")

Dim delimiter : delimiter = "	"

strWeekGrid = "M"&delimiter&"T"&delimiter&"W"&delimiter&"Th"&delimiter&"F"&delimiter&""

Dim arrWeekDay
arrWeekDay = Array("NA","M","T","W","Th","F")

Dim arrMinutes
arrMinutes= Array("NA","00","30")

Dim arrLectureDur
arrLectureDur = Array("NA","1","2","3","4","5","6")

Dim arrRoomNumber
arrRoomNumber = Array("NA","101","102","103","104","201","202","203","204","301","302","303","304")

strFIleLocation = "C:\Users\Oles Bober\Documents\COMSC200\Project\SemesterProject\students.txt"

Set objFSO = CreateObject("Scripting.FileSystemObject")
Set objFile = objFSO.CreateTextFile(strFIleLocation)
objFile.Close

Const ForWriting = 2
Set objFile = objFSO.OpenTextFile(strFIleLocation, ForWriting)

Dim arrBuildingd(17)
arrBuildingd(0)= "NA" '- Not available
arrBuildingd(1)= "ATC" '- Advanced Technology Center
arrBuildingd(2)= "A" ' - Art
arrBuildingd(3)= "BFL" ' - Business and Foreign Language
arrBuildingd(4)= "ET" ' - Engineering and Technology
arrBuildingd(5)= "GYM" ' - Gymnasium
arrBuildingd(6)= "OH" ' - Ornamental Horticulture
arrBuildingd(7)= "H" ' - Humanities
arrBuildingd(8)= "LA" ' - Liberal Arts
arrBuildingd(9)= "L" ' - Library
arrBuildingd(10)= "LHS" ' - Life and Health Sciences
arrBuildingd(11)= "MA" ' - Mathematics
arrBuildingd(12)= "MM" ' - Music
arrBuildingd(13)= "NUL" ' - No class on that day
arrBuildingd(14)= "PAC" ' - Performing Arts Center
arrBuildingd(15)= "PS" ' - Physical Science
arrBuildingd(16)= "PL" ' - Planetarium
arrBuildingd(17)= "SC" ' - Science Center

Function randomize_value(min, max)
    Randomize   ' Initialize random-number generator.
	'randomize_value = Int((int_To * Rnd) + int_From)
	
	randomize_value = Int((max-min+1)*Rnd+min)
End Function


objFile.WriteLine strWeekGrid
    
For intStudent = 1 To intNumOfStudents
  ' Print strWeekGrid

    ' objFile.WriteLine strWeekGrid
    
   ' mon. through fri.
	For intWeekDatCal = 1 To 5
	    

	   For intRows = 1 To 4
	       
	       Select Case intRows
	       	  
	       	  Case 1
	       	   		'Print strArivalDay 
	       	   
	       	  Case 2 
			  		'Arrival Hours from 8AM to 5PM
	    			intArrivalHour = randomize_value(8, 17)
	    			If intArrivalHour > 19 Then
	    				msgbox "Bad Hour " &  intArrivalHour
	    			End If
	    	   		'Arrival Minutes
	    	    	intArrivalMinute = arrMinutes(randomize_value(1,2))
	    	    	' complete arrival time 
	    	   		strArrivalTitme = strArrivalTitme & (intArrivalHour & ":" & intArrivalMinute) & delimiter
						    	   		
	       	 Case 3 
	       		    intDepartureHour = 	intArrivalHour + (arrLectureDur(randomize_value(3,5)))
	       		    intDepartureMinutes = arrMinutes(randomize_value(1,2))
	       		    strDepartureTime = strDepartureTime & intDepartureHour & ":" & intDepartureMinutes & delimiter
	       		    'print strDepartureTime
	       		    
	         Case 4 
	         		strBuildingIfo = strBuildingIfo & arrBuildingd(randomize_value(1, 17)) & "-" & arrRoomNumber(randomize_value(1, 12)) & delimiter
	         		'print strBld
	       End Select

	    
	    
	    Next 'For intRows = 1 To 4
	    

	Next ' For intWeekDatCal = 1 To 5
	
'	print strArrivalTitme 
'	print strDepartureTime
'	print strBuildingIfo 
	
	objFile.WriteLine strArrivalTitme
	objFile.WriteLine strDepartureTime
	objFile.WriteLine strBuildingIfo
	
	strBuildingIfo = ""
	strDepartureTime = ""
	strArrivalTitme = ""

Next ' For intStudent = 1 TointNumOfStudents


objFile.Close
Set objFile = Nothing
Set objFSO = Nothing
msgbox "Done Creating " &  intNumOfStudents & " students"

'Function ShowDateCreated(filespec)
'   Dim fso, f
'   Set fso = CreateObject("Scripting.FileSystemObject")
'   Set f = fso.GetFile(filespec)
'   ShowDateCreated = f.DateCreated
'End Function 
