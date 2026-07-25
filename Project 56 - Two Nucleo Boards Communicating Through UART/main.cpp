/*
 * Two Nucleo Boards Communicating Through UART
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

Serial pc(USBTX,USBRX,9600);
Serial link(PC_6,PC_7,9600); // USART6 TX/RX on F446RE
int main()
{
    /*
     * Build one board as sender and one as receiver.
     * Set SENDER to 1 for the sender build and 0 for the receiver build.
     */
    const int SENDER=1;
    if(SENDER){
        float t=25.0f;
        while(true){link.printf("%.2f\n",t);wait(1.0f);}
    }else{
        float t;
        while(true){if(link.scanf("%f",&t)==1)pc.printf("\r\nReceived %.2f C",t);}
    }
}
