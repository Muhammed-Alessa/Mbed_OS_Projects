/*
 * TMP102 Temperature Sensor
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
I2C i2c(D14,D15);
#define TMP102_ADDR (0x48<<1)
static float read_temp()
{
    char reg=0x00,b[2];
    i2c.write(TMP102_ADDR,&reg,1,true);
    i2c.read(TMP102_ADDR,b,2);
    int16_t raw=(int16_t)(((uint16_t)(uint8_t)b[0]<<4)|((uint8_t)b[1]>>4));
    if(raw&0x800)raw|=0xF000;
    return raw*0.0625f;
}
int main(){while(true){pc.printf("\r\nTMP102 %.2f C",read_temp());wait(1.0f);}}
