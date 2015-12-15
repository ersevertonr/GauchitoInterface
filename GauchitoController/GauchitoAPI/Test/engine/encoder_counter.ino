#include <Encoder.h>
#include <Engine.h>
#include <BrakeMode.h>
#include <SpinMode.h>

#define ENC_PORT PINC

Engine *eng;
Encoder *enc;

void setup() {
  Serial.begin(9600);
  
   eng = Engine::Builder()
           .directionPin(7)
           .pwmPin(A0)
           .brakePin(6)
           .configure();
           
    enc = Encoder::Builder()
         .channelA(2)
         .channelB(11)
         .interruptionPin(0)
         .resolution(16)
         .wheelCircunference(1)
         .build();
}

void loop() {
  eng->forward(100);
  
  delay(200);
  
  Serial.print("CHA: "); Serial.print(enc->readChannelA());
  Serial.print("| CHB: "); Serial.print(enc->readChannelB());
  Serial.print("| Counter: "); Serial.print(enc->getCounter());
  Serial.print("| Rotation: "); Serial.println(enc->readRotations());
}

