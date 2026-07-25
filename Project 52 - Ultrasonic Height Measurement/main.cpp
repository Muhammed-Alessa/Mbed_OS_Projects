/*
 * Ultrasonic Height Measurement
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

#include "TextLCD.h"   // historical external Mbed library
TextLCD lcd(D2,D3,D4,D5,D6,D7); // RS,E,D4,D5,D6,D7
DigitalOut trig(D8);
DigitalIn echo(D9);
int main()
{
    Timer t;
    while(true){
        trig=0;wait_us(2);trig=1;wait_us(10);trig=0;
        while(echo==0){}
        t.reset();t.start();while(echo==1){}t.stop();
        float cm=t.read_us()*0.01715f;
        lcd.locate(0,0);lcd.printf("Distance:%6.1f",cm);wait(0.5f);
    }
}
