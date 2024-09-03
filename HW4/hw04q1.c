/*
  
*/

// READ BEFORE YOU START:
// You are given a partially completed program that creates a list of students, like students' record.
// We use the word list in a general sense here - it is really a collection of students stored in an array of structs.
// Each student record has this information: student's name, major, school year of student, ID.
// The struct 'studentRecord' holds information of one student. School year is enum type.
// An array of structs called 'list' is made to hold the list of students.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.

// WRITE COMMENTS FOR IMPORANT STEPS IN YOUR CODE.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) // for Visual Studio Only

#define MAX_STUDENTS 15
#define MAX_NAME_LENGTH 25

typedef enum { freshman = 0, sophomore, junior, senior } schoolYear; // enum type 

struct studentRecord {					// struct for student details
	char studentName[MAX_NAME_LENGTH];
	char major[MAX_NAME_LENGTH];
	schoolYear schoolYear;
	unsigned int studentID;
};

struct studentRecord list[MAX_STUDENTS]; // declare list of students
int count = 0;							// the number of students currently stored in the list (initialized to 0)

// functions already implmented
void flushStdIn();
void executeAction(char);
void save(char* fileName);

// functions that need implementation:
int addSort(char* studentName_input, char* major_input, char* schoolYear_input, unsigned int studentID_input); // 30 points
void display();				// 10 points
void load(char* fileName);	// 10 points

