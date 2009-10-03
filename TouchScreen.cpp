/**
 * TouchScreen Library
 *
 * Copyright 2009 Jonathan Oxer <jon@oxer.com.au> / <www.practicalarduino.com>
 *
 * Reads X/Y coordinates from a 4-wire resistive touch-screen connected
 * to four analog inputs on an Arduino.
 *
 * Analog input pins can also be used as general-purpose digital I/O
 * pins. When referenced in that mode they are actually d14 through
 * d18, ie:
 *   a0 = d14 = y1
 *   a1 = d15 = x2
 *   a2 = d16 = y2
 *   a3 = d17 = x1
 * We therefore add 14 to the analog pin number to reference it as a
 * digital pin.
 */
//#include "WProgram.h"
#include "TouchScreen.h"

TouchScreen::TouchScreen(int pinX1, int pinX2, int pinY1, int pinY2)
{
  _pinX1 = pinX1;
  _pinX2 = pinX2;
  _pinY1 = pinY1;
  _pinY2 = pinY2;
}
/* ================  Public methods ================ */

/**
 * Reads the X and Y coordinates from a touchscreen
 */
void TouchScreen::read(int *coordinates)
{
  // Read the X coordinate
  pinMode( _pinX2 + DIGITAL_OFFSET, INPUT );     // Analog pin 1
  pinMode( _pinX1 + DIGITAL_OFFSET, INPUT );     // Analog pin 3
  pinMode( _pinY1 + DIGITAL_OFFSET, OUTPUT );    // Analog pin 0
  digitalWrite( _pinY1 + DIGITAL_OFFSET, LOW );  // Use analog pin 0 as a GND connection
  pinMode( _pinY2 + DIGITAL_OFFSET, OUTPUT );    // Analog pin 2
  digitalWrite( _pinY2 + DIGITAL_OFFSET, HIGH ); // Use analog pin 2 as a +5V connection
  _xVal = analogRead( _pinX2 );      // Read the X value

  // Read the Y coordinate
  pinMode( _pinY1 + DIGITAL_OFFSET, INPUT );     // Analog pin 0
  pinMode( _pinY2 + DIGITAL_OFFSET, INPUT );     // Analog pin 2
  pinMode( _pinX2 + DIGITAL_OFFSET, OUTPUT );    // Analog pin 1
  digitalWrite( _pinX2 + DIGITAL_OFFSET, LOW );  // Use analog pin 1 as a GND connection
  pinMode( _pinX1 + DIGITAL_OFFSET, OUTPUT );    // Analog pin 3
  digitalWrite( _pinX1 + DIGITAL_OFFSET, HIGH ); // Use analog pin 3 as a +5V connection
  _yVal = analogRead( _pinY1 );      // Read the Y value

  // Update the array we were pointed to by the calling function
  coordinates[0] = _xVal;
  coordinates[1] = _yVal;
}
