/*
 * Flashing an External LED
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

DigitalOut led(D2);
int main()
{
    while (true) {
        led = 1; wait(0.1f);
        led = 0; wait(1.0f);
    }
}
