#include <Arduino.h>
#include <BleGamepad.h>
#include <button.h>
#include <joystick.h>

JoystickConfig leftJoystick = {
  .analogXPin = VX1,       
  .analogYPin = VY1,       
//   .centerX = 2869,         // Measured center for left X
//   .centerY = 2976,         // Measured center for left Y
  .deadzone = 100,
  .realCenter = 2048,       // Typically the midpoint of the ADC (0-4095)
  .isLeft = true
};

// Right Joystick
// JoystickConfig rightJoystick = {
//   .analogXPin = ,       // e.g., pin 32
//   .analogYPin = ,       // e.g., pin 33
// //   .centerX = 3000,         
// //   .centerY = 3050,       
//   .deadzone = 100,
//   .realCenter = 2048,
//   .isLeft = false
// };

BleGamepad bleGamepad;

void setup() {
    bleGamepad.begin();
    Serial.begin(115200);
    analogSetAttenuation(ADC_11db);

    pinMode(PUSH_BUTTON, INPUT_PULLUP); 
    pinMode(PUSH_BUTTON2, INPUT_PULLUP);
    pinMode(SW1, INPUT_PULLUP);
    pinMode(VX1, INPUT);
    pinMode(VY1, INPUT);

    delay(2500);
    calibrateJoystick(leftJoystick);

    delay(2500);
    calibrateJoystick(rightJoystick);
}

void loop() {
    if (bleGamepad.isConnected()) {
        button_press(PUSH_BUTTON, BUTTON_1);
        button_press(PUSH_BUTTON2, BUTTON_2);

        button_press(SW1, BUTTON_3);

        // joystickControlScaled(VX1, VY1);
        joystickControl(leftJoystick);
        joystickControl(rightJoystick);
    }
}

