/*
 * Sound Level Meter
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

Serial pc(USBTX,USBRX,9600);
AnalogIn ain(A0);
int main()
{
    while(true){
        float minv=1.0f,maxv=0.0f;
        Timer t; t.start();
        while(t.read_ms()<100){float v=ain.read(); if(v<minv)minv=v; if(v>maxv)maxv=v;}
        t.stop(); pc.printf("\r\nPeak-to-peak = %.1f mV",(maxv-minv)*3300.0f); wait(0.2f);
    }
}
