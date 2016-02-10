#include "REncoder.h"

uint8_t REncoder::IDXDECODING = 0;
uint8_t REncoder::Builder::_IDXCOUNTER = 0;
REncoder *REncoder::Builder::_ENCODERS2DECODE[2];

void REncoder::attach() {
    attachInterrupt(interruptionPin, REncoder::encode, CHANGE);
}

void REncoder::detach() {
    detachInterrupt(interruptionPin);
}

void REncoder::reset() {
    setCounter(0);
}

long REncoder::getCounter() {
   return counter;
}

void REncoder::setCounter(long value) {
    counter = value;
}

int REncoder::readRotations() {
    return getCounter() / (resolution * 2);
}

uchar_t REncoder::readChannelA() {
    return digitalRead(channelA);
}

uint8_t REncoder::readChannelB() {
    return digitalRead(channelB);
}

void REncoder::encode() {
    REncoder *enc = REncoder::Builder::_ENCODERS2DECODE[REncoder::IDXDECODING];

    long position = enc->getCounter();
    if (enc->readChannelA()) enc->readChannelB() ? position++ : position--;
    else enc->readChannelB() ? position-- : position++;

    enc->setCounter(position);
}

