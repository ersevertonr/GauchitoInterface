#ifndef IRHandler_h
#define IRHandler_h

class IRHandler {

    public:
        virtual long apply(long volts) = 0;

};

class IRCentimeters : public IRHandler {
    public:
        long apply(long volts) {
            return (6787.0 /((long)volts -3.0)) -4.0;
        }
};	

#endif IRHAndler_h
