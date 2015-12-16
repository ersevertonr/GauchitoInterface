#ifndef Communication_h
#define Communication_h

#include "SecurityType.h"

#include "Arduino.h"
#include "../ZG2100BasedWiFiShield/WiShield.h"
#include "../ZG2100BasedWiFiShield/uip.h"
#include "../ZG2100BasedWiFiShield/config.h"

#define WIRELESS_MODE_INFRA	1

typedef unsigned char uchar_t;

class Communication {
    private:
        static Communication *instance;
        Communication(){};
  
    public:
        static Communication* getInstance();
	    Communication &localIp(uchar_t a, uchar_t b, uchar_t c, uchar_t d);
	    Communication &gatewayIp(uchar_t a, uchar_t b, uchar_t c, uchar_t d);
	    Communication &subnetMask(uchar_t a, uchar_t b, uchar_t c, uchar_t d);
	    Communication &securityType(SecurityType::Enum value);
            Communication &targetIp(uchar_t a, uchar_t b, uchar_t c, uchar_t d);
            Communication &targetPort(int value);
            Communication &ssid(char *value);
	    void connect();
	    void run();
};

#endif
