#ifndef Dpad_h
#define Dpad_h
#include "Arduino.h"


class Dpad {
    public:
		enum Direction{NONE, UP, LEFT, RIGHT, DOWN};
        Dpad(int pin);
        Dpad(int pin, int upVal, int leftVal, int rightVal, int downVal);
        Direction getButtonInput();
        void printCalibration();

    private:
        int _pin;
        int upValue;
        int rightValue;
        int downValue;
        int leftValue;

};

#endif