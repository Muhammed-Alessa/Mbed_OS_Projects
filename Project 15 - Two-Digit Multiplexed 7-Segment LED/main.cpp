/*
 * Two-Digit Multiplexed 7-Segment LED
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
BusOut enables(D9,D10);
static void display2(unsigned value)
{
    unsigned d0=value%10U, d1=(value/10U)%10U;
    enables=0; seg=lut[d1]; enables=1; wait_ms(4);
    enables=0; seg=lut[d0]; enables=2; wait_ms(4);
}
int main(){ while(true) display2(25); }
