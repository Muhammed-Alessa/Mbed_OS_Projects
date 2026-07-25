# TM1637_Mbed_OS
Library for TM1637 LEDcontroller, Is used for 4-digit 7-SEG module with TM1637 chip
Simple and easy library for displaying numbers.

### How to use the library (step-by-step)

1. **Include the library in your project**

   * Add `tm1637.h` and `tm1637.cpp` to your project folder.
   * Include `tm1637.h` in your `main.cpp`.

2. **Create a TM1637 object with your pins**

   ```cpp
   TM1637 display(PB_10, PB_4);  // Replace PB_10 and PB_4 with your actual DIO and CLK pins
   ```

3. **Set brightness and clear the display (optional)**

   ```cpp
   display.setBrightness(7);  // max brightness
   display.clear();           // clear all digits
   ```

4. **Display numbers**

   * To show a number (0 to 9999):

     ```cpp
     display.displayNumber(1234);
     ```

   * To display a single digit at position (0 = leftmost, 3 = rightmost):

     ```cpp
     display.displayDigit(2, 5, true);  // digit 5 with decimal point at position 2
     ```

5. **Update display in your loop**

   Continuously update numbers or digits as needed.

---

### Example **main.cpp** ready for reuse:

```cpp
#include "mbed.h"
#include "tm1637.h"

// Create display object: adjust pins to your wiring
TM1637 display(PB_10, PB_4);

int main() {
    display.setBrightness(7); // max brightness
    display.clear();

    int counter = 0;
    while (true) {
        display.displayNumber(counter);
        counter = (counter + 1) % 10000; // loop 0-9999
        thread_sleep_for(300);
    }
}
```
