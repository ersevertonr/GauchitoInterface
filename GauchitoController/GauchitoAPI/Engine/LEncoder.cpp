#include "LEncoder.h"

uint8_t LEncoder::IDXDECODING = 0;
uint8_t LEncoder::Builder::_IDXCOUNTER = 0;
LEncoder *LEncoder::Builder::_ENCODERS2DECODE[2];

void LEncoder::attach() {
    attachInterrupt(interruptionPin, LEncoder::encode, CHANGE);
}

void LEncoder::detach() {
    detachInterrupt(interruptionPin);
}

void LEncoder::reset() {
    setCounter(0);
}

long LEncoder::getCounter() {
   return counter;
}

void LEncoder::setCounter(long value) {
    counter = value;
}

int LEncoder::readRotations() {
    return getCounter() / (resolution * 2);
}

uchar_t LEncoder::readChannelA() {
    return digitalRead(channelA);
}

uint8_t LEncoder::readChannelB() {
    return digitalRead(channelB);
}

void LEncoder::encode() {
    LEncoder *enc = LEncoder::Builder::_ENCODERS2DECODE[LEncoder::IDXDECODING];

    long position = enc->getCounter();
    if (enc->readChannelA()) enc->readChannelB() ? position++ : position--;
    else enc->readChannelB() ? position-- : position++;

    enc->setCounter(position);
}

