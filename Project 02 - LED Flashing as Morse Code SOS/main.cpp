/*
 * LED Flashing as Morse Code SOS
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

DigitalOut led(LED1);
static void pulse(float on_time)
{
    led = 1; wait(on_time);
    led = 0; wait(0.2f);
}
int main()
{
    while (true) {
        for (int i=0;i<3;i++) pulse(0.25f);
        for (int i=0;i<3;i++) pulse(1.0f);
        for (int i=0;i<3;i++) pulse(0.25f);
        wait(2.0f);
    }
}
