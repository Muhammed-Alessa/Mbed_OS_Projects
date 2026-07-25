/*
 * Android-Nucleo Communication Using the Wi-Fi Expansion Board
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
 * Historical X-NUCLEO Wi-Fi middleware project.
 *
 * The original expansion-board library and online Mbed workspace are legacy
 * dependencies. Restore the exact library revision you used in college before
 * reconstructing the networking application; do not invent a modern API here.
 */
Serial pc(USBTX,USBRX,9600);
int main()
{
    pc.printf("\r\nHistorical Wi-Fi shield project - restore archived middleware revision.\r\n");
    while(true) wait(1.0f);
}
