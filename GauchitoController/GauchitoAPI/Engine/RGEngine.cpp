#include "RGEngine.h"

void RGEngine::forward(uint8_t speed) {
    engine->forward(speed);
}

void RGEngine::reverse(uint8_t speed) {
    engine->reverse(speed);
}

void RGEngine::brake(BrakeMode::Enum value) {
    engine->brake(value);
}

void RGEngine::freeSpin(SpinMode::Enum value) {
    engine->freeSpin(value);
}

void RGEngine::resetPosition() {
    encoder->reset();
}

void RGEngine::setPosition(int value) {
    encoder->setCounter(value);
}

int RGEngine::readRotations() {
    return (int) encoder->readRotations() / reducer->getValue();
}

int RGEngine::readWheelRotations() {
    return readRotations() / reducer->getValue();
}

