/*
 * Generating Square Wave with SPI DAC
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

SPI spi(D11,D12,D13);
DigitalOut cs(D10);
static void dac_write(uint16_t value)
{
    value&=0x0FFFU;
    uint16_t word=0x3000U|value;
    cs=0; spi.write((word>>8)&0xFF); spi.write(word&0xFF); cs=1;
}
int main()
{
    spi.format(8,0);spi.frequency(1000000);cs=1;
    uint16_t one_volt=(uint16_t)(4095.0f/3.3f);
    while(true){dac_write(one_volt);wait_us(500);dac_write(0);wait_us(500);}
}
