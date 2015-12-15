#ifndef IR_h
#define IR_h

#include "IRHandler.h"
#include "Arduino.h"

typedef unsigned char uchar_t;

class IR {

    public:
        IR(uint8_t pin) {
            this->pin = pin;
            pinMode(pin, INPUT);
        }

    float read();
    float readIn(IRHandler *handler);
    float readInCentimeters();

    private:
        uint8_t pin;
        IRHandler *cmHandler = new IRCentimeters();

};

#endif IR_h
