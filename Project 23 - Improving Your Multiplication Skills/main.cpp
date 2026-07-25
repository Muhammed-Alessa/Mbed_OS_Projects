/*
 * Improving Your Multiplication Skills
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
    uint32_t s=0x13572468UL;
    while(true){
        s=s*1664525UL+1013904223UL; int a=1+(s%20);
        s=s*1664525UL+1013904223UL; int b=1+(s%20);
        int ans; pc.printf("\r\n%d x %d = ? ",a,b); pc.scanf("%d",&ans);
        pc.printf(ans==a*b ? "Correct!\r\n" : "Correct answer: %d\r\n",a*b);
    }
}
