#ifndef LEncoder_h
#define LEncoder_h

#include "Arduino.h"

#define ENC2DECODE 2

typedef unsigned char uchar_t;

class LEncoder {

    public:
        class Builder {
            public:
                static uint8_t _IDXCOUNTER;
                static LEncoder * _ENCODERS2DECODE[ENC2DECODE];

                uchar_t _channelA;
                uchar_t _channelB;
                uchar_t _interruptionPin;
                uchar_t _resolution;
                float _wheelCircunference;

                Builder &channelA(uchar_t value) {
                    _channelA = value;
                    return *this;
                }
                Builder &channelB(uchar_t value) {
                    _channelB = value;
                    return *this;
                }
                Builder &interruptionPin(uchar_t value) {
                    _interruptionPin = value;
                    return *this;
                }
                Builder &resolution(uchar_t value) {
                    _resolution = value;
                    return *this;
                }
                Builder &wheelCircunference(float value) {
                    _wheelCircunference = value;
                    return *this;
                }
                LEncoder *build() {
                    LEncoder *enc = new LEncoder(this);
                    _ENCODERS2DECODE[_IDXCOUNTER] = enc;
                    _IDXCOUNTER = _IDXCOUNTER + 1;
                    enc->attach();
                    return enc;
                }
        };

        void setCounter(long value);
        void reset();
        long getCounter();
        int readRotations();
        uchar_t readChannelA();
        uchar_t readChannelB();

    private:
        static uint8_t IDXDECODING;
        uint8_t idx;
        uchar_t interruptionPin;
        uchar_t resolution;
        uchar_t channelA;
        uchar_t channelB;
        float wheelCircunference;
        volatile long counter;

        void attach();
        void detach();
        static void encode();

        LEncoder() { }
        LEncoder(Builder *builder) {
            idx = builder->_IDXCOUNTER;
            interruptionPin = builder->_interruptionPin;
            resolution = builder->_resolution;
            wheelCircunference = builder->_wheelCircunference;
            channelA = builder->_channelA;
            channelB = builder->_channelB;
            
            pinMode(channelA, INPUT);
            pinMode(channelB, INPUT);
            digitalWrite(channelA, HIGH);
            digitalWrite(channelB, HIGH);
            counter = 0;
        }

};

#endif LEncoder_h
