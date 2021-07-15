#include "Setup.h"      //PIC
#include "Stepper.h"    //STEPPER MOTOR
#include"PWM.h"         //PWM

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    __builtin_disable_interrupts();
    // set the CP0 CONFIG register to indicate that kseg0 is cacheable (0x3)
    __builtin_mtc0(_CP0_CONFIG, _CP0_CONFIG_SELECT, 0xa4210583);
    // 0 data RAM access wait states
    BMXCONbits.BMXWSDRM = 0x0;
    // enable multi vector interrupts
    INTCONbits.MVEC = 0x1;
    // disable JTAG to get pins back
    DDPCONbits.JTAGEN = 0;
    //Make B4 and B2 an input (USER)
    TRISBbits.TRISB4 = 1;
    TRISBbits.TRISB3 = 1;
    //Make A4 an output (ELECMAGNET)
    TRISAbits.TRISA4 = 0;
    //Stepper Motor Setup (and PWM)
    Stepper_Setup();
    PWM_init();
    __builtin_enable_interrupts();

    LATAbits.LATA4 = 1;
    _CP0_SET_COUNT(0);

    //    Step_60();
    int trig = 0;
    int prev = 1;
    int dir = 1;
    int counter = 0;
    while (1) {

        if (prev == 0){
            Stop();
            int i = 0;
            while (i<6){ 
                Step_60(0);
                _CP0_SET_COUNT(0);
                while (_CP0_GET_COUNT() < 15000000) {
                }
                i++;
            }
            i = 0;
            while (i<6){ 
                Step_60(1);
                i++;
            }
            Step_Back(0);
            prev = 1;
        }else{
            prev = PORTBbits.RB4;
            Step(1);
        }






    }

}

