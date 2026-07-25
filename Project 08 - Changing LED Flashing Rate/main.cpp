/*
 * Changing LED Flashing Rate
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
    float delay_s = 1.0f;
    while (true) {
        led = !led;
        wait(delay_s);
        if (button == 0) {
            delay_s -= 0.2f;
            if (delay_s < 0.1f) delay_s = 1.0f;
            while (button == 0) wait_ms(10);
        }
    }
}
