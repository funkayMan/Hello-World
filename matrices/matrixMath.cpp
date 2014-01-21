#include<iostream>
#include <stdio.h>
using namespace std;
int main()
{	
	int nSize = 10;
	float fAmatrix[nSize][nSize];
	for(int i = 0; i<nSize;i++)
	{	
		for(int j=0;j<nSize;j++)
		{
			fAmatrix[i][j]=0;
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
