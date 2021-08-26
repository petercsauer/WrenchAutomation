# Electrical Design

This directory contains the eagle files that Levi created in his version of the device. My version did not modify his electronics besides the addition of a servo, the momentary addition of a second stepper motor and driver (which was later removed) and the removal of the electromagnet driver. 



## Microcontroller

For this project the [PIC32MX250F128B](../Docs/PIC32MX1XX2XX-28-36-44-PIN-DS60001168K.pdf) was used as the control unit for the process. It was used to control the stepper motor and servo and in the past was used to control an electromagnet, but ultimately it was decided to keep that on full time.

The breakout schematic from eagle for the process is shown below, which shows the 3.3V regulator, pololu dual h-bridge, micro usb connector (for power) and MPLAB SNAP (for programming). 

![PIC32_BREAKOUT](PIC32_BREAKOUT.png)

## Stepper Motor Driver

The circuitry used to control the stepper motor is the Pololu [MD20b](https://www.pololu.com/product/2133/resources) chip. This chip is a breakout board for the [DRV8825](../Docs/drv8825.pdf) which has two H-bridge
drivers and a microstepping indexer, along with some protective circuitry. This chip allows the stepper to be simply controlled by 3 GPIO pins to control the step resolution (M0,M1,M2) and one pin set to output a PWM signal (STEP). This chip also allows for 3.3V logic to be used from the microcontroller while supplying the motor with the 12V necesarry to use it. 

As can be seen in the [code](../Code) directory, pins M0, M1 and M2 are used to set the resolution at which the motor is controlled. Setting M0 and M1 high and M2 low sets the driver to control the motor in 1/8 step mode, meaning the 200-step-per-revolution motor now has 1600 microsteps per revolution. A PWM signal is sent to the STEP pin to drive the motor.

![STEPPER_MOTOR_DRIVER](STEPPER_MOTOR_DRIVER.png)

## Servo

A servo was added to the electronics part of this project. The servo had three wires, red, black and white which were connected to 5V, GND and pin 6 on the PIC32, respectively. A PWM signal was outputted to pin 6 which allows for control over the servo position. 

## Overall Layout

Here is a picture of the final layout of the system on it's breadboards. The smaller breadboard is running off of 12V (from an external supply) and the larger one runs off of USB which is converted to 3.3V by the Pololu voltage regulator you can see in the top center.
![STEPPER_MOTOR_DRIVER](../media/Electronics.jpg)

