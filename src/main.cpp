#include <Arduino.h>
#include <BleGamepad.h>
#include <button.h>
#include <joystick.h>

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

    //calibration routine to find center
    // delay(20000);

    // long sumX = 0;
    // long sumY = 0;


    // for (int i = 0; i < NUM_SAMPLES; i++) {
    //         sumX += analogRead(VX1);
    //         sumY += analogRead(VY1);
    //         delay(10);
    // }

    // int centerX = sumX / NUM_SAMPLES;
    // int centerY = sumY / NUM_SAMPLES;
    
    // // Print the calculated center values
    // Serial.print("Center X: ");
    // Serial.println(centerX);
    // Serial.print("Center Y: ");
    // Serial.println(centerY);
}

void loop() {
    if (bleGamepad.isConnected()) {
        button_press(PUSH_BUTTON, BUTTON_1);
        button_press(PUSH_BUTTON2, BUTTON_2);

        button_press(SW1, BUTTON_3);

        joystickControl(VX1, VY1);
    }
}

