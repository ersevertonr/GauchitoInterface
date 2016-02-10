#ifndef IR_h
#define IR_h

#include "IRHandler.h"
#include "Arduino.h"

typedef unsigned char uchar_t;
typedef unsigned long ulong_t;

class IR {

    public:
        IR(uint8_t pin) {
            this->pin = pin;
            pinMode(pin, INPUT);
        }

    ulong_t read();
    ulong_t readIn(IRHandler *handler);
    ulong_t readInCentimeters();

//    float read();
//    float readIn(IRHandler *handler);
//    float readInCentimeters();

    private:
        uint8_t pin;
        IRHandler *cmHandler = new IRCentimeters();

};

#endif IR_h
