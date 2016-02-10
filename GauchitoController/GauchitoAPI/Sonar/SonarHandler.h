#ifndef SonarHandler_h
#define SonarHandler_h

class SonarHandler {

    public:
        virtual long apply(long volts) = 0;

};

class SonarCentimeters : public SonarHandler {
    public:
        long apply(long msec) {
            return ((msec*172) - 273000) / 10000;
        }
};

class SonarInches : public SonarHandler {
    public:
        long apply(long msec) {
            return (((msec*172) - 273000) / 10000) / 2.54;
        }
};

#endif