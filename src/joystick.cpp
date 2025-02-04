#include <Arduino.h>
#include "joystick.h"

const int centerX = 2869;
const int centerY = 2976;
const int deadzone = 100; 
const int realCenter = 2048;

void printAnalogValues(int inputX, int inputY){
        int xGamepad, yGamepad;
        int16_t xval = analogRead(VX1);
        int16_t yval = analogRead(VY1);

        int dx = xval - centerX;
        int dy = yval - centerY;

        //center the joystick if there is no significant movement detected
        if(abs(dx) < deadzone) xGamepad = map(realCenter, 0, 4095, (centerX - realCenter), 32767);
        else if(abs(dx) > deadzone) xGamepad = map(xval, 0, 4095, (centerX - realCenter), 32767);

        if(abs(dy) < deadzone) yGamepad = map(realCenter, 0, 4095, (centerY - realCenter), 32767);
        else if(abs(dy) > deadzone) yGamepad = map(yval, 0, 4095, (centerY - realCenter), 32767);

        bleGamepad.setLeftThumb(xGamepad, yGamepad);
}