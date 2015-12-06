#include <iostream>
#include <string>
using namespace std;

#include "StudentRecord.h"

/***Default Constructor***/
StudentRecord::StudentRecord()
{
	first=0;
	mySize=0;
}


void StudentRecord::addStudent(istream & in)
{
	
	StudentPointer ptr;
	ptr = new Student;
	
	ptr->next=first;
	first=ptr;
	mySize++;
	
	cout<<"Enter student name: ";
	getline(cin, ptr->sName, '\n');
	
	
	cout<<"Enter student ID number(precede number with 'u'): ";
	cin>>ptr->sID;
	
	cout<<"Enter student email address: ";
	cin>>ptr->sEmail;
	
	cout<<"Enter student's grade for first essay(Enter an integer from 0 to 4, enter 0 if not yet graded): ";
	cin>>ptr->sEssay1;
	
	cout<<"Enter student's grade for second essay(Enter an integer from 0 to 4, enter 0 if not yet graded): ";
	cin>>ptr->sEssay2;
	
	cout<<"Enter student's grade for project(Enter an integer from 0 to 4, enter 0 if not yet graded): ";
	cin>>ptr->sProject;
	cin.ignore();

}

void StudentRecord::delStudent()
{
	StudentPointer ptr;
	ptr = first;
	first = ptr->next;
	delete ptr;
	mySize--;
}

void StudentRecord::show(ostream & out) const
{
StudentPointer ptr;
ptr=first;

if(mySize<1)
out<<"There are no records\n";
else
{
while(ptr!=0)
{
out<<ptr->sName;
out<<" "<<ptr->sID;
out<<" "<<ptr->sEmail;
out<<" "<<ptr->sEssay1;
out<<" "<<ptr->sEssay2;
out<<" "<<ptr->sProject;
out<<" "<<ptr->next;
out<<"\n"<<mySize<<"\n";
ptr=ptr->next;
}
}
}
	