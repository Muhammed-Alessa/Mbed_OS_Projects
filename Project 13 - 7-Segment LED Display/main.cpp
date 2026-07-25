/*
 * 7-Segment LED Display
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

static const uint8_t lut[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
BusOut seg(D2,D3,D4,D5,D6,D7,D8);
int main()
{
    while (true) for (int n=0;n<10;n++) { seg=lut[n]; wait(1.0f); }
}
