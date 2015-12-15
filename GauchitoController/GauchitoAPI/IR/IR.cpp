#include "IR.h"

float IR::read() {
    return analogRead(pin);
}

float IR::readIn(IRHandler *handler) {
    return handler->apply(read());
}

float IR::readInCentimeters() {
    return (float)(2914.0 / (read() + 5.0)) - 1.0;
}
