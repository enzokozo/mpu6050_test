#include <Arduino.h>
#include "mpu6050.h"

void setup() 
{
  Serial.begin(9600);

  mpu_begin();

  Serial.println("Calibrando, deixa parado!");
  delay(1000);
  mpu_calibrate(200);
  Serial.println("Calibrado!");

  mpu_reset();
}


void loop()
{
  mpu_loop();
  Serial.print("Ang X:");
  Serial.print(getAngleX());
  Serial.print(" | Ang Y:");
  Serial.print(getAngleY());
  Serial.print(" | Ang Z:");
  Serial.print(getAngleZ());
  
  delay(100);
}