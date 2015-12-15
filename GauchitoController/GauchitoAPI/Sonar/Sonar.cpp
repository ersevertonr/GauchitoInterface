#include "Sonar.h"

ulong_t Sonar::read() {
    digitalWrite(initPin, HIGH);
    ulong_t delay = 0;
    delay = micros();
    while (digitalRead(echoPin) == LOW);
    digitalWrite(initPin, LOW);
    return micros() - delay;
}

ulong_t Sonar::readIn(SonarHandler *handler) {
    return handler->apply(read());
}

ulong_t Sonar::readInCentimeters() {
    return cmHandler->apply(read());
}

