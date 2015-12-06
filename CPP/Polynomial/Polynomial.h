/***Header file for Polynomial class***/
/***by: Mark Suarin***/

#include <iostream>
using namespace std;

#ifndef POLYNOMIAL
#define POLYNOMIAL

typedef int CoefType;

class Polynomial
{
 public:

 /***Default Constructor***/
 Polynomial();				

/***Read and display functions***/
 void read(istream & in);		
 void display(ostream & out) const;

 /***Evaluate Function***/
 CoefType evaluate(CoefType value);

 /***Copy Constructors***/
 Polynomial(const Polynomial & other);
 Polynomial &operator=(const Polynomial &b);


/***Add function***/
Polynomial operator+(const Polynomial & poly);

/***Multiply function***/
Polynomial operator*(const Polynomial & poly);

 
 /***Destructor***/
 ~Polynomial();

 
 private:
	int myDegree;
	CoefType * myCoeff;
 

}; // end of class declaration





/***Overloaded input and output functions***/
ostream & operator<<(ostream & out, const Polynomial & p);
istream & operator>>(istream & in, Polynomial & p);

#endif