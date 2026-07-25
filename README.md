# Mbed OS Projects — NUCLEO-F446RE

This repository preserves and reconstructs my college Mbed work on the **NUCLEO-F446RE / STM32F446RET6**.

The project sequence is inspired by Dogan Ibrahim's *ARM-based Microcontroller Projects Using mbed* (2019). The book mostly uses the NUCLEO-F411RE; these files are independently rewritten for my F446RE and for the Mbed OS 5-era programming style.

> This is a **learning/archive portfolio**, not a recommendation to start a new production product with Mbed OS today.

## Repository style

Every project is intentionally simple:

```text
Project XX - Name/
├── main.cpp
├── README.md
└── images/
    └── .gitkeep
```

After rebuilding a project on real hardware, add your own photo as `images/breadboard.jpg`.

## Important compatibility notes

- Target board: `NUCLEO_F446RE`.
- Code intentionally follows **Mbed OS 5.x-era APIs** such as `DigitalOut`, `AnalogIn`, `PwmOut`, `Serial`, `Ticker`, `Timer`, and classic RTOS APIs.
- The book itself mostly targets NUCLEO-F411RE, so pin assignments are not copied blindly; Arduino/Nucleo aliases are used where practical.
- Some LCD, Wi-Fi, and X-NUCLEO projects require historical external libraries. Those projects are clearly marked instead of pretending a current library API is identical.
- The random-number exercise from the source book is kept as a neutral **Unique Random Number Generator** programming exercise.

## Projects

- `Project 01 - Flashing LED`
- `Project 02 - LED Flashing as Morse Code SOS`
- `Project 03 - Flashing an External LED`
- `Project 04 - Rotating LEDs`
- `Project 05 - Binary Counting LEDs`
- `Project 06 - Random Flashing LEDs`
- `Project 07 - LED Control with Push-Button`
- `Project 08 - Changing LED Flashing Rate`
- `Project 09 - Binary Event Counting with LEDs`
- `Project 10 - Using an External Button`
- `Project 11 - RGB LED Control`
- `Project 12 - Random Colored LED Display`
- `Project 13 - 7-Segment LED Display`
- `Project 14 - Powering Large Loads - DC Motor Control`
- `Project 15 - Two-Digit Multiplexed 7-Segment LED`
- `Project 16 - Four-Digit Multiplexed 7-Segment LED`
- `Project 17 - Four-Digit 7-Segment LED Counter`
- `Project 18 - Four-Digit 7-Segment LED Event Counter`
- `Project 19 - 7-Segment LED Dice`
- `Project 20 - Volume of a Cylinder`
- `Project 21 - Calculator`
- `Project 22 - Learn Your Times Tables`
- `Project 23 - Improving Your Multiplication Skills`
- `Project 24 - Loop Execution Times`
- `Project 25 - Reaction Timer`
- `Project 26 - Event Counter`
- `Project 27 - Hi-Lo Game`
- `Project 28 - Serial Interrupt`
- `Project 29 - Unique Random Number Generator`
- `Project 30 - Digital Voltmeter`
- `Project 31 - Analog Temperature Sensor - Digital Thermometer`
- `Project 32 - Digital Thermostat`
- `Project 33 - ON-OFF Temperature Controller`
- `Project 34 - Light Level Meter`
- `Project 35 - Changing LED Flashing Rate with a Potentiometer`
- `Project 36 - Sound Level Meter`
- `Project 37 - Generating Fixed Voltage`
- `Project 38 - Sawtooth Waveform`
- `Project 39 - Triangular Waveform`
- `Project 40 - Sine Waveform`
- `Project 41 - Arbitrary Periodic Waveform`
- `Project 42 - Waveform Generator`
- `Project 43 - Melody Maker`
- `Project 44 - Electronic Organ`
- `Project 45 - Varying the LED Brightness`
- `Project 46 - Simple Brushed DC Motor Control`
- `Project 47 - Changing the Motor Rotation Direction`
- `Project 48 - Simple Servo Motor Control`
- `Project 49 - Simple Stepper Motor Control`
- `Project 50 - Displaying Text on the LCD`
- `Project 51 - External Interrupt-Driven Event Counter`
- `Project 52 - Ultrasonic Height Measurement`
- `Project 53 - Calculator Using a Keypad`
- `Project 54 - TMP102 Temperature Sensor`
- `Project 55 - Generating Square Wave with SPI DAC`
- `Project 56 - Two Nucleo Boards Communicating Through UART`
- `Project 57 - Android-Nucleo Communication Using the Wi-Fi Expansion Board`
- `Project 58 - Android-Nucleo Communication Using the ESP-01`
- `Project 59 - Android-Nucleo Communication Using Bluetooth`
- `Project 60 - Different Flashing a Pair of LEDs Using Mbed Thread`
- `Project 61 - Refreshing a 7-Segment Display with RTOS`
- `Project 62 - Car Park Controller Using Signals`
- `Project 63 - Home IoT Project`
- `Project 64 - Environmental Measurements with X-NUCLEO-IKS01A2`
- `Project 65 - Brushed DC Motor Speed Control with X-NUCLEO-IHM13A1`
- `Project 66 - Potentiometer Motor Speed Control with X-NUCLEO-IHM13A1`
- `Project 67 - Controlling LEDs with X-NUCLEO-OUT01A1`
- `Project 68 - Measuring Distance with X-NUCLEO-53L0A1`
