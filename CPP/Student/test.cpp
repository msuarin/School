#include <iostream>
#include <string>
using namespace std;
#include "StudentRecord.h"

int main()
{
StudentRecord a;
int opt=1;
cout<<"\n\n****************************\n";
cout<<"STUDENT DATABASE MENU";
cout<<"\n0: Exit\n";
cout<<"1: Add a record\n";
cout<<"2: Delete a record\n";
cout<<"3: Print the whole database\n";
cout<<"4: Load database from a file\n";
cout<<"5: Save database to a file\n";
cout<<"****************************\n\n";

while(opt>0)
{
cout<<"\nEnter your option: ";
cin >> opt;
cin.ignore();

if(opt==1)
{
a.addStudent(cin);
}//end if 1

if(opt==2)
{
a.delStudent();
}//end if 2

if(opt==3)
{
a.show(cout);
}//end if 3


}//end while

}//end main