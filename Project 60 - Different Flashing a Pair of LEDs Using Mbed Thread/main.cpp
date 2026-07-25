/*
 * Different Flashing a Pair of LEDs Using Mbed Thread
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
DigitalOut a(D2),b(D3);
Thread ta,tb;
static void task_a(){while(true){a=!a;Thread::wait(1000);}}
static void task_b(){while(true){b=!b;Thread::wait(500);}}
int main()
{
    ta.start(callback(task_a));tb.start(callback(task_b));
    while(true)Thread::wait(1000);
}
