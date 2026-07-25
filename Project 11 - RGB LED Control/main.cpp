/*
 * RGB LED Control
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

DigitalIn r_btn(D2,PullUp), g_btn(D3,PullUp), b_btn(D4,PullUp);
DigitalOut r(D5), g(D6), b(D7);
static void toggle_if_pressed(DigitalIn &btn, DigitalOut &out)
{
    if (btn == 0) { out = !out; while (btn == 0) wait_ms(10); }
}
int main()
{
    while (true) {
        toggle_if_pressed(r_btn,r);
        toggle_if_pressed(g_btn,g);
        toggle_if_pressed(b_btn,b);
    }
}
