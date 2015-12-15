#ifndef Engine_h
#define Engine_h

#include "Arduino.h"
#include "BrakeMode.h"
#include "SpinMode.h"

typedef unsigned char uchar_t;

class Engine {

    public: 
        class Builder {
            public:
                uchar_t _currentPin;
                uchar_t _directionPin;
                uchar_t _pwmPin;
                uchar_t _brakePin;

                Builder &currentPin(uchar_t value) {
                    _currentPin = value;
                    pinMode(value, OUTPUT);
                    return *this;
                }
                Builder &directionPin(uchar_t value) {
                    _directionPin = value;
                    pinMode(value, INPUT);
                    return *this;
                }
                Builder &pwmPin(uchar_t value) {
                    _pwmPin = value;
                    return *this;
                }
                Builder &brakePin(uchar_t value) {
                    _brakePin = value;
                    pinMode(value, INPUT);
                    return *this;
                }
                Engine* configure() {
                    return new Engine(this);
                }
        };

    private:
        uchar_t currentPin;
        uchar_t directionPin;
        uchar_t brakePin;
        uchar_t pwmPin;

        Engine(Builder *builder) {
            currentPin = builder->_currentPin;
            directionPin = builder->_directionPin;
            pwmPin = builder->_pwmPin;
            brakePin = builder->_brakePin;
        }
	uint8_t calcDutyCycle(uint8_t percent);

    public:
        void forward(uint8_t value);
        void reverse(uint8_t value);
        void brake(BrakeMode::Enum value);
        void freeSpin(SpinMode::Enum value);
};

#endif
