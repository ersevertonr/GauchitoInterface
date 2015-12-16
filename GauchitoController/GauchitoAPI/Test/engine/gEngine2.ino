#include <Encoder.h>
#include <Engine.h>
#include <GEngine.h>
#include <BrakeMode.h>
#include <SpinMode.h>
#include <Reducer.h>

#define ENC_PORT PINC

Encoder *enc;
GEngine *gEng;

void setup() {
  Serial.begin(9600);
  
   Engine* eng = Engine::Builder()
           .directionPin(26)
           .pwmPin(8)
           .brakePin(24)
           .configure();
           
    enc = Encoder::Builder()
         .channelA(3)
         .channelB(22)
         .interruptionPin(1)
         .resolution(16)
         .wheelCircunference(1)
         .build();
         
    Reducer *red = new Reducer(19);
    gEng = new GEngine(eng, enc, red);
}

void loop() {
  gEng->forward(20);
  
  delay(200);
  
  Serial.print("CHA: "); Serial.print(enc->readChannelA());
  Serial.print("| CHB: "); Serial.print(enc->readChannelB());
  Serial.print("| Counter: "); Serial.print(enc->getCounter());
  Serial.print("| Rotation: "); Serial.println(gEng->readRotations());
}

