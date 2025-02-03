#include <Arduino.h>
#include "joystick.h"

void printAnalogValues(int inputX, int inputY){

        int xval = analogRead(VX1);
        int yval = analogRead(VY1);

        xval = map(xval, 0, 4095, -32768, 32767);
        yval= map(yval, 0, 4095, -32768, 32767);

        xval = constrain(xval, -32768, 32767);
        yval = constrain(yval, -32768, 32767);

        // if(xval > 32737) xval = 32737;
        // if(xval < - 32768) xval = -32768;

        // if(yval > 32737) yval = 32737;
        // if(yval < - 32768) yval = -32768;

        // xval = -xval;
        // yval = -yval;

        bleGamepad.setLeftThumb(xval, yval);

        Serial.print("X center: ");
        Serial.println(xval);
        Serial.print("Y center: ");
        Serial.println(yval);
        // delay(500);  
}