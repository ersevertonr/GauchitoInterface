#include "LGEngine.h"

void LGEngine::forward(uint8_t speed) {
    engine->forward(speed);
}

void LGEngine::reverse(uint8_t speed) {
    engine->reverse(speed);
}

void LGEngine::brake(BrakeMode::Enum value) {
    engine->brake(value);
}

void LGEngine::freeSpin(SpinMode::Enum value) {
    engine->freeSpin(value);
}

void LGEngine::resetPosition() {
    encoder->reset();
}

void LGEngine::setPosition(int value) {
    encoder->setCounter(value);
}

int LGEngine::readRotations() {
    return (int) encoder->readRotations() / reducer->getValue();
}

int LGEngine::readWheelRotations() {
    return readRotations() / reducer->getValue();
}

