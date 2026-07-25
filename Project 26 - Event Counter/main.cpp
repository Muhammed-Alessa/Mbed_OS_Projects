/*
 * Event Counter
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
DigitalIn button(BUTTON1);
int main()
{
    unsigned count=0;
    while(true){
        if(button==0){
            pc.printf("\r\nCount = %u",++count);
            while(button==0) wait_ms(10);
        }
    }
}
