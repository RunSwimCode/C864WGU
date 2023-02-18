#include "student.h"
#include <iostream>
using namespace std;


//Step 6 of PA directions.
Student::Student()  {          // "no argument constructor" sets to defaults  (this is necessary to prevent error message)

	this->studentID = "";;
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
	
}     

//  This is the full constructor (PA Rubric D2D)
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->numDays = new int[3];
	for (int i = 0; i < 3; i++) {
		this->numDays[i] = numDays[i];
	}
	this->degreeProgram = degreeProgram;
}

//This is the destructor
Student::~Student() 
{

}

//Below is PA Rubric D2A
//Accessor: returns the student's ID number. 
string Student::getStudentID()
{
	return this->studentID;
}

//Accessor: returns the student's first name. 
string Student::getFirstName() 
{
	return this->firstName;
}

//Accessor: returns the student's last name. 
string Student::getLastName()
{
	return this->lastName;
}

//Accessor: returns the student's age. 
int Student::getAge()
{
	return this->age;
}

//Accessor: returns email address
string Student::getEmailAddress()
{
	return this->emailAddress;
}

//Accessor: returns number of days for 3 classes    
int* Student::getnumDays()
{
	return this->numDays;
}


//Accessor:  returns the student's degree program
DegreeProgram Student::getDegreeProgram()
{
return this->degreeProgram;
}

//Below is PA Rubric for D2B

	//Mutator: Sets the student's ID number. 
void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
	return;
}

//Mutator: Sets the student's first name
void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
	return;
}

//Mutator: Sets the student's last name 
void Student::setLastName(string lastName) 
{
	this->lastName = lastName;
	return;
}

//Mutator: Sets the student's email address
void Student::setEmailAddress(string emailAddress) 
{
	this->emailAddress = emailAddress;
	return;
}

//Mutator: Sets the student's age
void Student::setAge(int age)
{
	this->age = age;
	return;
}
//Mutator: Sets the number of days to complete each of three classes 

void Student::setnumDays(int numDays[])
{
	for (int i = 0; i < 3; i++)
		
		this->numDays[i] = numDays[i];
	return;
}



//Mutator: Sets the student's degree program 
void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
	return;
}


void Student::print()     //This is the print function in the Student class (PA Rubric D2E)
{

	string degree_string;

	if (degreeProgram == DegreeProgram::NETWORK)
	{
		degree_string = "NETWORK";
	}

	else if (degreeProgram == DegreeProgram::SECURITY)
	{
		degree_string = "SECURITY";
	}

	else if (degreeProgram == DegreeProgram::SOFTWARE)
	{
		degree_string = "SOFTWARE";
	}

	cout << getStudentID() << '\t';
	cout << getFirstName() << '\t' << '\t';
	cout << getLastName() << '\t' << '\t';
	cout << getAge() << '\t';
	cout << "{" << numDays[0] << "," << numDays[1] << "," << numDays[2] << "}" << '\t';
	cout << degree_string;
	cout << endl;

}



		
		
		
		