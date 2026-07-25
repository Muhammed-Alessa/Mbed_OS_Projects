/*
 * Generating Fixed Voltage
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
        float v[4]={0.0f,1.0f/3.3f,2.0f/3.3f,3.0f/3.3f};
        for(int i=0;i<4;i++){dac=v[i];wait(0.1f);}
    }
}
