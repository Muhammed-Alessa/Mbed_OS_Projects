#ifndef TM1637_H
#define TM1637_H

#include "mbed.h"

class TM1637 {
public:
    TM1637(PinName dio, PinName clk);

    void setBrightness(uint8_t brightness);  // 0-7, 7 is max brightness
    void clear();
    void displayDigit(int pos, uint8_t digit, bool dot = false);
    void displayNumber(int num);
    void displaySegments(const uint8_t segments[4]);

private:
    DigitalInOut _dio;
    DigitalOut _clk;

    uint8_t _brightness;

    void start();
    void stop();
    bool writeByte(uint8_t b);
    uint8_t encodeDigit(uint8_t digit, bool dot);
};

#endif
