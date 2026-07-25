/*
 * Arbitrary Periodic Waveform
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
        static const float wave[]={0.0f,0.15f,0.30f,0.80f,1.0f,0.7f,0.4f,0.1f};
        for(unsigned i=0;i<sizeof(wave)/sizeof(wave[0]);i++){dac=wave[i];wait_ms(2);}
    }
}
