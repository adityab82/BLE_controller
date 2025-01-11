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
    // // Serial.begin(9600);
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

        int xGamepad = map(xval, 0, 4095, -127, 127);
        int yGamepad = map(yval, 0, 4095, -127, 127);


        // Simulate joystick movement
        bleGamepad.setAxes(xGamepad, yGamepad, 0, 0, 0, 0);
        // delay(1000);
        // bleGamepad.setAxes(0, 0, 0, 0, 0, 0);
        // delay(1000);
        // Serial.print("X axis: ");
        // Serial.println(analogRead(VX1));
        // Serial.print("Y axis: ");
        // Serial.println(analogRead(VY1));
        // Serial.print("X axis: ");
        // Serial.println(xGamepad);
        // Serial.print("Y axis: ");
        // Serial.println(yGamepad);
        // delay(400);
    }
}


