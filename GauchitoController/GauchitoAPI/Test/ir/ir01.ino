#include <IR.h>
#include <IRHandler.h>

IR *ir_01 = new IR(A14);

void setup() {
  Serial.begin(9600);
}

void loop(){
  Serial.print("IR_01 => ");
  Serial.print(ir_01->read());
  
  
  Serial.print(" | ");
  Serial.println(ir_01->readInCentimeters());
  
  delay(100);
}

