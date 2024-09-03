
// Q2b: Define displayRoom() for Noble class (5 points)
// Define the function displayRoom() that you declared within the Noble class in the header file
// See expected output in question file.

// (displayList() function in the hw7.cpp should call this function.)
// Include necessary header files


#include "room.h"
#include "noble.h"

#include <iostream>

void Noble::displayRoom()
{
	cout << endl << "Room name:  " << getName() << endl;
	cout << "Number of Rooms: " << getNo() << endl;
	string name;
	if (getLibraryType() == 1)
	{
		name = "Noble";
	}
	else
	{
		name = "Hayden";
	}
	cout << "Library: " << name << endl << endl;
	// notice that no function call is needed becasue we know this is Noble class function
}
