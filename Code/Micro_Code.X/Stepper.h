#ifndef _STEPPER_H   
#define _STEPPER_H

#include<xc.h>           // processor SFR definitions
#include<sys/attribs.h>  // __ISR macro

#define STEPS 19

void Stepper_Setup(void); //Set up the GPIO pins to control motor.
void Step_60(int dir);          //Step 60 degrees
void Step(int dir);
void Stop(void);
void Step_Back(int dir);

#endif