/*
 * Simple Stepper Motor Control
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

BusOut coils(D2,D3,D4,D5);
static const uint8_t seq[4]={0x03,0x06,0x0C,0x09};
static void steps(int n,bool reverse)
{
    for(int i=0;i<n;i++){
        int k=reverse?(3-(i&3)):(i&3);
        coils=seq[k]; wait_ms(3);
    }
    coils=0;
}
int main()
{
    while(true){steps(512,false);wait(1.0f);steps(512,true);wait(1.0f);}
}
