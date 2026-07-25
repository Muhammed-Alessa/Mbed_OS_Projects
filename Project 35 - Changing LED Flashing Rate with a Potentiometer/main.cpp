/*
 * Changing LED Flashing Rate with a Potentiometer
 * Board: NUCLEO-F446RE / STM32F446RET6
 * Framework: Arm Mbed OS 5.x style
 *
 * Independently rewritten study example.
 * The source book mostly targets NUCLEO-F411RE, so pin choices here use
 * Nucleo/Mbed aliases or F446RE-compatible pins where practical.
 */
#include "mbed.h"
#include <cstdio>
#include <cstdlib>
#include <cmath>

DigitalOut led(LED1);
AnalogIn ain(A0);
int main()
{
    while(true){
        float d=ain.read();
        led=1; wait(0.03f);
        led=0; wait(0.05f+0.95f*d);
    }
}
