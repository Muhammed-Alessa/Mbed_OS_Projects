/*
 * Sawtooth Waveform
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

AnalogOut dac(PA_4);
Serial pc(USBTX,USBRX,9600);
int main()
{
    while(true){
        for(int i=0;i<10;i++){dac=(float)i/9.0f;wait_ms(2);}
    }
}
