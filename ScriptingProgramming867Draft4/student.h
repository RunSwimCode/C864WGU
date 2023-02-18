#include "degree.h"
#include <iostream>

using namespace std;

//PA Rubric D1: Student class is created with required variables
//This is the Student class definition with the public and private data members and the declarations of the member functions
class Student
{
	private: 
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int* numDays;
		DegreeProgram degreeProgram;

	public:
		Student();   //Technically not a default constructor... it just has no arguments. Tip #14: this is necessary or will get error message
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram);
		
		//Below are the accessors for the Student class
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int* getnumDays();
		DegreeProgram getDegreeProgram();

		//Below are the mutators for the Studend class
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setnumDays(int numDays[]);
		void setDegreeProgram(DegreeProgram degreeProgram);
		void print();
		~Student();

};

