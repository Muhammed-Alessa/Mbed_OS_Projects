/*
 * Volume of a Cylinder
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

Serial pc(USBTX, USBRX, 9600);

int main()
{
    float r,hgt;
    while(true){
        pc.printf("\r\nRadius: "); pc.scanf("%f",&r);
        pc.printf("\r\nHeight: "); pc.scanf("%f",&hgt);
        pc.printf("\r\nVolume = %.3f\r\n", 3.1415926f*r*r*hgt);
    }
}
