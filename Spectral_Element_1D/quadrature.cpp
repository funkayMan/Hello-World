/*
[fX,fWeight] = legendreQuad(nSize)
	fX  - Gauss-Lobatto Points
	fWeight - Gauss-Lobatto Weights
	nSize  - Polynomial Degree
	
Function performs calculation of quadrature and weights for Legendre-
Gauss-Lobatto Quadrature as outlined in "CALCULATION OF GAUSS 
QUADRATURE RULES" Gene H. Golub and John H. Welsch
	
ftp://reports.stanford.edu/pub/cstr/reports/cs/tr/67/81/CS-TR-67-81.pdf
	
	
To build this file use the command:
g++ -I /home/wookie/eigen-3.0.5/ quadrature.cpp -o quadrature

By: Tyler Arsenault
*/

#include <stdio.h>
#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{	
	// Initialize the size variables
	int nSize=5;
	int nSize1=nSize+1;
	// Initialize the function call and the outputted variable
	MatrixXf legendreQuad(int nSize1);
	MatrixXf LegQuad(nSize1,2);
	
	// Call the function to get the quadrature
	LegQuad=legendreQuad(nSize);
	

	// print the quadrature for varification
	cout << LegQuad << endl;
}
// Compute the quadrature/abcissa and weights
MatrixXf legendreQuad(int nSize)
{
	int nSize1=nSize+1;
	// intialize storage for T
	MatrixXf t(nSize1,nSize1);
	// Allocate space for function
	MatrixXf buildTmatrix (int nSize);
	
	// Call the T matrix building function to build matrix T.
	t=buildTmatrix(nSize);
	
	// decompose our t matrix using eigen stuff
	SelfAdjointEigenSolver<MatrixXf> eigensolver(t);
	if (eigensolver.info() != Success) abort();
	MatrixXf feigenvalues = eigensolver.eigenvalues();
	MatrixXf feigenvectors = eigensolver.eigenvectors();
	// This section makes a compounded variable
	MatrixXf LegQuad(nSize1,2);
	for(int i=0;i<nSize1;i++)
	{
		// Weights
		LegQuad(i,0)=2*feigenvectors(0,i)*feigenvectors(0,i);
		// Abcissa
		LegQuad(i,1)=-1*feigenvalues(i);
	}
	//~ cout << feigenvectors << endl;
	return LegQuad;
}

// Build the T matrix
MatrixXf buildTmatrix (int nSize)
{
	int nSize1=nSize+1;			//init. n+1
	MatrixXf t(nSize1,nSize1);	//init. Legendre Polys
	float fBeta = 1/sqrt(3);
	// initialize the t matrix
	for(int i = 0; i<nSize1;i++)
	{	
		for(int j=0;j<nSize1;j++)
		{
			t(i,j)=0.0;
		}
	}	
	// Define the t matrix
	t(0,1)=fBeta;
	t(1,0)=fBeta;
	float ii=1; // this i is used for the calculation (not indexing)
	for(int i=1;i<nSize;i++)
	{
		ii++;
		t(i+1,i) = sqrt((2*ii-1)/(2*ii+1))*ii/(2*ii-1);
		t(i,i+1) = t(i+1,i);
		
	}
	t(nSize,nSize-1) = sqrt(ii/(2*ii-1));
	t(nSize-1,nSize) = t(nSize,nSize-1);
	return t;
}
