// #include <Arduino.h>
// #include <BleGamepad.h>
// #include <button.h>
// #include <joystick.h>
// // #include "bleGamepadExtern.h"

// BleGamepad bleGamepad;

// const int centerX = 2900;
// const int centerY = 2900;
// const int deadzone = 30; 

// void setup() {
//     bleGamepad.begin();
//     Serial.begin(115200);
//     pinMode(PUSH_BUTTON, INPUT_PULLUP); 
//     pinMode(PUSH_BUTTON2, INPUT_PULLUP);
//     pinMode(SW1, INPUT_PULLUP);
//     pinMode(VX1, INPUT);
//     pinMode(VY1, INPUT);
// }

// void loop() {
//     if (bleGamepad.isConnected()) {
//         button_press(PUSH_BUTTON, BUTTON_1);
//         button_press(PUSH_BUTTON2, BUTTON_2);

//         button_press(SW1, BUTTON_3);

//         int xval = analogRead(VX1);
//         int yval = analogRead(VY1);

//         // xval -= centerX;
//         // yval -= centerY;

//         // // Apply deadzone
//         // if (abs(xval) < deadzone) xval = 0;
//         // if (abs(yval) < deadzone) yval = 0;

//         int xGamepad = map(xval, 0, 4095, -32768, 32737);
//         int yGamepad = map(yval, 0, 4095, -32768, 32737);

//         // int xGamepad = map(xval, -centerX, 4095 - centerX, 0, 32737);
//         // int yGamepad = map(yval, -centerX, 4095 - centerY, 0, 32737);

//         yGamepad = -yGamepad;

//         // if (false) {
//         //     xGamepad = 32737 - xGamepad;
//         //     if (xGamepad < 0)
//         //         xGamepad = -xGamepad;
//         // }
//         // if (true) {
//         //     yGamepad = 32737 - yGamepad;
//         //     if (yGamepad < 0)
//         //         yGamepad = -yGamepad;
//         // }
//         bleGamepad.setLeftThumb(xGamepad, yGamepad);
//         // Serial.print("X center: ");
//         // Serial.println(analogRead(VX1));
//         // Serial.print("Y center: ");
//         // Serial.println(analogRead(VY1));
//     }
// }

#include <Arduino.h>
#include <BleGamepad.h>
#include <button.h>
#include <joystick.h>
// #include "bleGamepadExtern.h"

BleGamepad bleGamepad;

const int centerX = 2900;
const int centerY = 2900;
const int deadzone = 30; 

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

        printAnalogValues(VX1, VY1);

        // int xval = analogRead(VX1);
        // int yval = analogRead(VY1);

        // xval -= centerX;
        // yval -= centerY;

        // // Apply deadzone
        // if (abs(xval) < deadzone) xval = 0;
        // if (abs(yval) < deadzone) yval = 0;

        // int xGamepad = map(xval, 0, 4095, -32768, 32737);
        // int yGamepad = map(yval, 0, 4095, -32768, 32737);

        // int xGamepad = map(xval, -centerX, 4095 - centerX, 0, 32737);
        // int yGamepad = map(yval, -centerX, 4095 - centerY, 0, 32737);

        // yGamepad = -yGamepad;

        // if (false) {
        //     xGamepad = 32737 - xGamepad;
        //     if (xGamepad < 0)
        //         xGamepad = -xGamepad;
        // }
        // if (true) {
        //     yGamepad = 32737 - yGamepad;
        //     if (yGamepad < 0)
        //         yGamepad = -yGamepad;
        // }
        // // bleGamepad.setLeftThumb(xGamepad, yGamepad);
        // Serial.print("X center: ");
        // Serial.println(analogRead(VX1));
        // Serial.print("Y center: ");
        // Serial.println(analogRead(VY1));
        // delay(500);
    }
}

