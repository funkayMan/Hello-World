/*  Example Program Simple Class Example Program In C++
    little drops @ thiyagaraaj.com

    Coded By:THIYAGARAAJ MP                             */

// Header Files
#include <iostream>
#include<conio.h>
using namespace std;

// Class Declaration
class person
{
//Access - Specifier
public:

//Varibale Declaration
  string name;
  int number;
};

//Main Function
int main()
{
    // Object Creation For Class
    person obj;

    //Get Input Values For Object Varibales
    cout<<"Enter the Name :";
    cin>>obj.name;

    cout<<"Enter the Number :";
    cin>>obj.number;

    //Show the Output
    cout << obj.name << ": " << obj.number << endl;

    getch();
    return 0;
}
