#include "tm1637.h"

// Digit to 7-seg (no decimal point)
static const uint8_t digitToSegment[] = {
    0x3f, // 0
    0x06, // 1
    0x5b, // 2
    0x4f, // 3
    0x66, // 4
    0x6d, // 5
    0x7d, // 6
    0x07, // 7
    0x7f, // 8
    0x6f, // 9
    0x00  // blank
};

TM1637::TM1637(PinName dio, PinName clk)
    : _dio(dio), _clk(clk), _brightness(7)
{
    _dio.output();
    _dio = 1;
    _clk = 1;
}

void TM1637::start() {
    _dio.output();
    _dio = 1;
    _clk = 1;
    wait_us(2);
    _dio = 0;
    wait_us(2);
    _clk = 0;
}

void TM1637::stop() {
    _dio.output();
    _clk = 0;
    _dio = 0;
    wait_us(2);
    _clk = 1;
    wait_us(2);
    _dio = 1;
    wait_us(2);
}

bool TM1637::writeByte(uint8_t b) {
    for (int i = 0; i < 8; i++) {
        _clk = 0;
        wait_us(3);
        _dio = (b & 0x01);
        wait_us(3);
        _clk = 1;
        wait_us(3);
        b >>= 1;
    }
    _clk = 0;
    _dio.input();
    wait_us(5);
    _clk = 1;
    bool ack = (_dio.read() == 0);
    wait_us(5);
    _clk = 0;
    _dio.output();
    return ack;
}

void TM1637::setBrightness(uint8_t brightness) {
    if (brightness > 7) brightness = 7;
    _brightness = brightness;
    // Send display control command to update brightness (display on)
    start();
    writeByte(0x88 | _brightness);
    stop();
}

uint8_t TM1637::encodeDigit(uint8_t digit, bool dot) {
    uint8_t seg = 0x00;
    if (digit < 10)
        seg = digitToSegment[digit];
    if (dot)
        seg |= 0x80;
    return seg;
}

void TM1637::displayDigit(int pos, uint8_t digit, bool dot) {
    if (pos < 0 || pos > 3) return;
    start();
    writeByte(0x40);  // set data command - automatic address increment
    stop();

    start();
    writeByte(0xC0 + pos);  // set address command
    writeByte(encodeDigit(digit, dot));
    stop();

    setBrightness(_brightness);
}

void TM1637::displaySegments(const uint8_t segments[4]) {
    start();
    writeByte(0x40);  // data command: automatic address increment
    stop();

    start();
    writeByte(0xC0);  // address command: start at 0
    for (int i = 0; i < 4; i++) {
        writeByte(segments[i]);
    }
    stop();

    setBrightness(_brightness);
}

void TM1637::displayNumber(int num) {
    if (num < 0) num = 0;
    uint8_t segs[4] = {0};
    for (int i = 3; i >= 0; i--) {  // start from leftmost
        int digit = num % 10;
        segs[i] = encodeDigit(digit, false);
        num /= 10;
    }
    displaySegments(segs);
}

void TM1637::clear() {
    uint8_t blank[4] = {0, 0, 0, 0};
    displaySegments(blank);
}