int main()
{
	char* fileName = "Student_List.txt";
	load(fileName);	// load list of students from file (if it exists). Initially there will be no file.
	char choice = 'i';		// initialized to a dummy value
	do
	{
		printf("\nEnter your selection:\n");
		printf("\t a: add a new student\n");
		printf("\t d: display student list\n");
		printf("\t q: quit\n");
		choice = getchar();
		flushStdIn();
		executeAction(choice);
	} while (choice != 'q');

	save(fileName); // save list of students to file (overwrites file, if it exists)
	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// ask for details from user for the given selection and perform that action
void executeAction(char c)
{
	char studentName_input[MAX_NAME_LENGTH], major_input[MAX_NAME_LENGTH];
	unsigned int studentID_input, add_result = 0;
	char schoolYear_input[20];
	switch (c)
	{
	case 'a':
		// input student record from user
		printf("\nEnter student name: ");
		fgets(studentName_input, sizeof(studentName_input), stdin);
		studentName_input[strlen(studentName_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter major: ");
		fgets(major_input, sizeof(major_input), stdin);
		major_input[strlen(major_input) - 1] = '\0';	// discard the trailing '\n' char

		printf("Enter whether students is 'freshman' or 'sophomore' or 'junior' or 'senior': ");
		fgets(schoolYear_input, sizeof(schoolYear_input), stdin);
		schoolYear_input[strlen(schoolYear_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter student ID number: ");
		scanf("%d", &studentID_input);
		flushStdIn();

		// add the student to the list
		add_result = addSort(studentName_input, major_input, schoolYear_input, studentID_input);
		if (add_result == 0)
			printf("\nStudent is already on the list! \n\n");
		else if (add_result == 1)
			printf("\nStudent successfully added to the list! \n\n");
		else
			printf("\nUnable to add. Student list is full! \n\n");

		break;
	case 'd': display();	break;
	case 'q': break;
	default: printf("%c is invalid input!\n", c);
	}
}

// Q1 : addSort (30 points)
// This function is used to add a student into the list and making sure the list is sorted at all times.
// The list has to be sorted at all times. You can add the student at the end of the list and then sort the list.
// Sort can be implemented as a different method and called it every you add a record.
// Use a temp struct (already declared) if you need to swap two structs in your logic.
// Do not allow the student to be added to the list if they already exist in the list. You can do that by checking student names already in the list.
// If the student already exists then return 0 without adding it to the list. If the student does not exist in the list then go on to add the student at the end of the list, sort the list and return 1.
// If student list is full, then do not add new student to the list and return 2.
// NOTE: Notice how return type of addSort() is checked in case 'a' of executeAction()
// NOTE: You must convert the string 'schoolYear_input' to an enum type and store it in the list because the school year has enum type (not string type).
// The list should be case sensitive. For instance, 'Roger' and 'roger' should be considered two different names.
// Hint: 'count' holds the number of students currently in the list
int addSort(char* studentName_input, char* major_input, char* schoolYear_input, unsigned int studentID_input)
{
	// checks if the list is full
	if (count == MAX_STUDENTS) {
		printf("not enough funding for more students.\n");
		return 0;
	}
	// checks to see if a student already exists
	for (int i = 0; i < count; ++i) {
		if (strcmp(list[i].studentName, studentName_input) == 0) {
			printf("Sorry no clones allowed bro\n");
			return 0;
		}
	}
	// converts input from school year to a digit(example: freshman =0 ect. ect.)
	schoolYear year;
	if (strcmp(schoolYear_input, "freshman") == 0) {
		year = freshman;
	}
	else if (strcmp(schoolYear_input, "sophomore") == 0) {
		year = sophomore;
	}
	else if (strcmp(schoolYear_input, "junior") == 0) {
		year = junior;
	}
	else if (strcmp(schoolYear_input, "senior") == 0) {
		year = senior;
	}
	else {
		printf("Error: sorry, no super seniors allowed\n");
		return 0;
	}

	// add student record to list
	strcpy(list[count].studentName, studentName_input);
	strcpy(list[count].major, major_input);
	list[count].schoolYear = year;
	list[count].studentID = studentID_input;
	count++;

	// sort list by student name using bubblesort(ty Zybooks LOL)
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (strcmp(list[j].studentName, list[j + 1].studentName) > 0) {
				struct studentRecord temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	return 1;
}


// Q2 : display (10 points)
// This function displays the student list with the details (struct elements) of each student. 
// Parse through the list and print the student details one after the other. See expected output screenshots in the PDF file.
// NOTE: School year is stored in the struct as enum type. You need to display 'freshman','sophomore', 'junior' or 'senior'
void display()
{
	// checks if the list is empty
	if (count == 0) {
		printf("no students lil bro.\n");
	}
	else {
		printf("Student List:\n");
		// iterates through the list and prints out stats
		for (int i = 0; i < count; i++) {
			printf("Name: %s, Major: %s, Year: %d, ID: %d\n", list[i].studentName, list[i].major, list[i].schoolYear, list[i].studentID);
		}
	}
}


// save() is called at the end of main()
// This function saves the array of structures to file. It is already implemented.
// You should read and understand how this code works. It will help you with 'load()' function.
// save() is called at end of main() to save the student list to a file.
// The file is saved at the same place as your C file. For VS, the default directory looks like this:
// C:\Users\<username>\Documents\Visual Studio 2019\Projects\Project1\Project1
// or
// C:\Users\<username>\source\repos\Project1
// You can simply delete the file to 'reset the list' or to avoid loading from it.
void save(char* fileName)
{
	FILE* file;
	int i, schoolYearValue = 0;
	file = fopen(fileName, "wb");		// open file for writing

	fwrite(&count, sizeof(count), 1, file);		// First, store the number of students in the list

	// Parse the list and write student record to file
	// 
	for (i = 0; i < count; i++)
	{
		fwrite(list[i].studentName, sizeof(list[i].studentName), 1, file);
		fwrite(list[i].major, sizeof(list[i].major), 1, file);
		// convert enum to a number for storing
		if (list[i].schoolYear == freshman)
			schoolYearValue = 0;		// 0 for freshman
		else if (list[i].schoolYear == sophomore)
			schoolYearValue = 1;		// 1 for sophomore
		else if (list[i].schoolYear == junior)
			schoolYearValue = 2;		// 2 for junior 
		else
			schoolYearValue = 3;		// 3 for senior

		fwrite(&schoolYearValue, sizeof(schoolYearValue), 1, file);
		fwrite(&list[i].studentID, sizeof(list[i].studentID), 1, file);
	}

	fclose(file);			// close the file after writing
}

// Q3:  load (10 points)
// This function is called in the beginning of main().
// This function reads the student list from the saved file and builds the array of structures 'list'. 
// In the first run of the program, there will be no saved file because save() is called at the end of program.
// So at the begining of this function, write code to open the file and check if it exists. If file does not exist, then return from the function.
// (See expected output of add() in homework question file. It displays "Student_List.txt not found" because the file did not exist initially.)
// If the file exists, then parse the student list to read the student details from the file.
// Use the save function given above as an example of how to write this function. Notice the order in which the struct elements are saved in save()
// You need to use the same order to read the list back.
// NOTE: The saved file is not exactly readable because all elements of the struct are not string or char type.
//       So you need to implement load() similar to how save() is implemented. Only then the 'list' will be loaded correctly.
//		You can simply delete the file to 'reset the list' or to avoid loading from it.
void load(char* fileName)
{
	// open file in write mode
	FILE* file = fopen(fileName, "rb");
	if (file == NULL)
	{
		printf("%s not found little bro\n", fileName);
		return; // Return if file doesn't exist
	}

	// Read the number of students from the file
	fread(&count, sizeof(count), 1, file);

	// Read student records from the file and populate the list
	for (int i = 0; i < count; i++)
	{
		fread(list[i].studentName, sizeof(list[i].studentName), 1, file);
		fread(list[i].major, sizeof(list[i].major), 1, file);

		int schoolYearValue;
		fread(&schoolYearValue, sizeof(schoolYearValue), 1, file);
		switch (schoolYearValue)
		{
		case 0:
			list[i].schoolYear = freshman;
			break;
		case 1:
			list[i].schoolYear = sophomore;
			break;
		case 2:
			list[i].schoolYear = junior;
			break;
		default:
			list[i].schoolYear = senior;
			break;
		}

		fread(&list[i].studentID, sizeof(list[i].studentID), 1, file);
	}

	fclose(file); // Close the file after reading
}
