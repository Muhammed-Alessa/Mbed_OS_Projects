/*
 * Android-Nucleo Communication Using the ESP-01
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
Serial esp(PA_9,PA_10,115200);
static void command(const char *s)
{
    esp.printf("%s\r\n",s);
    wait(1.0f);
    while(esp.readable()) pc.putc(esp.getc());
}
int main()
{
    command("AT");
    command("AT+GMR");
    while(true) wait(1.0f);
}
