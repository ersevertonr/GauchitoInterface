#ifndef GEngine_h
#define GEngine_h

#include "Engine.h"
#include "Encoder.h"
#include "Reducer.h"

class GEngine {
    public:
        GEngine(Engine *_eng, Encoder *_enc, Reducer *_red) {
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
        Encoder *encoder;
        Reducer *reducer;
};

#endif GEngine_h
