#pragma once
#include "student.h"
#include <iostream>



class Roster        //this is the class Roster definition with data members and declarations of the member functions 
{	 
	
	 public: 
		Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };   //this will hold the data from the studentData (Rubric: E1)
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysinCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void remove(string studentID);
		void printAll();   //this arranges the printing into a tab-separated list 
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void parse(string row);
		void printByDegreeProgram(DegreeProgram degreeProgram);
		int i = -1;
		~Roster();


};



