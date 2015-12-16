#include <Communication.h>
#include <SecurityType.h>
#include "WiShield.h"

const prog_char ssid[] PROGMEM = {"ssid"};
const prog_char security_passphrase[] PROGMEM = {"pass"};

Communication *comm = Communication::getInstance();

void setup() { 
  comm->localIp(192,168,0,30)
    .gatewayIp(192,168,0,1)
    .subnetMask(255,255,255,0)
    .securityType(SecurityType::OPEN)
    .targetIp(192,168,0,2)
    .targetPort(12345)
    .connect();
}

void loop() {
  comm->run();
}

