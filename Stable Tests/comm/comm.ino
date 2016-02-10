#include <Communication.h>
#include <SecurityType.h>
#include "WiShield.h"

typedef struct {
    char *value;
} Data;

typedef struct {
    Data dataset[8];
} GauchitoData;

GauchitoData gData;

// ------------------------------------------------------------------- //
// --                         GAUCHITO                              -- /
// ------------------------------------------------------------------- //

const prog_char ssid[] PROGMEM = {"ChurrascoComChimarrao"};
const prog_char security_passphrase[] PROGMEM = {""};

Communication *comm = Communication::getInstance();

void setup() {
  Serial.begin(9600);
  
  comm->localIp(192,168,0,129)
    .gatewayIp(192,168,0,1)
    .subnetMask(255,255,255,0)
    .securityType(SecurityType::OPEN)
    .targetIp(192,168,0,2)
    .targetPort(12345)
    .connect();
  
}

void loop() {
  comm->run();
  setFakeData();
}

void setFakeData() {
  Serial.println("x");
  gData.dataset[0].value = "IR0";
  gData.dataset[1].value = "IR1";
  gData.dataset[2].value = "IR2";
  gData.dataset[3].value = "IR3";
  gData.dataset[4].value = "IR4";
  gData.dataset[5].value = "IR5";
  
  gData.dataset[6].value = "SONAR0";
  gData.dataset[7].value = "SONAR1";
}

