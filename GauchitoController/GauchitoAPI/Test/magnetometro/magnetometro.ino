#include <Magnetometro.h>
#include <Direction.h>
#include <Wire.h>

Magnetometro *mag = new Magnetometro();
void printCoordinates(Magnetometro::MagData *data);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  Magnetometro::MagData *raw = mag->readRaw();
  Serial.print("Raw values [x, y, z] = ");
  printCoordinates(raw);
  free(raw);
  
  Magnetometro::MagData *scaled = mag->readScaled();
  Serial.print("Scaled values: [x, y, z] = ");
  printCoordinates(scaled);
  free(scaled);
  
  Serial.print("Direction = ");
  Serial.println(mag->getDirection());
  
  Serial.print("Declination Angle = ");
  Serial.println(mag->getDeclinationAngle());
  
}

void printCoordinates(Magnetometro::MagData *data) {
  Serial.print(data->getX()); Serial.print(", ");
  Serial.print(data->getY()); Serial.print(", ");
  Serial.println(data->getZ());
}
