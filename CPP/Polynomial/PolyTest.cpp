//--- Test driver for class Polynomial
/***Author: Mark Suarin***/

#include <iostream>
using namespace std;
#include "Polynomial.h"

int main()
{

/***Constructs, reads and displays a polynomial***/
Polynomial A;
A.read(cin);
cout<<endl<<"Polynomial A is ";
A.display(cout);


/***Evaluates the polynomial***/
cout<<endl<<endl<<"The value of A with x=3 is "<<A.evaluate(3);

/***Copies old Polynomial to new Polynomial and displays new polynomial***/
Polynomial B=A;
cout<<endl<<endl<<"B is a copy of A. B is equal to ";
B.display(cout);

/***Uses the overloaded input and output functions***/
cout<<endl<<endl<<"This uses the overloaded output operator and displays A.";
cout<<endl<<A<<endl<<endl;

Polynomial C;
cin>>C;

cout<<"We have created a new Polynomial C using the overloaded input opeartor."<<endl;
cout<<"C is equal to "<<C<<endl;

/***Performs addition using Add operator***/

cout<<endl<<"A+C is equal to "<<A+C<<endl;


/***Performs multiplication using Multiply operator***/
cout<<endl<<"A*C is equal to "<<A*C;

}