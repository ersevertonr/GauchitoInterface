#ifndef Gauchito_h
#define Gauchito_h

#include "../Communication/Communication.h"

#include "../Engine/GEngine.h"
#include "../Engine/Encoder.h"
#include "../Engine/Engine.h"

#include "../Engine/Reducer.h"
#include "../Engine/BrakeMode.h"
#include "../Engine/SpinMode.h"

#include "../Ultrasonic/Ultrasonic.h"
#include "../Ultrasonic/UltrasonicHandler.h"

#include "../IR/IR.h"
#include "../IR/IRHandler.h"

#include "../Magnetometro/Magnetometro.h"

#define RDIR 27
#define RPWM 45
#define RBRAKE 25
#define RCHA 19
#define RCHB 23
#define RINT 4

#define LDIR 26
#define LPWM 8
#define LBRAKE 24
#define LCHA 3
#define LCHB 22
#define LINT 1

#define ULTRASONIC_PIN 7

#define IR01_PIN A10
#define IR02_PIN A11
#define IR03_PIN A12
#define IR04_PIN A13
#define IR05_PIN A14
#define IR06_PIN A15

class Gauchito {

    private:
        Gauchito(Communication *comm) {
            this->comm = comm;
        }

        static Gauchito *instance;
        Communication *comm;
        Ultrasonic *ultrasonic;
        IR *irs[6];
        Magnetometro *compass;
        GEngine *rightEng, *leftEng;

        void sendData();
        void buildREngine();
        void buildLEngine();
        void buildUltrasound();
        void buildIRs();
        void buildCompass();

    public:
        static Gauchito* getInstance(Communication *comm);

        void initialize() {
            Serial.println("Gauchito initializing\n");
            buildREngine();
            buildLEngine();
            buildUltrasound();
            buildIRs();
            buildCompass();
            Serial.println("\nGauchito initialized");
            Serial.println("***********************");
            delay(1000);
        }

        void run();

        GEngine * getREngine();
        GEngine * getLEngine();
        IR * getIR(int idx);
	Ultrasonic *getUltrasound();
        Magnetometro *getMagnetometro();
};

#endif Gauchito_h
