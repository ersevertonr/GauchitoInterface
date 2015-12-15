#include "Ultrasonic.h"

ulong_t Ultrasonic::read() {
    pinMode(signalPin, OUTPUT);
    digitalWrite(signalPin, LOW);
    digitalWrite(signalPin, LOW);
    delayMicroseconds(2);
    digitalWrite(signalPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(signalPin, LOW);

    pinMode(signalPin, INPUT);
    return pulseIn(signalPin, HIGH);
}

ulong_t Ultrasonic::readIn(UltrasonicHandler *handler) {
    return handler->apply(read());
}

ulong_t Ultrasonic::readInCentimeters() {
    return cmHandler->apply(read());
}

ulong_t Ultrasonic::readInInches() {
    return inHandler->apply(read());
}

