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

#include "WProgram.h"

class TouchScreen
{
  public:
    TouchScreen(int x1, int x2, int y1, int y2);
    void read(int *coordinates);  // Read the touchscreen and return coordinates
  private:
    int _x1;      // Analog pin connected to screen line X1
    int _x2;      // Analog pin connected to screen line X2
    int _y1;      // Analog pin connected to screen line Y1
    int _y2;      // Analog pin connected to screen line Y2
    int _xVal;    // Current X coordinate
    int _yVal;    // Current Y coordinate
};

#endif
