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
  Serial.print("roll(x):");
  Serial.println(getAngleX());
  Serial.print("pitch(y):");
  Serial.println(getAngleY());
  Serial.print("yaw(z):");
  Serial.println(getAngleZ());
  delay(100);
}