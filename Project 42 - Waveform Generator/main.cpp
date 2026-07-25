/*
 * Waveform Generator
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
        pc.printf("\r\n1 Fixed  2 Saw  3 Triangle  4 Sine\r\nChoice: ");
        int c; pc.scanf("%d",&c);
        if(c==1){dac=1.0f/3.3f;wait(1.0f);}
        else if(c==2){for(int i=0;i<20;i++){dac=(float)i/19.0f;wait_ms(1);}}
        else if(c==3){for(int i=0;i<50;i++){dac=(float)i/49.0f;wait_us(200);}for(int i=49;i>=0;i--){dac=(float)i/49.0f;wait_us(200);}}
        else if(c==4){for(int i=0;i<100;i++){dac=0.5f+0.5f*sinf(6.2831853f*i/100.0f);wait_us(100);}}
    }
}
