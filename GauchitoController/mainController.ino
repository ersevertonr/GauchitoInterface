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

int indice = 10;

// ------------------------------------------------------------------- //
// --                         GAUCHITO                              -- /
// ------------------------------------------------------------------- //

//const prog_char ssid[] PROGMEM = {"Gauchito"};
const prog_char ssid[] PROGMEM = {"Everton GS4"};
//const prog_char security_passphrase[] PROGMEM = {"gauchito"};
const prog_char security_passphrase[] PROGMEM = {"qwertyui"};

Communication *comm = Communication::getInstance();

void setup() {
  Serial.begin(9600);
  
//  comm->localIp(192,168,0,129)
//    .gatewayIp(192,168,0,1)
//    .subnetMask(255,255,255,0)
//    .securityType(SecurityType::OPEN)
//    .targetIp(192,168,0,100)
//    .targetPort(12345)
//    .connect();
  
  comm->localIp(192,168,43,129)
    .gatewayIp(192,168,46,255)
    .subnetMask(255,255,255,0)
    .securityType(SecurityType::WPA2)
    .targetIp(192,168,43,89)
    .targetPort(12345)
    .connect();  
  
}

void loop() {
  comm->run();
  enviaDados();
  
  delay(500);
}

void enviaDados() {
  indice++;
  char indiceConvert[1000];
  sprintf(indiceConvert, "%i", indice);
  
  gData.dataset[0].value = indiceConvert;  
  
// ------------------ GPS ------------------------
  gData.dataset[1].value = "GPSLat";       //GPS Latitude  
  gData.dataset[2].value = "GPSLon";       //GPS Longitude

// ------------------ INFRAVERMELHO --------------  
  gData.dataset[3].value = "IR0";          //Infravermelho 1
  gData.dataset[4].value = "IR1";          //Infravermelho 2
  gData.dataset[5].value = "IR2";          //Infravermelho 3
  gData.dataset[6].value = "IR3";          //Infravermelho 4
  gData.dataset[7].value = "IR4";          //Infravermelho 5
  gData.dataset[8].value = "IR5";          //Infravermelho 6

// ------------------ SONAR ----------------------    
  gData.dataset[9].value = "SonarSinal";   //Sinal do Sonar
  gData.dataset[10].value = "SonarDist";    //Distancia Medida pelo Sonar

// ------------------ MOTORES --------------------    
  gData.dataset[11].value  = "MEV";         //Motor Esquerdo Velocidade
  gData.dataset[12].value  = "MED";         //Motor Esquerdo Distancia Percorrida
  gData.dataset[13].value  = "MDV";         //Motor Direito Velocidade
  gData.dataset[14].value  = "MDD";         //Motor Direito Distancia Percorrida
  gData.dataset[15].value  = "VET";          //Velocidade Total
  gData.dataset[16].value  = "DPT";         //Distancia Percorrida Total
  
// ------------------ ULTRASSOM --------------------    
  gData.dataset[17].value = "USSinal";     //Sinal do Ultrassom
  gData.dataset[18].value = "USDist";      //Distancia Medida pelo Ultrassom
  
// ------------------ BUSSOLA --------------------    
  gData.dataset[19].value = "Bussola";     //Orientacao Bussola  
}

