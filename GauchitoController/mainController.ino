#include <Communication.h>
#include <SecurityType.h>
#include <UltrasonicHandler.h>
#include <Ultrasonic.h>
#include <IR.h>
#include <IRHandler.h>
#include "WiShield.h"

#define TAMVAR 20

typedef struct {
    char *value;
} Data;

typedef struct {
    Data dataset[50];
} GauchitoData;

GauchitoData gData;

int indice = 0;

Ultrasonic *ultrasonic = new Ultrasonic(7);
IR *ir0 = new IR(A14);

// ------------------------------------------------------------------- //
// --                         GAUCHITO                              -- /
// ------------------------------------------------------------------- //

 const prog_char ssid[] PROGMEM = {"ChurrascoComChimarrao"};
 const prog_char security_passphrase[] PROGMEM = {""};

Communication *comm = Communication::getInstance();

void setup() {
  Serial.begin(9600);
  
  comm->localIp(192,168,1,129)
    .gatewayIp(192,168,1,255)
    .subnetMask(255,255,255,0)
    .securityType(SecurityType::OPEN)
    .targetIp(192,168,1,100)
    .targetPort(12345)
    .connect();  
  
}

void loop() {
  comm->run();
  enviaDados();
  
  delay(500);
}

void enviaDados() {
  
// ----- CONVERSAO DOS DADOS ------ //
  indice++;
  char indiceConvert[TAMVAR];
  sprintf(indiceConvert, "%i", indice);

// ----- INFRAVERMELHO -----
  char IR0Cm[TAMVAR];
  //sprintf(IR0Cm, "%f", ir0->readInCentimeters());
  float teste = 3.14;
  sprintf(IR0Cm, "%f", teste);
  
// ----- ULTRASSOM -----
  char USDistCm[TAMVAR];
  sprintf(USDistCm, "%i",ultrasonic->readInCentimeters());

  char USDistPl[TAMVAR];
  sprintf(USDistPl, "%i",ultrasonic->readInInches());
  
// ----- SONAR -----  



// ------- MAPEAMENTO DE VARIVEIS ---------------------------------------
  gData.dataset[0].value = indiceConvert;  
  gData.dataset[1].value = "GPSLat";          //GPS Latitude  
  gData.dataset[2].value = "GPSLon";          //GPS Longitude
  gData.dataset[3].value = IR0Cm;             //Infravermelho 1
  gData.dataset[4].value = "IR1";             //Infravermelho 2
  gData.dataset[5].value = "IR2";             //Infravermelho 3
  gData.dataset[6].value = "IR3";             //Infravermelho 4
  gData.dataset[7].value = "IR4";             //Infravermelho 5
  gData.dataset[8].value = "IR5";             //Infravermelho 6
  gData.dataset[9].value = "SonarSinal";      //Sinal do Sonar
  gData.dataset[10].value = "SonarDist";      //Distancia Medida pelo Sonar
  gData.dataset[11].value  = "MEV";           //Motor Esquerdo Velocidade
  gData.dataset[12].value  = "MED";           //Motor Esquerdo Distancia Percorrida
  gData.dataset[13].value  = "MDV";           //Motor Direito Velocidade
  gData.dataset[14].value  = "MDD";           //Motor Direito Distancia Percorrida
  gData.dataset[15].value  = "VET";           //Velocidade Total
  gData.dataset[16].value  = "DPT";           //Distancia Percorrida Total
  gData.dataset[17].value = "USSinal";        //Sinal do Ultrassom
  gData.dataset[18].value = USDistCm;  //Distancia Medida pelo Ultrassom em Cm
  gData.dataset[19].value = USDistPl;  //Distancia Medida pelo Ultrassom em Polegadas
  gData.dataset[20].value = "Bussola";        //Orientacao Bussola  
}

