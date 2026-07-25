# Refreshing a 7-Segment Display with RTOS

## Description
Moves display refresh into an RTOS thread while the main task updates the count.

## Hardware
- NUCLEO-F446RE
- 2-digit 7-segment display
- Resistors
- 2 NPN transistors

## Mbed concepts
- `BusOut`
- `RTOS Thread / signals`

## Code
See [main.cpp](main.cpp).

## Circuit / Real Build
Add your own real breadboard or bench photo here after verifying the project:

![Breadboard](images/breadboard.jpg)

## Source Inspiration
Dogan Ibrahim, *ARM-based Microcontroller Projects Using mbed*, Section 15.5.

The description and code in this repository are independently rewritten for the NUCLEO-F446RE and are not copied from the book.
