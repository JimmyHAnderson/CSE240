#include "room.h"

// definitions of Room member functions
Room::Room(string roomName, int noOfRooms, libraryType libType)
{
	name = roomName;
	no = noOfRooms;
	lib = libType;
}

string Room::getName()
{
	return name;
}

int Room::getNo()
{
	return no;
}

libraryType Room::getLibraryType()
{
	return lib;
}
