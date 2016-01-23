#include "IR.h"

//float IR::read() {
ulong_t IR::read() {
    return analogRead(pin);
}

//float IR::readIn(IRHandler *handler) {
ulong_t IR::readIn(IRHandler *handler) {
    return handler->apply(read());
}

//float IR::readInCentimeters() {
ulong_t IR::readInCentimeters() {
    return (float)(2914.0 / (read() + 5.0)) - 1.0;
}