#include "Encoder.h"

uint8_t Encoder::IDXDECODING = 0;
uint8_t Encoder::Builder::_IDXCOUNTER = 0;
Encoder *Encoder::Builder::_ENCODERS2DECODE[2];

void Encoder::attach() {
    attachInterrupt(interruptionPin, Encoder::encode, CHANGE);
}

void Encoder::detach() {
    detachInterrupt(interruptionPin);
}

void Encoder::reset() {
    setCounter(0);
}

long Encoder::getCounter() {
   return counter;
}

void Encoder::setCounter(long value) {
    counter = value;
}

int Encoder::readRotations() {
    return getCounter() / (resolution * 2);
}

uchar_t Encoder::readChannelA() {
    return digitalRead(channelA);
}

uint8_t Encoder::readChannelB() {
    return digitalRead(channelB);
}

void Encoder::encode() {
    Encoder *enc = Encoder::Builder::_ENCODERS2DECODE[Encoder::IDXDECODING];

    long position = enc->getCounter();
    if (enc->readChannelA()) enc->readChannelB() ? position++ : position--;
    else enc->readChannelB() ? position-- : position++;

    enc->setCounter(position);
}

