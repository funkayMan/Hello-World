// a class declaration part, vehicle.h, header file
// save and include this file in your next project
// do not compile or run

#ifndef  VEHICLE_H   // preprocessor directive

#define  VEHICLE_H

// class declaration part – the interface

class Cvehicle
{
      protected:
           int  wheels;
           int  weight;
      public:
	void  initialize(int input_wheels, float input_weight);
        int   get_wheels(void);
        float get_weight(void);
	float wheel_load (void);
};
#endif
