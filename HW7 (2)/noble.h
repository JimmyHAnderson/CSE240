#ifndef _NOBLE_H_
#define _NOBLE_H_
// Q1b: Create Noble class (5 points)
// Part 1: Create a child class of the Room class named 'Noble'
//creates child class called Noble
class Noble : public Room
{


	// Part2: Declare constructor which accepts the same 3 parameters as the parent class Room's constructor.
	// Pass the 3 parameters to the super constructor of the Room class.
	//Declares constructor for Noble and takes same 3 parameters as the parent class Room's constructor
public:Noble(string roomName, int noOfRooms, libraryType libType) : Room(roomName, noOfRooms, libType)
{

}

	  // Part 3: Re-declare the method displayRoom (virtual method found inside of parent class Room)
		//redeclares the method
	  void displayRoom();
};
#endif // _NOBLE_H_
