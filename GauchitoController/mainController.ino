#include <Communication.h>
#include <SecurityType.h>
#include <UltrasonicHandler.h>
#include <Ultrasonic.h>
#include <IR.h>
#include <IRHandler.h>
#include <SonarHandler.h>
#include <Sonar.h>
#include <Encoder.h>
#include <Engine.h>
#include <GEngine.h>
#include <BrakeMode.h>
#include <SpinMode.h>
#include <Reducer.h>
#include "WiShield.h"

#define TAMVAR 20
#define QTDE_REG 30

typedef struct { char *value;} Data;
typedef struct { Data dataset[30];} GauchitoData;

GauchitoData gData;

IR *ir0 = new IR(A15);
IR *ir1 = new IR(A14);
IR *ir2 = new IR(A13);
IR *ir3 = new IR(A12);
IR *ir4 = new IR(A11);
IR *ir5 = new IR(A10);
Sonar *sonar = new Sonar(4,5);
Ultrasonic *ultrasonic = new Ultrasonic(7);
Encoder *leftEnc;
GEngine *leftgEng;
//Encoder *rightEnc;
//GEngine *rightgEng;

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
    .targetIp(192,168,1,101)
    .targetPort(12345)
    .connect();  
  
   Engine* leftEng = Engine::Builder()
           .directionPin(26)
           .pwmPin(8)
           .brakePin(24)
           .configure();

    leftEnc = Encoder::Builder()
         .channelA(3)
         .channelB(22)
         .interruptionPin(1)
         .resolution(16)
         .wheelCircunference(1)
         .build();

//   Engine* rightEng = Engine::Builder()
//           .directionPin(26)
//           .pwmPin(8)
//           .brakePin(24)
//           .configure();                   
//
//    rightEnc = Encoder::Builder()
//         .channelA(3)
//         .channelB(22)
//         .interruptionPin(1)
//         .resolution(16)
//         .wheelCircunference(1)
//         .build();         
         
    Reducer *red = new Reducer(19);
    leftgEng = new GEngine(leftEng, leftEnc, red);
//    rightgEng = new GEngine(rightEng, rightEnc, red);
  
}

void loop() {
  comm->run();
  enviaDados();
  
  delay(50);
}

void enviaDados() {
  
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
  char USSinal[TAMVAR];
  sprintf(USSinal, "ON");

  char USDistCm[TAMVAR];
  sprintf(USDistCm, "%i",ultrasonic->readInCentimeters());

  char USDistPl[TAMVAR];
  sprintf(USDistPl, "%i",ultrasonic->readInInches());
  
// ----- SONAR -----  
  char SonarSinal[TAMVAR];
  sprintf(SonarSinal, "ON");
  
  char SonarDistCm[TAMVAR];
  sprintf(SonarDistCm, "%i",sonar->readInCentimeters());
  
  char SonarDistPl[TAMVAR];
  sprintf(SonarDistPl, "%i",sonar->readInInches());
  
// ----- MOTORES -----  
char lChA[TAMVAR];
sprintf(lChA, "%i", leftEnc->readChannelA());

char lChB[TAMVAR];
sprintf(lChB, "%i", leftEnc->readChannelB());

char lCounter[TAMVAR];
sprintf(lCounter, "%i", leftEnc->getCounter());

char lRotation[TAMVAR];
sprintf(lRotation, "%i", leftgEng->readRotations());

//char rChA[TAMVAR];
//sprintf(rChA, "%i", rightEnc->readChannelA());
//
//char rChB[TAMVAR];
//sprintf(rChB, "%i", rightEnc->readChannelB());
//
//char rCounter[TAMVAR];
//sprintf(rCounter, "%i", rightEnc->getCounter());
//
//char rRotation[TAMVAR];
//sprintf(rRotation, "%i", rightgEng->readRotations());


// ------- MAPEAMENTO DE VARIVEIS ---------------------------------------
  gData.dataset[0].value  = USDistCm;          //Distancia Medida pelo Ultrassom em Cm
  gData.dataset[1].value  = USDistPl;          //Distancia Medida pelo Ultrassom em Polegadas  
  gData.dataset[2].value  = SonarDistCm;       //Distancia Medida pelo Sonar em Centrimetros
  gData.dataset[3].value  = SonarDistPl;       //Distancia Medida pelo Sonar em Polegadas  
  gData.dataset[4].value   = "GPSSinal";       //GPS Latitude    
  gData.dataset[5].value   = "GPSLat";         //GPS Latitude  
  gData.dataset[6].value   = "GPSLon";         //GPS Longitude
  gData.dataset[7].value   = IR1Cm;            //Infravermelho 1
  gData.dataset[8].value   = IR2Cm;            //Infravermelho 2
  gData.dataset[9].value   = IR3Cm;            //Infravermelho 3
  gData.dataset[10].value  = IR4Cm;            //Infravermelho 4
  gData.dataset[11].value  = IR5Cm;            //Infravermelho 5
  gData.dataset[12].value  = IR6Cm;            //Infravermelho 6
  gData.dataset[13].value  = "BScaleX";        //Bussola Scale X
  gData.dataset[14].value  = "BScaleY";        //Bussola Scale Y
  gData.dataset[15].value  = "BScaleZ";        //Bussola Scale Y
  gData.dataset[16].value  = lChA;             //Motor Esquerdo Channel A
  gData.dataset[17].value  = lChB;             //Motor Esquerdo Channel B
  gData.dataset[18].value  = lCounter;         //Motor Esquerdo Rolagem
  gData.dataset[19].value  = lRotation;         //Motor Esquerdo Qtde de Rotacao
  gData.dataset[20].value  = lChA;           //Motor Direito Channel A
  gData.dataset[21].value  = lChB;           //Motor Direito Channel B
  gData.dataset[22].value  = lCounter;       //Motor Direito Rolagem
  gData.dataset[23].value  = lRotation;      //Motor Direito Qtde de Rotacao
  gData.dataset[24].value  = "VET";            //Velocidade Total
  gData.dataset[25].value  = "DPT";            //Distancia Percorrida Total
}

