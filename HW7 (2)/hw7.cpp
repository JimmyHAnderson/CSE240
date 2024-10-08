/*
*/
// CSE240 
// Be sure to add the standard header above.
// Write the compiler used: Visual studio or g++ (SELECT ONE AND INDICATE)


// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of rooms.
// Each room has name, number of rooms and library type (hayden or noble).
// This information is stored as an object of Room class. Class defined in room.h
// The classes Hayden and Noble are child classes of the Room class.
// When adding a new room, these child classes are used to make the room node of the list.
// So each node in the list is actually an object of either Hayden or Noble class.

//
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// Do not modify given code.

// You can assume that all input is valid:
// Valid name:	String containing alphabetical letters
// Valid number: a positive integer

#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
#include "room.h"
#include "noble.h"
#include "hayden.h"

using namespace std;

// functions already implemented:
void executeAction(char c);
Room* searchRoom(string name_input);


// functions that need implementation:
void addRoom(string name_input, int no_input, libraryType type);			// 7 points
void displayList();							// 4 points
void save(string fileName);					// 7 points
void load(string fileName);					// 7 points

Container* list = NULL;				// global list

int main()
{
	char c = 'i';				// initialized to a dummy value

  // During first execution, there will be no list.txt in source directory. list.txt is generated by save() while exiting the program.
	load("list.txt");
	do {
		cout << "\nCSE240 HW10\n";
		cout << "Please enter your selection:\n";
		cout << "\t a: add a new room\n";
		cout << "\t d: display room list\n";
		cout << "\t c: change library type\n";
		cout << "\t q: quit\n";
		cin >> c;
		cin.ignore();
		executeAction(c);
	} while (c != 'q');

	save("list.txt");

	list = NULL;

	return 0;
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	int no_input;
	int type_input = 2;
	libraryType type;
	Room* roomResult = NULL;

	switch (c)
	{
	case 'a':	// add room
				// input room details from user
		cout << endl << "Enter room name: ";
		getline(cin, name_input);
		cout << "Enter number of rooms: ";
		cin >> no_input;
		cin.ignore();

		while (!(type_input == 0 || type_input == 1))
		{
			cout << "Enter library type: " << endl;
			cout << "0. Hayden " << endl;
			cout << "1. Noble" << endl;
			cin >> type_input;
			cin.ignore();
		}
		type = (libraryType)type_input;

		// searchRoom() will return the room object if found, else returns NULL
		roomResult = searchRoom(name_input);
		if (roomResult == NULL)
		{
			addRoom(name_input, no_input, type);
			cout << endl << "Room added to list!" << endl << endl;
		}
		else
			cout << endl << "Room already present in the list!" << endl << endl;

		break;

	case 'd':		// display the list
		displayList();
		break;

	case 'c':		// change room type
		cout << endl << "Enter room name: ";
		getline(cin, name_input);
		// searchRoom() will return the room node if found, else returns NULL
		roomResult = searchRoom(name_input);
		if (roomResult == NULL)
		{
			cout << endl << "Room not in list!" << endl << endl;
		}
		else
		{
			// if room exists in the list, then ask user for new number of rooms
			cout << endl << "Enter new library type: " << endl;
			cout << "0. Hayden " << endl;
			cout << "1. Noble" << endl;
			cin >> type_input;
			cin.ignore();
			type = (libraryType)type_input;
			// Q3c Call changeLibraryType() here   (1 point)
			// 'roomResult' contains the room whose Library Type is to be changed.
			// Call the function with appropriate arguments.

			changeLibraryType(roomResult, type);
			cout << endl << "Library type changed lil bro!" << endl << endl;
		}
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

// No implementation needed here, however it may be helpful to review this function
Room* searchRoom(string name_input)
{

	Container* tempList = list;			// work on a copy of 'list'

	while (tempList != NULL)			// parses till end of list
	{
		if (tempList->room->getName() == name_input)
		{
			return tempList->room;	// returns the room if it's found
		}
		tempList = tempList->next;		// parses the list
	}

	return NULL;						// returns NULL if room not found in list
}

// Q3b: Define Friend Function changeLibraryType()  (3 points)
// Define the function changeLibraryType()that is declared in room.h file.
// This function sets the new library type for the room. The room object and new library type (as integer) are to be passed as function arguments.
// Use 'd' display option after using 'c' option to verify.
// You will need to implement add() and displayList() before you test this function.
void changeLibraryType(Room* room, int newLibraryType){
	//parses integer to enum to make it easier
	if (newLibraryType == 0)
	{
		room->lib = hayden; // changes the room to hayden
	}
	else
	{
		room->lib = noble; // changess the room to noble
	}

}
// Q4: addRoom  (7 points)
// This function is used to add a new room to the global linked list 'list'. You may add the new room to head or tail of the list. (Sample solution adds to tail)
// libraryType 'type' can be hayden or noble. You will need to use the function argument �type� to determine which constructor to use to create new room node.
// For example, if the user enters type as 'noble', then you need to use Noble class and constructor to create new room node and add it to the list.
// NOTE: In executeAction(), searchroom() is called before this function. Therefore no need to check here if the room exists in the list.
//       See how this fucntion is called in case 'a' of executeAction()

void addRoom(string name_input, int no_input, libraryType type)
{
	Container* tempList = list;				// work on a copy of 'list'
	Room* newRoom;

	if (type == 0) // depending on type, we can change the room between hayden or noble
	{
		newRoom = new Hayden(name_input, no_input, type); // making the new room into hayden
	}
	else
	{
		newRoom = new Noble(name_input, no_input, type); // making the new room into noble
	}
	if (tempList == NULL)
	{ // if this is empty, moved to front
		tempList = new Container(); // making temp list a new container
		tempList->room = newRoom; // moving the node to a new room
		list = tempList; // making list into temp list
	}
	else
	{
		tempList = new Container();// adding to the next position
		tempList->room = newRoom;
		tempList->next = list;
		list = tempList;
	}
}

// Q5: displayList	(4 points)
// This function displays the list of room and their details (name, no, library name)
// Parse the list and use the class member function to display the room info.
// See expected output in the question file.

void displayList()
{
	Container* tempList = list;			// work on a copy of 'list'
	while (tempList != NULL) {
		cout << "Name: " << tempList->room->getName() << endl;
		cout << "Number of rooms: " << tempList->room->getNo() << endl;
		cout << "Library type: " << (tempList->room->getLibraryType() == hayden ? "Hayden" : "Noble") << endl;
		tempList = tempList->next;
	}
}

// Q6: save  (7 points)
// Save the linked list of rooms to a file list.txt using ofstream.
// You will need to save the number of rooms in linked list. That will help in load() when reading the file.
// One format to store is:
// <no. of rooms>
// <Room1 name>
// <Room1 no>
// <Room type>
// <Room2 name>
// <Room2 no>
// <Room2 type>
// and so on..
// You may store the list in another format if you wish. You need to read the file in load () the same way that it is saved in save().
// This function is called when exiting the program (end of main() ).
// Hint: You may want to cast the enum �libraryType� to an int before writing it to the file.


void save(string fileName)
{
	Container* tempList = list;
	int count = 0;
	ofstream fileA;

	while (tempList != NULL) { //gets length of list ie. number of rooms
		tempList = tempList->next;
		count++;                
	}
	fileA.open(fileName);
	tempList = list;
	fileA << count << endl;  //count is wrriten onto the file
	while (tempList != NULL) {
		fileA << tempList->room->getName() << endl; //writes room name
		fileA << tempList->room->getNo() << endl;  //writes room number
		fileA << tempList->room->getLibraryType() << endl;  //writes room type 
		tempList = tempList->next;

	}
	fileA.close(); //closes the stream
}

// Q7: load (7 points)
// Load the linked list of rooms from the file using ifstream.
// You will need to create the linked list in the same order that is was saved to the file in save().
// First, read the number of rooms saved in the file.
// Then, for every room you will need to create a new Room node depending on room type. You may add the room to head or tail of the list. 
// Hint: If you casted the enum 'libraryType' to an int, you will need to cast it back to 'libraryType' when making the room node.
// This function is called at the beginning of main().

void load(string fileName)
{
	int count = 0;
	int no;
	int type;
	string name;
	ifstream fileA;
	fileA.open(fileName);
	if (fileA.is_open()) { //checks if the file even exists or not
		fileA >> count;
		for (int i = 0; i < count; i++) { // loop for how many number of rooms
			if (getline(fileA, name, '\n')) { //checks to see if lists is empty
				getline(fileA, name, '\n'); //this reads the whole line till end since \n specifies end of line
			}
			fileA >> no;  //gets phrase from the file and stores it
			fileA >> type;// ^^
			addRoom(name, no, (libraryType)type);
		}
		fileA.close(); //closes
	}
}
