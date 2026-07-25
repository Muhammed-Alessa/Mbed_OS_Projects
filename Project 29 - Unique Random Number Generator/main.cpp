/*
 * Unique Random Number Generator
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
    uint32_t s=0xCAFEBABEUL;
    while(true){
        int values[7]; int used=0;
        while(used<7){
            s=s*1664525UL+1013904223UL;
            int candidate=1+(s%50);
            bool duplicate=false;
            for(int i=0;i<used;i++) if(values[i]==candidate) duplicate=true;
            if(!duplicate) values[used++]=candidate;
        }
        pc.printf("\r\nUnique numbers: ");
        for(int i=0;i<7;i++) pc.printf("%d ",values[i]);
        pc.printf("\r\n");
        wait(2.0f);
    }
}
