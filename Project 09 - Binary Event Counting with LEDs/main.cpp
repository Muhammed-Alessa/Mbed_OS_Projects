/*
 * Binary Event Counting with LEDs
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
DigitalIn button(BUTTON1);
uint8_t count=0;
int main()
{
    while (true) {
        if (button == 0) { leds = ++count; while (button == 0) wait_ms(10); }
    }
}
