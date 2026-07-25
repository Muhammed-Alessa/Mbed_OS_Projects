/*
 * Calculator
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
    float a,b; char op;
    while(true){
        pc.printf("\r\nFirst number: "); pc.scanf("%f",&a);
        pc.printf("\r\nOperator (+-*/): "); pc.scanf(" %c",&op);
        pc.printf("\r\nSecond number: "); pc.scanf("%f",&b);
        float result=0.0f;
        if(op=='+') result=a+b; else if(op=='-') result=a-b;
        else if(op=='*') result=a*b; else if(op=='/' && b!=0.0f) result=a/b;
        pc.printf("\r\nResult = %.3f\r\n",result);
    }
}
