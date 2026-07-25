/*
 * Powering Large Loads - DC Motor Control
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

DigitalOut motor(D2);
int main()
{
    while(true){motor=1;wait(2.0f);motor=0;wait(2.0f);}
}
