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
#include "WProgram.h"
#include "TouchScreen.h"

TouchScreen::TouchScreen(int x1, int x2, int y1, int y2)
{
  _x1 = x1;
  _x2 = x2;
  _y1 = y1;
  _y2 = y2;
}
/* ================  Public methods ================ */

/**
 * Reads the X and Y coordinates from a touchscreen
 */
void TouchScreen::read(int *coordinates)
{
  // Read the X coordinate
  pinMode( _x2 + 14, INPUT );     // Analog pin 1
  pinMode( _x1 + 14, INPUT );     // Analog pin 3
  pinMode( _y1 + 14, OUTPUT );    // Analog pin 0
  digitalWrite( _y1 + 14, LOW );  // Use analog pin 0 as a GND connection
  pinMode( _y2 + 14, OUTPUT );    // Analog pin 2
  digitalWrite( _y2 + 14, HIGH ); // Use analog pin 2 as a +5V connection
  _xVal = analogRead( _x2 );      // Read the X value

  // Read the Y coordinate
  pinMode( _y1 + 14, INPUT );     // Analog pin 0
  pinMode( _y2 + 14, INPUT );     // Analog pin 2
  pinMode( _x2 + 14, OUTPUT );    // Analog pin 1
  digitalWrite( _x2 + 14, LOW );  // Use analog pin 1 as a GND connection
  pinMode( _x1 + 14, OUTPUT );    // Analog pin 3
  digitalWrite( _x1 + 14, HIGH ); // Use analog pin 3 as a +5V connection
  _yVal = analogRead( _y1 );      // Read the Y value

  // Update the array we were pointed to by the calling function
  coordinates[0] = _xVal;
  coordinates[1] = _yVal;
}
