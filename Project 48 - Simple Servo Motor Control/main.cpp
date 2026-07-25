/*
 * Simple Servo Motor Control
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

PwmOut servo(D9);
static void position(float pulse_ms)
{
    servo.pulsewidth_us((int)(pulse_ms*1000.0f));
}
int main()
{
    servo.period_ms(20);
    while(true){
        position(1.0f);wait(2.0f);
        position(1.5f);wait(2.0f);
        position(2.0f);wait(2.0f);
    }
}
