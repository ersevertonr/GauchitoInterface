#include <SonarHandler.h>
#include <Sonar.h>


Sonar *sonar = new Sonar(7);
void setup() {
  Serial.begin(9600);
}
 
void loop()
{
    Serial.print("raw: "); Serial.print(sonar->read());
    Serial.print("| in: "); Serial.print(sonar->readInInches());
    Serial.print("| cm: "); Serial.println(sonar->readInCentimeters());
    
    delay(100);
}
