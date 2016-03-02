#ifndef Magnetometro_h
#define Magnetometro_h

#include <Arduino.h>
#include <Wire.h>
#include <HMC5883L.h>
#include <Direction.h>

#define SCALE 1.3
#define MARINGA_DEC_ANGLE -0.312123048

class Magnetometro {

    private:
        float declinationAngle = MARINGA_DEC_ANGLE;
        int region[9] = {0, 45, 90, 135, 180, 225, 270, 315, 360};
        HMC5883L compass;

    public:
        class MagData {
            private:
                float x, y, z;

            public:
                MagData(float _x, float _y, float _z) {
                    x = _x;
                    y = _y;
                    z = _z;
                }
                float getX() { return x; }
                float getY() { return y; }
                float getZ() { return z; }
        };

        Magnetometro() {
            Wire.begin();
            compass = HMC5883L();
            compass.SetScale(SCALE);
            compass.SetMeasurementMode(Measurement_Continuous);
        }

        Magnetometro(float scale) {
            Wire.begin();
            compass = HMC5883L();
            compass.SetScale(scale);
            compass.SetMeasurementMode(Measurement_Continuous);
        }

        MagData* readRaw();
        MagData* readScaled();
        Direction::Enum getDirection();
        void setDeclinationAngle(float radians);
        float getDeclinationAngle();
};

#endif

