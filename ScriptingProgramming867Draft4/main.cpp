#include <iostream>													//PA Rubric B: C++ project with six required files
#include "roster.h"
using namespace std;



int main()

{	
	cout << "C867-Scripting & Programming: Applications" << endl;      // (PA Rubric F1)
	cout << "Language C++" << endl;
	cout << "Student ID:  000786932" << endl;
	cout << "Name: Amy Couture" << endl << endl;

	


	const string studentData[5] = {"A1,John,Smith,John1989@g ail.com,20,30,35,32,SECURITY",
								   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,52,NETWORK",
								   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,22,SOFTWARE",
								   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,52,SECURITY",
								   "A5,Amy,Couture,amy.couture@gmail.com,45,15,12,20,SOFTWARE" };   //PA Rubric A: My Personal Information

	Roster classRoster;	     //Creating an instance of the Roster class  (PA Rubric F2)

	for (int i = 0; i < 5; i++)
		{
		classRoster.parse(studentData[i]);      //Calling the parse funtion in the Roster class. Rubric F3. This code is from the WGU video in Tip #9 w/ Amy Antonucci 
		
		}
	
	//Below are the function calls in order for PA Rubric F4

	//Displaying all students section. This loops through all students in the array and calls the print function 
	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	cout << endl;


	//Displaying invalid emails section
	cout << "Displaying invalid emails:" << endl << endl;
	classRoster.printInvalidEmails();
	cout << endl << endl;


	//Displaying average days in course for each student in the array
	for (int i = 0; i < 5; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	//Displaying only the students who are in the degree program: software
	cout << "Showing students in degree program: SOFTWARE" << endl << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	
 
	//This is the section for removing student A3  and shows use of getters (PA Rubric D2C)
	classRoster.remove("A3");
	classRoster.printAll();   
	cout << endl;
	cout << "Removing A3 again" << endl << endl;
	classRoster.remove("A3");

	classRoster.~Roster();      //Implementing the destructor (PA Rubric F5)

	}
	
