/*
 * Random Colored LED Display
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

BusOut rgb(D5,D6,D7);
int main()
{
    uint32_t state=0x31415926UL;
    while (true) {
        state=state*1664525UL+1013904223UL;
        rgb=(uint8_t)(state&0x07U);
        wait(0.25f);
    }
}
