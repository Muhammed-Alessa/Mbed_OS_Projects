/*
 * Reaction Timer
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
DigitalOut led(LED1);
DigitalIn button(BUTTON1);
int main()
{
    Timer t; uint32_t s=0x10203040UL;
    while(true){
        led=0;
        s=s*1664525UL+1013904223UL;
        wait(1.0f+(float)(s%5U));
        led=1; t.reset(); t.start();
        while(button!=0){}
        t.stop(); led=0;
        pc.printf("\r\nReaction: %d ms\r\n",t.read_ms());
        while(button==0) wait_ms(10);
        wait(1.0f);
    }
}
