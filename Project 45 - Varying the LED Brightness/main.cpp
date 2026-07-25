/*
 * Varying the LED Brightness
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

PwmOut led(D9);
int main()
{
    led.period_ms(20);
    while(true){
        for(int i=0;i<=10;i++){led.write(i/10.0f);wait(0.2f);}
        for(int i=10;i>=0;i--){led.write(i/10.0f);wait(0.2f);}
    }
}
