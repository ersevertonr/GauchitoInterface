#include "Sonar.h"

ulong_t Sonar::read() {
	ulong_t tempo;
    digitalWrite(initPin, HIGH);

    tempo = micros();

    while (digitalRead(echoPin) == LOW);
    tempo = micros() - tempo;
    digitalWrite(initPin, LOW);

    return tempo;
}

ulong_t Sonar::readIn(SonarHandler *handler) {
    return handler->apply(read());
}

ulong_t Sonar::readInCentimeters() {
    return cmHandler->apply(read());
}

ulong_t Sonar::readInInches() {
    return inHandler->apply(read());
}
