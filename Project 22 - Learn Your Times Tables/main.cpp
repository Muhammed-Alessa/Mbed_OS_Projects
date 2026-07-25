/*
 * Learn Your Times Tables
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
    int n;
    while(true){
        pc.printf("\r\nNumber: "); pc.scanf("%d",&n);
        for(int i=1;i<=12;i++) pc.printf("%d x %d = %d\r\n",n,i,n*i);
    }
}
