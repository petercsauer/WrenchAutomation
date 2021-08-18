# Code

The [MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide) was used in this project to program the [PIC32MX250F128B](../Docs/PIC32MX1XX2XX-28-36-44-PIN-DS60001168K.pdf) microcontoller. Code was written in C and programmed using the MPLab SNAP.

The code for this project is relatively straightforward with two main functions. One function is control of the servo by varying the PWM output on pin 6 of the PIC32. By changing the PWM, the servo will go to different positions. The other function is for movement of the stepper motor. This is done again through PWM. There are also four additional wires going to the Pololu DRV8834 board, three of which control microstepping and the last controls direction.

Overall, the code activates a 6X loop when a limit switch is pressed and each time it goes through the loop the wrench moves 60 degrees, the feeder pushes out a new jaw and the wrench wiggles twice to attempt to ensure that the jaws fall back into place. At the end of the loop, the mechanism swings back around 360 degrees in the opposite direction to get back to 0.
