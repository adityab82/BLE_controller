#include <Arduino.h>
#include <button.h>
#include "bleGamepadExtern.h"

void button_press(int pin_number, int button_number){
    if(!digitalRead(pin_number)){
        bleGamepad.press(button_number);
    }
    else{
        bleGamepad.release(button_number);
    }
}