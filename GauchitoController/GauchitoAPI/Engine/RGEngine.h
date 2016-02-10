#ifndef RGEngine_h
#define RGEngine_h

#include "Engine.h"
#include "REncoder.h"
#include "Reducer.h"

class RGEngine {
    public:
        RGEngine(Engine *_eng, REncoder *_enc, Reducer *_red) {
            engine = _eng;
            encoder = _enc;
            reducer = _red;
        }

        void forward(uint8_t percent);
        void reverse(uint8_t percent);
        void brake(BrakeMode::Enum value);
        void freeSpin(SpinMode::Enum value);

        void setPosition(int value);
        void resetPosition();
        int readRotations();
        int readWheelRotations();

    private:
        Engine *engine;
        REncoder *encoder;
        Reducer *reducer;
};

#endif RGEngine_h
