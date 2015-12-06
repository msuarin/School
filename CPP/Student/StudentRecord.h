#include <iostream>
#include <string>
using namespace std;

#ifndef STUDENTRECORD
#define STUDENTRECORD

//StudentRecord manipulates a linked list using nodes
class StudentRecord
{

	/***Student class***/
	private:
	//the class Student represents the student records
	class Student
	{
	public:
		string sName;
		string sID;
		string sEmail;
		int sEssay1;
		int sEssay2;
		int sProject;
		Student * next;
	};
	
	typedef Student * StudentPointer;

public:

/***Default Constructor***/
StudentRecord();

//add a student
void addStudent(istream & in);
//print database
void show(ostream & out) const;

//delete a Student Record
void delStudent();





/***Destructor***/
//~StudentRecord();


/***StudentRecord's data members***/
private:
StudentPointer first;	//points to first record
int mySize;				//number of records


};

#endif
