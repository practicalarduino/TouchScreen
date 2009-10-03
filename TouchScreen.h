/**
 * TouchScreen Library
 *
 * Copyright 2009 Jonathan Oxer <jon@oxer.com.au> / <www.practicalarduino.com>
 *
 * Reads X/Y coordinates from a 4-wire resistive touch-screen connected
 * to four analog inputs on an Arduino.
 */
#ifndef TouchScreen_h
#define TouchScreen_h

#define DIGITAL_OFFSET 14  // Added to analog pin number to get digital number

#include "WProgram.h"

class TouchScreen
{
  public:
    TouchScreen(int pinX1, int pinX2, int pinY1, int pinY2);
    void read(int *coordinates);  // Read the touchscreen and return coordinates
  private:
    int _pinX1;   // Analog pin connected to screen line X1
    int _pinX2;   // Analog pin connected to screen line X2
    int _pinY1;   // Analog pin connected to screen line Y1
    int _pinY2;   // Analog pin connected to screen line Y2
    int _xVal;    // Current X coordinate
    int _yVal;    // Current Y coordinate
};

#endif
