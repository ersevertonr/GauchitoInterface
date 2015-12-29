#include <Communication.h>
#include <SecurityType.h>
#include "WiShield.h"

typedef struct {
    char *value;
} Data;

typedef struct {
    Data dataset[20];
} GauchitoData;

GauchitoData gData;

// ------------------------------------------------------------------- //
// --                         GAUCHITO                              -- /
// ------------------------------------------------------------------- //

const prog_char ssid[] PROGMEM = {"Gauchito"};
const prog_char security_passphrase[] PROGMEM = {"gauchito"};

Communication *comm = Communication::getInstance();

void setup() {
  Serial.begin(9600);
  
  comm->localIp(192,168,0,129)
    .gatewayIp(192,168,0,1)
    .subnetMask(255,255,255,0)
    .securityType(SecurityType::WPA2)
    .targetIp(192,168,0,101)
    .targetPort(12345)
    .connect();
  
}

void loop() {
  comm->run();
  setFakeData();
}

void setFakeData() {
  Serial.println("x");
// ------------------ GPS ------------------------
  gData.dataset[0].value = "GPSLat";       //GPS Latitude
  gData.dataset[1].value = "GPSLon";       //GPS Longitude

// ------------------ INFRAVERMELHO --------------  
  gData.dataset[2].value = "IR0";          //Infravermelho 1
  gData.dataset[3].value = "IR1";          //Infravermelho 2
  gData.dataset[4].value = "IR2";          //Infravermelho 3
  gData.dataset[5].value = "IR3";          //Infravermelho 4
  gData.dataset[6].value = "IR4";          //Infravermelho 5
  gData.dataset[7].value = "IR5";          //Infravermelho 6

// ------------------ SONAR ----------------------    
  gData.dataset[8].value = "SonarSinal";   //Sinal do Sonar
  gData.dataset[9].value = "SonarDist";    //Distancia Medida pelo Sonar

// ------------------ MOTORES --------------------    
  gData.dataset[10].value  = "MEV";         //Motor Esquerdo Velocidade
  gData.dataset[11].value  = "MED";         //Motor Esquerdo Distancia Percorrida
  gData.dataset[12].value  = "MDV";         //Motor Direito Velocidade
  gData.dataset[13].value  = "MDD";         //Motor Direito Distancia Percorrida
  gData.dataset[14].value  = "VT";          //Velocidade Total
  gData.dataset[15].value  = "DPT";         //Distancia Percorrida Total
  
// ------------------ ULTRASSOM --------------------    
  gData.dataset[16].value = "USSinal";     //Sinal do Ultrassom
  gData.dataset[17].value = "USDist";      //Distancia Medida pelo Ultrassom
  
// ------------------ BUSSOLA --------------------    
  gData.dataset[18].value = "Bussola";     //Orientacao Bussola
}
