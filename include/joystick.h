#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "bleGamepadExtern.h"
#include <BleGamepad.h>

// X on pin 32 and Y on pin 15 work
#define VX1 32
#define VY1 15
#define SW1 13

void joystickControl(int inputX, int inputY);

#endif