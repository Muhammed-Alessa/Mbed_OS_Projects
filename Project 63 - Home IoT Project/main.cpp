/*
 * Home IoT Project
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

/*
 * Historical three-node Bluetooth exercise.
 * Choose one node type before compiling:
 *   1 = temperature node
 *   2 = light node
 *   3 = window switch node
 */
#define NODE_TYPE 2

Serial bt(PA_9,PA_10,9600);
AnalogIn light(A0);
DigitalIn window(D2,PullUp);

int main()
{
    while(true){
#if NODE_TYPE == 1
        bt.printf("Temperature node: connect your TMP102 helper here\r\n");
#elif NODE_TYPE == 2
        bt.printf(light.read()<0.5f ? "Lights are OFF\r\n" : "Lights are ON\r\n");
#else
        bt.printf(window ? "Window is OPEN\r\n" : "Window is CLOSED\r\n");
#endif
        wait(5.0f);
    }
}
