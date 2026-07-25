/*
 * 7-Segment LED Dice
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
DigitalIn button(BUTTON1);
int main()
{
    uint32_t state=0xA5A5A5A5UL;
    while(true){
        if(button==0){
            state=state*1664525UL+1013904223UL;
            unsigned a=1U+state%6U;
            state=state*1664525UL+1013904223UL;
            unsigned b=1U+state%6U;
            unsigned shown=a*100U+b;
            for(int i=0;i<250;i++) display4(shown);
            while(button==0) wait_ms(10);
        }
        display4(0);
    }
}
