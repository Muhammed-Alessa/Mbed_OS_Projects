/*
 * Car Park Controller Using Signals
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

#include "rtos.h"
Serial pc(USBTX,USBRX,9600);
DigitalIn entry(D2,PullUp),exit_sw(D3,PullUp),start(D4,PullUp);
Thread controller;
volatile int spaces=100;
static void control()
{
    Thread::signal_wait(0x1);
    while(true){
        if(entry==0 && spaces>0){--spaces;while(entry==0)Thread::wait(10);}
        if(exit_sw==0 && spaces<100){++spaces;while(exit_sw==0)Thread::wait(10);}
        Thread::wait(20);
    }
}
int main()
{
    controller.start(callback(control));
    pc.printf("\r\nCLOSED");
    while(start!=0)Thread::wait(20);
    controller.signal_set(0x1);
    while(true){pc.printf("\r\nSPACES: %d   ",spaces);Thread::wait(500);}
}
