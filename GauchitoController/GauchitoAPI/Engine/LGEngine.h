#ifndef LGEngine_h
#define LGEngine_h

#include "Engine.h"
#include "LEncoder.h"
#include "Reducer.h"

class LGEngine {
    public:
        LGEngine(Engine *_eng, LEncoder *_enc, Reducer *_red) {
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
        LEncoder *encoder;
        Reducer *reducer;
};

#endif LGEngine_h
