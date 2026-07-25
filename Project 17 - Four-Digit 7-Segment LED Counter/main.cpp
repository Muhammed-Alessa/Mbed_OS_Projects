/*
 * Four-Digit 7-Segment LED Counter
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
BusOut enables(D9,D10,D11,D12);
static void display4(unsigned value)
{
    unsigned div=1000U;
    for (int i=0;i<4;i++) {
        unsigned digit=(value/div)%10U;
        enables=0; seg=lut[digit]; enables=(1U<<i); wait_ms(2);
        div/=10U;
    }
}
int main()
{
    unsigned count=0;
    while(true){
        for(int i=0;i<120;i++) display4(count);
        count=(count+1U)%10000U;
    }
}
