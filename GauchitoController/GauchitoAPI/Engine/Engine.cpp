#include "Engine.h"

void Engine::forward(uint8_t value) {
    digitalWrite(brakePin, LOW);
    digitalWrite(directionPin, HIGH);
    
    int val = calcDutyCycle(value);
    analogWrite(pwmPin, val);
}

void Engine::reverse(uint8_t value) {
    digitalWrite(brakePin, LOW);
    digitalWrite(directionPin, LOW);
    analogWrite(pwmPin, calcDutyCycle(value));    
}

void Engine::brake(BrakeMode::Enum value) {
    if (value == BrakeMode::ACTIVE) {
        digitalWrite(pwmPin, HIGH);
    } else {
        digitalWrite(pwmPin, LOW);
    }
    digitalWrite(brakePin, value);
    digitalWrite(directionPin, LOW);
}

void Engine::freeSpin(SpinMode::Enum value) {
    digitalWrite(brakePin, HIGH);
    digitalWrite(directionPin, value);
    digitalWrite(pwmPin, LOW);
}

uint8_t Engine::calcDutyCycle(uint8_t percent) {
        return 255 * percent / 100.0;
}
