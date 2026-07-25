/*
 * Changing the Motor Rotation Direction
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

DigitalOut in1(D2),in2(D3);
DigitalIn button(BUTTON1);
int main()
{
    while(true){
        if(button==0){in1=1;in2=0;}
        else{in1=0;in2=1;}
        wait_ms(20);
    }
}
