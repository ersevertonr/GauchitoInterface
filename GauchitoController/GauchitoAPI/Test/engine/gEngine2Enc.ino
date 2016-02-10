#include <LEncoder.h>
#include <REncoder.h>
#include <Engine.h>
#include <LGEngine.h>
#include <RGEngine.h>
#include <BrakeMode.h>
#include <SpinMode.h>
#include <Reducer.h>

#define ENC_PORT PINC

LEncoder *leftEnc;
LGEngine *leftgEng;
REncoder *rightEnc;
RGEngine *rightgEng;

void setup() {
  Serial.begin(9600);
  
  Engine* leftEng = Engine::Builder().directionPin(26).pwmPin(8).brakePin(24).configure();     
  leftEnc = LEncoder::Builder().channelA(3).channelB(22).interruptionPin(1).resolution(16).wheelCircunference(1).build();
  Reducer *leftRed = new Reducer(19);
  leftgEng = new LGEngine(leftEng, leftEnc, leftRed);

  Engine* rightEng = Engine::Builder().directionPin(27).pwmPin(45).brakePin(25).configure();           
  rightEnc = REncoder::Builder().channelA(19).channelB(23).interruptionPin(4).resolution(16).wheelCircunference(1).build();         
  Reducer *rightRed = new Reducer(19);
  rightgEng = new RGEngine(rightEng, rightEnc, rightRed);  
}

void loop() {
//  gEng->forward(20);
  
  Serial.print("ME --> ");
  Serial.print("CHA: "); Serial.print(leftEnc->readChannelA());
  Serial.print("| CHB: "); Serial.print(leftEnc->readChannelB());
  Serial.print("| Counter: "); Serial.print(leftEnc->getCounter());
  Serial.print("| Rotation: "); Serial.print(leftgEng->readRotations());
//  Serial.print("| Rotation: "); Serial.println(leftgEng->readRotations());
  
  Serial.print("          MD --> ");
  Serial.print("CHA: "); Serial.print(rightEnc->readChannelA());
  Serial.print("| CHB: "); Serial.print(rightEnc->readChannelB());
  Serial.print("| Counter: "); Serial.print(rightEnc->getCounter());
  Serial.print("| Rotation: "); Serial.println(rightgEng->readRotations());  
  
  delay(100);
}

