#include <Communication.h>
#include <SecurityType.h>
#include <UltrasonicHandler.h>
#include <Ultrasonic.h>
#include <IR.h>
#include <IRHandler.h>
#include "WiShield.h"

#define TAMVAR 20
#define QTDE_REG 30

typedef struct {
    char *value;
} Data;

typedef struct {
    Data dataset[30];
} GauchitoData;

GauchitoData gData;

int indice = 0;

Ultrasonic *ultrasonic = new Ultrasonic(7);
IR *ir0 = new IR(A15);
IR *ir1 = new IR(A14);
IR *ir2 = new IR(A13);
IR *ir3 = new IR(A12);
IR *ir4 = new IR(A11);
IR *ir5 = new IR(A10);


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
  char IR1Cm[TAMVAR];
  sprintf(IR1Cm, "%i", ir0->readInCentimeters());
  
  char IR2Cm[TAMVAR];
  sprintf(IR2Cm, "%i", ir1->readInCentimeters());

  char IR3Cm[TAMVAR];
  sprintf(IR3Cm, "%i", ir2->readInCentimeters());

  char IR4Cm[TAMVAR];
  sprintf(IR4Cm, "%i", ir3->readInCentimeters());

  char IR5Cm[TAMVAR];
  sprintf(IR5Cm, "%i", ir4->readInCentimeters());

  char IR6Cm[TAMVAR];
  sprintf(IR6Cm, "%i", ir5->readInCentimeters());

  
// ----- ULTRASSOM -----
  char USDistCm[TAMVAR];
  sprintf(USDistCm, "%i",ultrasonic->readInCentimeters());

  char USDistPl[TAMVAR];
  sprintf(USDistPl, "%i",ultrasonic->readInInches());
  
// ----- SONAR -----  



// ------- MAPEAMENTO DE VARIVEIS ---------------------------------------
  gData.dataset[0].value   = indiceConvert;  
  gData.dataset[1].value   = "GPSSinal";        //GPS Latitude    
  gData.dataset[2].value   = "GPSLat";          //GPS Latitude  
  gData.dataset[3].value   = "GPSLon";          //GPS Longitude
  gData.dataset[4].value   = IR1Cm;             //Infravermelho 1
  gData.dataset[5].value   = IR2Cm;             //Infravermelho 2
  gData.dataset[6].value   = IR3Cm;             //Infravermelho 3
  gData.dataset[7].value   = IR4Cm;             //Infravermelho 4
  gData.dataset[8].value   = IR5Cm;             //Infravermelho 5
  gData.dataset[9].value   = IR6Cm;             //Infravermelho 6
  gData.dataset[10].value  = "SonarSinal";      //Sinal do Sonar
  gData.dataset[11].value  = "SonarDist";       //Distancia Medida pelo Sonar
  gData.dataset[12].value  = "MESinal";         //Motor Esquerdo Sinal
  gData.dataset[13].value  = "MEV";             //Motor Esquerdo Velocidade
  gData.dataset[14].value  = "MED";             //Motor Esquerdo Distancia Percorrida
  gData.dataset[15].value  = "MDSinal";         //Motor Direito Sinal
  gData.dataset[16].value  = "MDV";             //Motor Direito Velocidade
  gData.dataset[17].value  = "MDD";             //Motor Direito Distancia Percorrida
  gData.dataset[18].value  = "VET";             //Velocidade Total
  gData.dataset[19].value  = "DPT";             //Distancia Percorrida Total
  gData.dataset[20].value  = "USSinal";         //Sinal do Ultrassom
  gData.dataset[21].value  = USDistCm;          //Distancia Medida pelo Ultrassom em Cm
  gData.dataset[22].value  = USDistPl;          //Distancia Medida pelo Ultrassom em Polegadas
  gData.dataset[23].value  = "BSinal";         //Bussola Sinal
  gData.dataset[24].value  = "BScaleX";         //Bussola Scale X
  gData.dataset[25].value  = "BScaleY";         //Bussola Scale Y
}

