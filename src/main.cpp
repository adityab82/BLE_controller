#include <Arduino.h>
#include <BleGamepad.h>
#include <button.h>
#include <joystick.h>
#include "bleGamepadExtern.h"

BleGamepad bleGamepad;

// void button_press(int pin_number, int button_number);

void setup() {
    bleGamepad.begin();
    Serial.begin(115200);
    pinMode(PUSH_BUTTON, INPUT_PULLUP); 
    pinMode(PUSH_BUTTON2, INPUT_PULLUP);
    pinMode(SW1, INPUT_PULLUP);
    pinMode(VX1, INPUT);
    pinMode(VY1, INPUT);
}

void loop() {
    if (bleGamepad.isConnected()) {
        button_press(PUSH_BUTTON, BUTTON_1);
        button_press(PUSH_BUTTON2, BUTTON_2);

        button_press(SW1, BUTTON_3);

        int xval = analogRead(VX1);
        int yval = analogRead(VY1);

        int xGamepad = map(xval, 4095, 0, 0, 32737);
        int yGamepad = map(yval, 4095, 0, 0, 32737);

        if (false) {
            xGamepad = 32737 - xGamepad;
            if (xGamepad < 0)
                xGamepad = -xGamepad;
        }
        if (true) {
            yGamepad = 32737 - yGamepad;
            if (yGamepad < 0)
                yGamepad = -yGamepad;
        }
        bleGamepad.setLeftThumb(xGamepad, yGamepad);
    }
}


