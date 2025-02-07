#include <Arduino.h>
#include "joystick.h"
#include <LittleFS.h>

void calibrateJoystick(JoystickConfig &jsConfig){
        //Calibration routine to find center
        long sumX = 0;
        long sumY = 0;

        for (int i = 0; i < NUM_SAMPLES; i++) {
                sumX += analogRead(jsConfig.analogXPin);
                sumY += analogRead(jsConfig.analogYPin);
                delay(10);
        }

        jsConfig.centerX = sumX / NUM_SAMPLES;
        jsConfig.centerY = sumY / NUM_SAMPLES;
        
        // Print the calculated center values
        if (jsConfig.isLeft){
                Serial.println("For Left Joystick: ");
                Serial.print("Center X: ");
                Serial.println(jsConfig.centerX);
                Serial.print("Center Y: ");
                Serial.println(jsConfig.centerY);
        }
        else {
                Serial.println("For Right Joystick: ");
                Serial.print("Center X: ");
                Serial.println(jsConfig.centerX);
                Serial.print("Center Y: ");
                Serial.println(jsConfig.centerY);
        }

        logCalibrationData(jsConfig);
}      

void joystickControl(const JoystickConfig &jsConfig){
        int xGamepad, yGamepad;
        int16_t xval = analogRead(jsConfig.analogXPin);
        int16_t yval = analogRead(jsConfig.analogYPin);

        int dx = xval - jsConfig.centerX;
        int dy = yval - jsConfig.centerY;

        //center the joystick if there is no significant movement detected
        if(abs(dx) < jsConfig.deadzone) xGamepad = map(jsConfig.realCenter, 0, 4095, (jsConfig.centerX - jsConfig.realCenter), 32767);
        else if(abs(dx) >= jsConfig.deadzone) xGamepad = map(xval, 0, 4095, (jsConfig.centerX - jsConfig.realCenter), 32767);

        if(abs(dy) < jsConfig.deadzone) yGamepad = map(jsConfig.realCenter, 0, 4095, (jsConfig.centerY - jsConfig.realCenter), 32767);
        else if(abs(dy) >= jsConfig.deadzone) yGamepad = map(yval, 0, 4095, (jsConfig.centerY - jsConfig.realCenter), 32767);

        if (jsConfig.isLeft)
                bleGamepad.setLeftThumb(xGamepad, yGamepad);
        else
                bleGamepad.setRightThumb(xGamepad, yGamepad);
}

void logCalibrationData(const JoystickConfig &jsConfig) {
    // Open the file in append mode
    File logFile = LITTLEFS.open("/calibration.log", "a"); 
    if (!logFile) {
        Serial.println("Failed to open /calibration.log for writing!");
        return;
    }

    // Simple timestamp using millis() since power-on
    unsigned long currentTime = millis();

    // Identify which joystick was calibrated
    const char *whichJs = jsConfig.isLeft ? "Left" : "Right";

    // Write the line: time, joystick label, and centers
    logFile.printf("Time: %lu ms, Joystick: %s, centerX: %d, centerY: %d\n",
                   currentTime, whichJs, jsConfig.centerX, jsConfig.centerY);

    logFile.close();
    Serial.println("Calibration data logged to /calibration.log");
}

// void joystickControlScaled(int inputX, int inputY){     //TODO
//         int xGamepad, yGamepad;
//         int16_t xval = analogRead(VX1);
//         int16_t yval = analogRead(VY1);

//         int dx = xval - centerX;
//         int dy = yval - centerY;

//         if (abs(dx) < deadzone) dx = 0;
//         if (abs(dy) < deadzone) dy = 0;

//         float ratio, scaled;

//         if (dx >= 0) {
//                 // Normalize dx for the positive side (0 to maxPosX)
//                 ratio = (float)dx / maxPosX;
//                 // Apply quadratic scaling; small ratios become even smaller.
//                 scaled = pow(ratio, exponent);
//                 // Map to the positive gamepad range (0 to 32767)
//                 xGamepad = (int)(scaled * 32767);
//         } else {
//                 // For negative dx, normalize the absolute value (0 to maxNegX)
//                 ratio = (float)(-dx) / maxNegX;
//                 scaled = pow(ratio, exponent);
//                 // Map to the negative gamepad range (0 to -32767)
//                 xGamepad = -(int)(scaled * 32767);
//         }

//         if (dy >= 0) {
//                 ratio = (float)dy / maxPosY;
//                 scaled = pow(ratio, exponent);
//                 yGamepad = (int)(scaled * 32767);
//         } else {
//                 ratio = (float)(-dy) / maxNegY;
//                 scaled = pow(ratio, exponent);
//                 yGamepad = -(int)(scaled * 32767);
//         }

//         bleGamepad.setLeftThumb(xGamepad, yGamepad);
// }