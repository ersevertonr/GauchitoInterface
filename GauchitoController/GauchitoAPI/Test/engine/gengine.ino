#include <Encoder.h>
#include <Engine.h>
#include <Reducer.h>
#include <GEngine.h>
#include <BrakeMode.h>
#include <SpinMode.h>

GEngine *gEngine;
Engine *eng;
Reducer *red;
Encoder *enc;

void setup() {
  Serial.begin(9600);
  
   eng = Engine::Builder()
           .directionPin(26)
           .pwmPin(44)
           .brakePin(24)
           .configure();
   
   red = new Reducer(19);        
   
   enc = Encoder::Builder()
        .channelA(3)
        .channelB(22)
        .interruptionPin(1)
        .resolution(16)
        .wheelCircunference(1)
        .build();
    
   gEngine = new GEngine(eng, enc, red);
   
   gEngine->reverse(100);
}
boolean flag = false;

void loop() {
 
  if (gEngine->readRotations() == -10) {
    flag = true;
    gEngine->forward(100);
  } else {
    if (flag && gEngine->readRotations() == 0) {
      gEngine->brake(BrakeMode::ACTIVE);
    }
  }
  
  Serial.print("CHA: "); Serial.print(enc->readChannelA());
  Serial.print("| CHB: "); Serial.print(enc->readChannelB());
  Serial.print("| Counter: "); Serial.print(enc->getCounter());
  Serial.print("| Rotation: "); Serial.println(gEngine->readRotations());

}

