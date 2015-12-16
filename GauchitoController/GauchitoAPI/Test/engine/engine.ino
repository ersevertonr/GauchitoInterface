#include <Engine.h>
#include <BrakeMode.h>
#include <SpinMode.h>

Engine *eng;

void setup() {
  Serial.begin(9600);
  eng = Engine::Builder()
           .directionPin(7)
           .pwmPin(A0)
           .brakePin(6)
           .configure();
}

void loop() {
  eng->forward(100);
}

