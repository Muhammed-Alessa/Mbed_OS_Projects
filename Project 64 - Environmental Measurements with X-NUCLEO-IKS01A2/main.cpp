/*
 * Environmental Measurements with X-NUCLEO-IKS01A2
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
 * Historical STM32 Nucleo expansion-board project.
 *
 * This project depended on an external Mbed component library whose exact API
 * is version-specific. Keep this file as the application entry point and
 * restore the exact archived library revision you used when you studied it.
 *
 * Project type: x_iks
 */
Serial pc(USBTX,USBRX,9600);
int main()
{
    pc.printf("\r\nExpansion-board study project: restore matching historical library.\r\n");
    while(true) wait(1.0f);
}
