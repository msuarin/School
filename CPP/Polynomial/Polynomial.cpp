//----- Polynomial.cpp ------
/***Implementation for Polynomial.h***/
/***Author: Mark Suarin***/


#include <iostream>
using namespace std;

#include "Polynomial.h"


/***Default Constructor***/
Polynomial::Polynomial()
{
	myDegree=-1;
	myCoeff=new int[1];
}


/***Reads and sets degree and coefficients***/
void Polynomial::read(istream & in)
{
	int degree;
	int size;
	
	cout<<"Enter the Degree (<=30): ";
	in >> degree;

	//check
	if(degree>=0 && degree<=30)
	{
	 myDegree=degree;
	 size=degree+1;

	myCoeff= new int[size];
	cout<<"Enter " << size <<" coefficients in ascending order: ";

	for(int i=0; i<size; i++)
		{
	 	 cin>>myCoeff[i];
		}

	}

	 else {
	   cerr << "Invalid Degree. \n";}

}


/***Displays the polynomial in ascending format***/
void Polynomial::display(ostream & out) const
{
	int size=myDegree+1;

	for(int i=0; i<size; i++)
	{
	 if(i==0){
		if(myCoeff[i]!=0){
			out<<myCoeff[i]<<" ";
		}
	 }
	 else{
		if(myCoeff[i]!=0 && myCoeff[i]>0){
			out<<"+"<<myCoeff[i]<<"x^"<<i<<" ";
		 }
		else{
			if(myCoeff[i]!=0){
			out<<myCoeff[i]<<"x^"<<i<<" ";
			}
		}
	      }
	 }

	
}


/***Evaluates the value of the polynomial for a given x value***/
int Polynomial::evaluate(int value)
{
	int total;
	int size=myDegree+1;

	for(int i=0;i<size;i++)
	{
		if(i==0){
			total=myCoeff[0];
		}
		else{
			int powerval=value;
			for(int j=1;j<i;j++){
				powerval*=value;
			}
			total=total+(myCoeff[i]*powerval);
		}
	}
	return total;
}





/***Copy Constructors***/
Polynomial::Polynomial(const Polynomial & other)
{
	myDegree=other.myDegree;
	int size=myDegree+1;

	myCoeff= new int[size];
	for(int i=0; i<size; i++)
	{
	 myCoeff[i]=other.myCoeff[i];
	}
}


Polynomial& Polynomial::operator=(const Polynomial & b)
{
	myDegree=b.myDegree;
	int size=myDegree+1;

	myCoeff= new int[size];
	for(int i=0; i<size; i++)
	{
	 myCoeff[i]=b.myCoeff[i];
	}
	return *this;
}




/***Add Function***/
Polynomial Polynomial::operator+(const Polynomial & poly)
{
	int hsize, lsize;
	int * nCoeff;
	if((myDegree+1)>=(1+poly.myDegree)){
		hsize=myDegree+1;
		lsize=1+poly.myDegree;
		nCoeff= new int[hsize];
	}
	else{
		hsize=1+poly.myDegree;
		lsize=myDegree+1;
		nCoeff= new int[hsize];
	}

	for(int i=0; i<lsize; i++){
		nCoeff[i]=myCoeff[i]+(poly.myCoeff[i]);
	}
	
	if(hsize!=lsize && (myDegree+1)>(1+poly.myDegree)){
		for(int j=lsize; j<hsize; j++){
			nCoeff[j]=myCoeff[j];
		}
	}
	else{
		for(int j=lsize; j<hsize; j++){
			nCoeff[j]=(poly.myCoeff[j]);
		}
	}

	Polynomial nPoly;
	nPoly.myDegree=hsize-1;
	nPoly.myCoeff= new int[hsize];
	for(int m=0;m<hsize;m++)
	{
		nPoly.myCoeff[m]=nCoeff[m];
	}
	return nPoly;
}



/***Multiplication Function***/
Polynomial Polynomial::operator*(const Polynomial & poly)
{
	int nDegree=myDegree+(poly.myDegree);
	int size=nDegree+1;
	int k;
	int * nCoeff= new int[size];

	for(int m=0; m<size; m++)
	{
		nCoeff[m]=0;
	}

	for(int i=0; i<(myDegree+1); i++)
	{
		for(int j=0; j<((poly.myDegree)+1); j++)
		{
			k=i+j;
			nCoeff[k]+=myCoeff[i]*(poly.myCoeff[j]);
		}
	}
	
	Polynomial nPoly;
	nPoly.myDegree=nDegree;
	nPoly.myCoeff= new int[size];
	for(int n=0;n<size;n++)
	{
		nPoly.myCoeff[n]=nCoeff[n];
	}
	return nPoly;		
}	


/***Overloaded input and output operators***/
ostream & operator<<(ostream & out, const Polynomial & p)
{
	p.display(out);
	return out;
}

istream & operator>>(istream & in, Polynomial & p)
{
	p.read(in);
	return in;
}

/***Destructor***/
Polynomial::~Polynomial()
{
}






