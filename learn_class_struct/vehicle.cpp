// program vehicle.cpp, implementation part,
// compile without error, generating object file, do not run
#include "vehicle.h"

// class implementation part
// initialize to data input by user

void  Cvehicle::initialize(int input_wheels, float input_weight)
{
	wheels = input_wheels;
	weight = input_weight;
}
// get the number of wheels of this vehicle
int  Cvehicle::get_wheels()
{
return wheels;
}
// return the weight of this vehicle
float Cvehicle::get_weight(){
return  weight;
}
// return the load on each wheel
float  Cvehicle::wheel_load()
{
return  (weight/wheels);
}
