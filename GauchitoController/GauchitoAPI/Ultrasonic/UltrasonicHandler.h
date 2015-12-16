#ifndef UltrasonicHandler_h
#define UltrasonicHandler_h

class UltrasonicHandler {

    public:
        virtual long apply(long microsec) = 0;
};

class Centimeters : public UltrasonicHandler {
    public:
        long apply(long microsec) {
            return microsec/29/2;
        }
};	

class Inches : public UltrasonicHandler {
    public:
        long apply(long microsec) {
            return microsec/74/2;
        }
};

#endif
