
#ifndef _HAYDEN_H
#define _HAYDEN_H
// Q1a: Create Hayden class (5 points)
// Part 1: Create a child class of the Room class named 'Hayden'
//Declares a child class from the room class
class Hayden : public Room
{

	// Part2: Declare constructor which accepts the same 3 parameters as the parent class Room's constructor.
	// Pass the 3 parameters to the super constructor of the Room class.
	//Declares constructor and takes roomNam, noOfRooms, and libType which are the same 3 parameters as the parent class Room's constructor
public: Hayden(string roomName, int noOfRooms, libraryType libType) : Room(roomName, noOfRooms, libType)
{

}

	  // Part 3: Re-declare the method displayRoom (virtual method found inside of parent class Room)
	   //redeclares the method
	  void displayRoom();
};
#endif // _HAYDEN_H
