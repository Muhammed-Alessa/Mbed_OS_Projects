/*
 * LED Control with Push-Button
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

DigitalOut led(LED1);
DigitalIn button(BUTTON1);
int main()
{
    while (true) {
        if (button == 0) {
            for (int i=0;i<3;i++) { led=1; wait(0.2f); led=0; wait(0.2f); }
            while (button == 0) wait_ms(10);
        }
    }
}
