/*
 * Melody Maker
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

PwmOut buzzer(D9);
static void note(float hz,float seconds)
{
    buzzer.period(1.0f/hz); buzzer.write(0.5f); wait(seconds); buzzer.write(0.0f); wait(0.05f);
}
int main()
{
    const float melody[]={262,294,330,349,392,440,494,523};
    while(true){for(unsigned i=0;i<8;i++)note(melody[i],0.25f);wait(1.0f);}
}
