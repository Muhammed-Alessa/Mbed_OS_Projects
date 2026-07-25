/*
 * Android-Nucleo Communication Using Bluetooth
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

Serial bluetooth(PA_9,PA_10,9600);
DigitalOut a(D2),b(D3);
int main()
{
    char cmd[8];
    while(true){
        if(bluetooth.scanf("%7s",cmd)==1){
            if(!strcmp(cmd,"ONA"))a=1;
            else if(!strcmp(cmd,"OFFA"))a=0;
            else if(!strcmp(cmd,"ONB"))b=1;
            else if(!strcmp(cmd,"OFFB"))b=0;
        }
    }
}
