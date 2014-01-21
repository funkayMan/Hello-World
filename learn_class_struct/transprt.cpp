// program transprt.cpp, the main program,
// compile and run
#include <iostream>
using namespace std;
#include "vehicle.h"
// a user define header file and put it in the same folder as this program
void main()
{Cvehicle    car, motorcycle, truck, sedan_car;
// 4 objects instantiated
// data initialization
car.initialize(4,3000.0);
truck.initialize(20,30000.0);
motorcycle.initialize(2,900.0);
sedan_car.initialize(4,3000.0);

// display the data
cout<<"The car has "<<car.get_wheels()<< " tires.\n";
cout<<"Truck has load "<<truck.wheel_load()<<" kg per tire.\n";
cout<<"Motorcycle weight is  "<<motorcycle.get_weight()<<" kg.\n";
cout<<"Weight of sedan car is "<<sedan_car.get_weight()<<" kg, and has                                     "<<sedan_car.get_wheels()<<" tires.\n";
//system("pause");
}
