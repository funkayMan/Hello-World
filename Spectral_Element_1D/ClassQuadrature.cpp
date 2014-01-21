
/*
LGLquadrature.()
	abcissa  - Legendre Gauss-Lobatto abcissa
	weights - Gauss-Lobatto Weights
	nSize  - Polynomial Degree
	legPoly - Legendre Polynomials on the abcissa
	gamma - normalization parameters
	
Function performs calculation of quadrature and weights for Legendre-
Gauss-Lobatto Quadrature as outlined in "CALCULATION OF GAUSS 
QUADRATURE RULES" Gene H. Golub and John H. Welsch
	
ftp://reports.stanford.edu/pub/cstr/reports/cs/tr/67/81/CS-TR-67-81.pdf
	
	
To build this file use the command to compile:
g++ -I /home/wookie/eigen-3.0.5/ ClassQuadrature.cpp -o classquad

Use ./classquad to execute.

By: Tyler Arsenault
*/

#include <stdio.h>
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

class LGLquadrature {
	int nSize, nSize1;
	MatrixXf abcissa, weights, legPoly, gamma, t;
private:

	
public:
	// define and return matrix dimensions
	int setSize(int); //Allocate space for function which defines size
	int junk()	
	{return nSize;};
	
	// Make the T Matrix
	MatrixXf MakeTmatrix(){
		float fBeta = 1/sqrt(3);
		MatrixXf t(nSize1,nSize1);
		// initialize the t matrix
		for(int i = 0; i<nSize1;i++){
			for(int j=0;j<nSize1;j++){
				t(i,j)=0.0;}}	
		// Define the t matrix
		t(0,1)=fBeta; t(1,0)=fBeta;
		float ii=1; // this i is used for the calculation (not indexing)
		for(int i=1;i<nSize;i++){ii++;
			t(i+1,i) = sqrt((2*ii-1)/(2*ii+1))*ii/(2*ii-1);
			t(i,i+1) = t(i+1,i);}
		t(nSize,nSize-1) = sqrt(ii/(2*ii-1));
		t(nSize-1,nSize) = t(nSize,nSize-1);
		return t;
	}
};
// define matrix dimensions
int LGLquadrature::setSize(int matDim){nSize=matDim; nSize1=matDim+1;}

// try to make dummy matrix to bring through the LGLquad class





int main()
{	
	LGLquadrature funknast;
	funknast.setSize(2);
	cout<< "nSize = "<< funknast.junk()<<endl;
	cout<< "funkay matrix = \n"<< funknast.MakeTmatrix()<<endl;	
}




