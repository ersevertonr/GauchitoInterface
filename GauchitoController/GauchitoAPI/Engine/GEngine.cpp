#include "GEngine.h"

void GEngine::forward(uint8_t speed) {
    engine->forward(speed);
}

void GEngine::reverse(uint8_t speed) {
    engine->reverse(speed);
}

void GEngine::brake(BrakeMode::Enum value) {
    engine->brake(value);
}

void GEngine::freeSpin(SpinMode::Enum value) {
    engine->freeSpin(value);
}

void GEngine::resetPosition() {
    encoder->reset();
}

void GEngine::setPosition(int value) {
    encoder->setCounter(value);
}

int GEngine::readRotations() {
    return (int) encoder->readRotations() / reducer->getValue();
}

int GEngine::readWheelRotations() {
    return readRotations() / reducer->getValue();
}

