#include "Magnetometro.h"
#include "Direction.h"

Magnetometro::MagData* Magnetometro::readRaw() {
    MagnetometerRaw raw = compass.ReadRawAxis();
    return new Magnetometro::MagData(raw.XAxis, raw.YAxis, raw.ZAxis);
}

Magnetometro::MagData* Magnetometro::readScaled() {
    MagnetometerScaled scaled = compass.ReadScaledAxis();
    return new Magnetometro::MagData(scaled.XAxis, scaled.YAxis, scaled.ZAxis);
}

Direction::Enum Magnetometro::getDirection() {
    float xDegrees = getDeclinationAngle();
    if (xDegrees < region[1] && xDegrees > region[0]) return Direction::NORTH; 
    if (xDegrees < region[2] && xDegrees > region[1]) return Direction::NORTHEAST;
    if (xDegrees < region[3] && xDegrees > region[2]) return Direction::EAST; 
    if (xDegrees < region[4] && xDegrees > region[3]) return Direction::SOUTHEAST;
    if (xDegrees < region[5] && xDegrees > region[4]) return Direction::SOUTH;
    if (xDegrees < region[6] && xDegrees > region[5]) return Direction::SOUTHWEST;
    if (xDegrees < region[7] && xDegrees > region[6]) return Direction::WEST;
    if (xDegrees < region[8] && xDegrees > region[7]) return Direction::NORTHWEST;
}

void Magnetometro::setDeclinationAngle(float radians) {
    declinationAngle = radians;
}

float Magnetometro::getDeclinationAngle() {
    MagnetometerScaled scaled = compass.ReadScaledAxis();
    float heading = atan2(scaled.YAxis, scaled.XAxis);
    heading += declinationAngle;

    if (heading < 0) heading += 2*PI;
    if (heading > 2*PI) heading-= 2*PI;

    return heading * 180/M_PI;
}

