#include <iostream>
#include <string>
#include "roster.h"
using namespace std;



//These are the member function definitions for the whole roster class  (PA Rubric E2A)
void Roster::parse(string studentData)         //This is from Tip #9 video at about 3:45
{
	
		size_t rhs = studentData.find(",");
		string studentID = studentData.substr(0, rhs);     //parsing the student ID from the string of data 

		size_t lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string firstName = studentData.substr(lhs, rhs - lhs);   //parsing the first name from the string of data

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string lastName = studentData.substr(lhs, rhs - lhs);   //parsing last name from the string 

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string emailAddress = studentData.substr(lhs, rhs - lhs);   //parsing email address

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int age = stoi(studentData.substr(lhs, rhs - lhs));   //parsing age from the string and changing from string to int 
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));    //parsing days #1 and changing string to int 

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));   //parsing days #2 and changing string to int  

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));   //parsing days #3 and changing string to int  

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		string strDegree = studentData.substr(lhs, rhs - lhs);      //parsing the degree  

		DegreeProgram degree = DegreeProgram::SECURITY;         //this hint is at Tip#9 video at 9:31
		if (strDegree == "NETWORK")
		{
			degree = DegreeProgram::NETWORK;
		}
		if (strDegree == "SOFTWARE")
		{
			degree = DegreeProgram::SOFTWARE;
		}

		this->add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);      //PA Rubric E2
	}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int avgDays[3];      //Here, I have changed the 3 integer days to an array, which will be needed by Roster
	avgDays[0] = daysInCourse1;
	avgDays[1] = daysInCourse2;
	avgDays[2] = daysInCourse3;

	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] == nullptr) {								//These are student objects for PA Rubric E2B and added for E3A

			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, avgDays, degreeProgram);
			break;
		}
	}
}


//output instructions for the "Displaying all Students" section    (PA Rubric E3C)
void Roster::printAll()
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			continue;
		}
		else {
			classRosterArray[i]->print();
		}
	}


}

//output instructions for the "Displaying Invalid Emails" section    (PA E3E)
void Roster::printInvalidEmails()
{

	bool invalid = false;

	for (int i = 0; i < 5; i++)
	{
		string emailAddress = classRosterArray[i]->getEmailAddress();
		if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos)) 
		{
			invalid = true;
			cout << classRosterArray[i]->getEmailAddress() << " -  is invalid." << endl;
		}

	
	}
}


//This adds and averages the number of days in three courses    (PA Rubric E3D) 
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getStudentID() == studentID)
			{
			cout << "Student ID: " << (classRosterArray[i]->getStudentID());
			cout << ", average days in course is: ";
			cout << ((classRosterArray[i]->getnumDays()[0] + classRosterArray[i]->getnumDays()[1] + classRosterArray[i]->getnumDays()[2]) / 3) << endl;
			}
	}
}   


//Instructions for displaying only the students in the software program    (PA E3F)
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < 5; i++)
	{  
		if
			(classRosterArray[i]->getDegreeProgram() == SOFTWARE)
			{
			classRosterArray[i]->print();   
		}
		
	}
	cout << endl;
}          

//Instructions for removing student A3    
void Roster::remove(string studentID)
{
	bool removed = false;
	for (int i = 0; i < 5; i++)
	{
		if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentID))
		{                                //If the student ID is found, then it becomes null and the list is printed without it
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			removed = true;
			cout << "Removing " << studentID << ":" << endl << endl;
			break;
		}
	}						//If removed already, the output will say it wasn't found and doesn't print anything
	if (!removed) {
		cout << "The student with the ID: " << studentID << " was not found." << endl;
	}
}

//Destructor
Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		classRosterArray[i] = nullptr;     //this will release the data in each iteration of the array 
	}
	cout << "DONE" << endl;
}      


