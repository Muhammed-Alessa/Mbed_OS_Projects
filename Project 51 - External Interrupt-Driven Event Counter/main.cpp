/*
 * External Interrupt-Driven Event Counter
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
InterruptIn event_pin(D8);
volatile unsigned count=0;
static void event(){++count;}
int main(){event_pin.fall(&event);while(true){lcd.locate(0,0);lcd.printf("Count: %-8u",count);wait_ms(100);}}
