#ifndef SonarHandler_h
#define SonarHandler_h

class SonarHandler {

    public:
        virtual long apply(long volts) = 0;

};

class Centimeters : public SonarHandler {
    public:
        long apply(long msec) {
            return ((msec*172) - 273000) / 10000;
        }
};

#endif 
