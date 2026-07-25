/*
 * Electronic Organ
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
PwmOut buzzer(D9);
int main()
{
    const float notes[]={262,294,330,349,392,440,494,523,587,659,698};
    while(true){
        char c=pc.getc();
        if(c>='a'&&c<='k'){
            float hz=notes[c-'a']; buzzer.period(1.0f/hz); buzzer.write(0.5f);
            wait(0.2f); buzzer.write(0.0f);
        }
    }
}
