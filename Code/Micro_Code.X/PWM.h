#ifndef PWM
#define PWM
 
#include<xc.h>           // processor SFR definitions
#include<sys/attribs.h>  // __ISR macro

 
void init_PWM(void);
void setDuty(float perc);
void setDutyWrench(float perc);

#endif