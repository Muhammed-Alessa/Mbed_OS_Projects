/*
 * Digital Thermostat
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

Serial pc(USBTX,USBRX,9600);
AnalogIn ain(A0);
DigitalOut alarm(LED1);
int main()
{
    while(true){
        float v=ain.read()*3.3f; float t=(v-0.5f)*100.0f;
        bool bad=(t<18.0f||t>30.0f); alarm=bad;
        pc.printf("\r\nTemp %.2f C - %s",t,bad?"OUT OF RANGE":"NORMAL"); wait(1.0f);
    }
}
