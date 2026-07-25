/*
 * Hi-Lo Game
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
    uint32_t s=0x24681357UL;
    while(true){
        s=s*1664525UL+1013904223UL; int secret=1+(s%100); int guess=-1;
        pc.printf("\r\nGuess a number from 1 to 100.\r\n");
        while(guess!=secret){
            pc.scanf("%d",&guess);
            if(guess>secret) pc.printf("HIGH\r\n");
            else if(guess<secret) pc.printf("LOW\r\n");
            else pc.printf("Correct!\r\n");
        }
    }
}
