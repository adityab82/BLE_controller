#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "bleGamepadExtern.h"
#include <BleGamepad.h>

// X on pin 32 and Y on pin 15 work
#define VX1 15
#define VY1 4
#define VX2 27
#define VY2 14
// #define VX1 4
// #define VY1 15
// #define VX2 14
// #define VY2 27
#define SW1 5
#define SW2 13
#define NUM_SAMPLES 200

// const int centerX = 2869;
// const int centerY = 2976;
// const int deadzone = 100; 
// const int realCenter = 2048;

//Variables for scaled joystick
// const int maxPosX = 4095 - centerX;  // Maximum positive deviation for X
// const int maxNegX = centerX;         // Maximum negative deviation for X
// const int maxPosY = 4095 - centerY;    // Maximum positive deviation for Y
// const int maxNegY = centerY;           // Maximum negative deviation for Y

// The exponent for scaling (2.0 gives quadratic behavior).
// Values greater than 1 make the joystick less sensitive in the mid-range.
// const float exponent = 2.0;

struct JoystickConfig {
    int analogXPin;
    int analogYPin;
    int centerX;    // Calibrated center for the X axis
    int centerY;    // Calibrated center for the Y axis
    int deadzone;   // Deadzone value
    int realCenter; // Reference value (e.g., midpoint of ADC, such as 2048)
    bool isLeft;    // True for left joystick, false for right joystick
};

void calibrateJoystick(JoystickConfig &jsConfig);
// void joystickControl(int inputPinX, int inputPinY);
void joystickControl(const JoystickConfig &jsConfig);
void joystickControlScaled(int inputPinX, int inputPinY);

#endif