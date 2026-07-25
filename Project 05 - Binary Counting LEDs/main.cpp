/*
 * Binary Counting LEDs
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

BusOut leds(D2,D3,D4,D5,D6,D7,D8,D9);
uint8_t count=0;
int main()
{
    while (true) {
        leds = count++; wait(1.0f);
    }
}
