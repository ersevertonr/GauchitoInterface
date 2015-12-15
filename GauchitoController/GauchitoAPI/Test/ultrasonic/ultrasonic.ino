#include <UltrasonicHandler.h>
#include <Ultrasonic.h>


Ultrasonic *ultrasonic = new Ultrasonic(7);
void setup() {
  Serial.begin(9600);
}
 
void loop()
{
    Serial.print("raw: "); Serial.print(ultrasonic->read());
    Serial.print("| in: "); Serial.print(ultrasonic->readInInches());
    Serial.print("| cm: "); Serial.println(ultrasonic->readInCentimeters());
    
    delay(100);
}
