#include <Gauchito.h>
#include <Communication.h>
#include <SecurityType.h>
#include <IR.h>
#include <IRHandler.h>
#include <Ultrasonic.h>
#include <UltrasonicHandler.h>
#include <Engine.h>
#include <Wire.h>
#include <Magnetometro.h>
#include "WiShield.h"

const prog_char ssid[] PROGMEM = {"NetworkSSID"};
const prog_char security_passphrase[] PROGMEM = {"NetworkPassword"};

typedef struct {
    char *value;
} Data;

typedef struct {
    Data dataset[8];
} GauchitoData;

Communication *comm = Communication::getInstance();
Gauchito *robot;
GauchitoData gData;

void configCOMM() {
    comm->localIp(192,168,0,129)
       .gatewayIp(192,168,0,1)
       .subnetMask(255,255,255,0)
       .securityType(SecurityType::WPA)
       .targetIp(192,168,0,2)
       .targetPort(12345)
       .connect();
}

void setup(){
  Serial.begin(9600);
  //configCOMM();
  robot = Gauchito::getInstance(0); 
}


void readUltrasound();
void readIR(int idx);
void readCompass();

void loop(){
    robot->run();
    readUltrasound();
    
    int i = 0;
    for (i = 0; i < 6; i++) {
        readIR(i);
    }

    delay(100);
    
    readCompass();
    
    Serial.println("");
    delay(1000);
}

void readUltrasound() {
  Ultrasonic *uSound = robot->getUltrasound();
  Serial.print("USOUND: "); Serial.println(uSound->readInCentimeters());
}

void readIR(int idx) {
  IR *ir = robot->getIR(idx);
  Serial.print("IR["); Serial.print(idx); Serial.print("]: ");
  Serial.println(ir->readInCentimeters());
}

void readCompass() {
  Magnetometro *compass = robot->getMagnetometro();
  Magnetometro::MagData *scaledData = compass->readScaled();
  
  delay(100);
  
  Serial.print("Coordinates[X=");
  Serial.print(scaledData->getX());
  Serial.print(", Y=");
  Serial.print(scaledData->getY());
  Serial.print(", Z=");
  Serial.print(scaledData->getZ());
  Serial.println("]");
  
  free(scaledData);
}

