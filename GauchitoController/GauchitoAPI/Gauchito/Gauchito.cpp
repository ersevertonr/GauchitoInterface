#include "Gauchito.h"

typedef struct {
    char value[10];
} Data;

typedef struct {
    Data dataset[6];
} GauchitoData;

static bool fInitialized = false;
extern GauchitoData gData;
Gauchito* Gauchito::instance = 0;

Gauchito* Gauchito::getInstance(Communication *comm) {
    if (!instance) {
        instance = new Gauchito(comm);
    }
    return instance;
}

void Gauchito::run() {
    if (!fInitialized) {
        initialize();
        fInitialized = true;
    }
    //comm->run();
    sendData();
}

void Gauchito::sendData() {

    dtostrf(irs[0]->readInCentimeters(), 0, 2, gData.dataset[0].value);
    dtostrf(irs[1]->readInCentimeters(), 0, 2, gData.dataset[1].value);
    dtostrf(irs[2]->readInCentimeters(), 0, 2, gData.dataset[2].value);
    dtostrf(irs[3]->readInCentimeters(), 0, 2, gData.dataset[3].value);
    dtostrf(irs[4]->readInCentimeters(), 0, 2, gData.dataset[4].value);
    dtostrf(ultrasonic->readInCentimeters(), 0, 2, gData.dataset[5].value);

/*
    Serial.print("IR_01 "); Serial.println(gData.dataset[0].value);
    Serial.print("IR_02 "); Serial.println(gData.dataset[1].value);
    Serial.print("IR_03 "); Serial.println(gData.dataset[2].value);
    Serial.print("IR_04 "); Serial.println(gData.dataset[3].value);
    Serial.print("IR_05 "); Serial.println(gData.dataset[4].value);
    Serial.print("ULTRASSOM "); Serial.println(gData.dataset[5].value);
*/

}

void Gauchito::buildUltrasound() {
    Serial.println("building Ultrasonic...");
    ultrasonic = new Ultrasonic(ULTRASONIC_PIN);
}

void Gauchito::buildREngine() {
    Serial.println("building REngine...");
    GEngine *gEngRight;
    Encoder *encRight;
    Reducer *redRight;
    Engine *engRight;

    encRight = Encoder::Builder()
        .channelA(RCHA)
        .channelB(RCHB)
        .interruptionPin(RINT)
        .resolution(16)
        .wheelCircunference(1)
        .build();

    redRight = new Reducer(19);

    engRight = Engine::Builder()
        .directionPin(RDIR)
        .pwmPin(RPWM)
        .brakePin(RBRAKE)
        .configure();
    
  rightEng = new GEngine(engRight, encRight, redRight);
}

void Gauchito::buildLEngine() {
    Serial.println("building LEngine...");
    GEngine *gEngLeft;
    Encoder *encLeft;
    Reducer *redLeft;
    Engine *engLeft;

    encLeft = Encoder::Builder()
        .channelA(LCHA)
        .channelB(LCHB)
        .interruptionPin(LINT)
        .resolution(16)
        .wheelCircunference(1)
        .build();

    redLeft = new Reducer(19);

    engLeft = Engine::Builder()
        .directionPin(LDIR)
        .pwmPin(LPWM)
        .brakePin(LBRAKE)
        .configure();
    
  leftEng = new GEngine(engLeft, encLeft, redLeft); 
}

void Gauchito::buildIRs() {
    Serial.println("building IRs...");
    irs[0] = new IR(IR01_PIN);
    irs[1] = new IR(IR02_PIN);
    irs[2] = new IR(IR03_PIN);
    irs[3] = new IR(IR04_PIN);
    irs[4] = new IR(IR05_PIN);
    irs[5] = new IR(IR06_PIN);
}

void Gauchito::buildCompass() {
    compass = new Magnetometro();
}

GEngine * Gauchito::getREngine() {
    return rightEng;
}

GEngine * Gauchito::getLEngine() {
    return leftEng;
}

IR* Gauchito::getIR(int idx) {
    return irs[idx];
}

Ultrasonic * Gauchito::getUltrasound() {
    return ultrasonic;
}

Magnetometro* Gauchito::getMagnetometro() {
    return compass;
}

