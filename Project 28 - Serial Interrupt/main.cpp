/*
 * Serial Interrupt
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
volatile float delay_s=0.5f;
static void rx()
{
    char c=pc.getc();
    if(c=='+') { delay_s-=0.05f; if(delay_s<0.05f) delay_s=0.05f; }
    if(c=='-') { delay_s+=0.05f; if(delay_s>1.0f) delay_s=1.0f; }
}
int main()
{
    pc.attach(&rx,Serial::RxIrq);
    while(true){ led=!led; wait(delay_s); }
}
