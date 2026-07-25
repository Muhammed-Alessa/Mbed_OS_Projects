/*
 * Loop Execution Times
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

Serial pc(USBTX, USBRX, 9600);

int main()
{
    Timer t;
    while(true){
        volatile uint32_t sink=0;
        t.reset(); t.start();
        for(uint32_t i=0;i<160000U;i++) sink+=i;
        t.stop();
        pc.printf("\r\nElapsed: %d ms\r\n",t.read_ms());
        wait(2.0f);
    }
}
