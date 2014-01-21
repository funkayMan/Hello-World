// arrays as parameters
#include <iostream>
using namespace std;
#include <fstream>
// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

int main () 
{
  FILE * f;
  f = fopen("matrix.txt", "w");
  int N=5;
  for (int i = 0; i < N;  i++)
  {
    for (int j = 0; j < N;  j++)
    {
      fprintf(f,"%2x",[i][j],i*j);
    }
  }
}