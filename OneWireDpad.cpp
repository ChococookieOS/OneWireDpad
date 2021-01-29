#include "OneWireDpad.h"

#define THRESHOLD 20

Dpad::Dpad(int pin){
    pinMode(pin, INPUT);
    _pin = pin;
}

Dpad::Dpad(int pin, int upVal, int leftVal, int rightVal, int downVal){
    _pin = pin;
	upValue = upVal;
	rightValue = rightVal;
	downValue = downVal;
	leftValue = leftVal;
}

void Dpad::printCalibration(){
    Serial.print("Current button value: ");
    Serial.println(analogRead(_pin));
}

Dpad::Direction Dpad::getButtonInput(){
    int read = analogRead(_pin);
    if(upValue - THRESHOLD < read && upValue + THRESHOLD > read){
        return UP;
    }
    else if(leftValue - THRESHOLD < read && leftValue + THRESHOLD > read){
        return LEFT;
    }
    else if(rightValue - THRESHOLD < read && rightValue + THRESHOLD > read){
        return RIGHT;
    }
    else if(downValue - THRESHOLD < read && downValue + THRESHOLD > read){
        return DOWN;
    }
    else {
        return NONE;
    }
    
}
