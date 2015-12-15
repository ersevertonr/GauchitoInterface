#ifndef Sonar_h
#define Sonar_h

#include "Arduino.h"
#include "SonarHandler.h"

typedef unsigned long ulong_t;
typedef unsigned char uchar_t;

class Sonar {
    
    public:
        Sonar(uchar_t initPin, uchar_t echoPin) {
            this->initPin = initPin;
            this->echoPin = echoPin;
            pinMode(initPin, OUTPUT);
            pinMode(echoPin, INPUT);
            delay(1000);
        }
        ulong_t read();
        ulong_t readIn(SonarHandler *handler);
        ulong_t readInCentimeters();

    private:
        uchar_t initPin;
        uchar_t echoPin;
        SonarCentimeters *cmHandler;
};

#endif Sonar_h
