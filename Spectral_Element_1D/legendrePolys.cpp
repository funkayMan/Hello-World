#include<iostream>
#include <stdio.h>
using namespace std;
/* Function to return the Gauss-Lobotto quadrature for the
Legendre polynomials.
Arguments:
	nSize   - Degree of the polynomials to be used
Returns:
	nSize1- N + 1
	fLval - Values of the Legendre polynomials on the abscissa
			fLval(i,j) = value of Legendre polynomial i on the 
			abscissa point j.
	fXlegendre - abscissa of the quadrature
	fWeight    - Weight of the quadrature
	fGamma - Normalization.  Value of the integral on [-1,1] of the 
			square of the Legendre polynomials.
*/
int main()
{	
	int nSize = 10;
	float fAmatrix[nSize][nSize];
	for(int i = 0; i<nSize;i++)
	{	
		for(int j=0;j<nSize;j++)
		{
			fAmatrix[i][j]=i*j;
		}
	}
	// Print Matrix to file
	FILE * (file);
	file=fopen("matrix_out.txt","w");
	for(int i = 0; i<nSize;i++)
	{	
		for(int j=0;j<nSize;j++)
		{
			fprintf (file, "%f \t",fAmatrix[i][j]);
		}
		fprintf (file,"\n");
	}
	fclose (file);
}
