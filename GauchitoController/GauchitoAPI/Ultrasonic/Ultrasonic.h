#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"
#include "UltrasonicHandler.h"

typedef unsigned long ulong_t;
typedef unsigned char uchar_t;

class Ultrasonic {

    public:
        Ultrasonic(uchar_t signalPin) {
            this->signalPin = signalPin;
        }

        ulong_t read();
        ulong_t readIn(UltrasonicHandler *handler);
        ulong_t readInCentimeters();
        ulong_t readInInches();

    private:
        UltrasonicHandler *cmHandler = new Centimeters();
        UltrasonicHandler *inHandler = new Inches();
        uint8_t signalPin;
};

#endif
