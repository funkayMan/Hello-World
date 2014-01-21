#include <iostream>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;
int main()
{
int nsize=5;
MatrixXf A(nsize,nsize);
MatrixXf makeAmatrix(int nsize);
A=makeAmatrix(nsize);

cout << "Here is the matrix A:\n" << A << endl;
SelfAdjointEigenSolver<MatrixXf> eigensolver(A);
if (eigensolver.info() != Success) abort();
/*cout << "The eigenvalues of A are:\n" << eigensolver.eigenvalues() << endl;
cout << "Here's a matrix whose columns are eigenvectors of A \n"
<< "corresponding to these eigenvalues:\n"
<< eigensolver.eigenvectors() << endl;*/

MatrixXf junk;
junk=eigensolver.eigenvalues();
//float m=junk(1,5);
cout << "The eigenvalues of A are:\n" << junk(1) << endl;
}

MatrixXf makeAmatrix(int nsize)
{ 
	MatrixXf A(nsize,nsize);
	for(int i =0; i<nsize;i++)
	{
		for(int j=0;j<nsize;j++)
		{
			A(i,j)=i*j;
		}
	}
return A;
}
