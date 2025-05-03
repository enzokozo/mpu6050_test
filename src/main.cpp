#include <Arduino.h>      // Includes the Arduino core library
#include <Wire.h>          // Includes the Wire library for I2C communication
#include "MPU6050_tockn.h" // Includes the MPU6050 library

MPU6050 mpu6050(Wire);    // Creates an MPU6050 object to communicate via I2C

void setup() {
  Serial.begin(9600);    // Starts the serial communication at 9600 baud rate
  Wire.begin();          // Initializes the I2C bus
  mpu6050.begin();       // Initializes the MPU6050 sensor
  mpu6050.calcGyroOffsets(true);  // Calibrates the gyroscope with the sensor stationary
}

void loop() {
  mpu6050.update();      // Updates sensor readings

  // Accelerometer readings (in g)
  Serial.print("Acc [g]  => ");
  Serial.print("X: "); Serial.print(mpu6050.getAccX(), 2);  // Prints X-axis acceleration
  Serial.print(" | Y: "); Serial.print(mpu6050.getAccY(), 2);  // Prints Y-axis acceleration
  Serial.print(" | Z: "); Serial.print(mpu6050.getAccZ(), 2);  // Prints Z-axis acceleration

  // Gyroscope readings (in °/s)
  Serial.print("   ||  Gyro [°/s] => ");
  Serial.print("X: "); Serial.print(mpu6050.getGyroX(), 2);   // Prints X-axis gyroscope value
  Serial.print(" | Y: "); Serial.print(mpu6050.getGyroY(), 2);   // Prints Y-axis gyroscope value
  Serial.print(" | Z: "); Serial.print(mpu6050.getGyroZ(), 2);   // Prints Z-axis gyroscope value

  // Angle readings (in °)
  Serial.print("   ||  Angles [°] => ");
  Serial.print("X: "); Serial.print(mpu6050.getAngleX(), 2);    // Prints X-axis angle
  Serial.print(" | Y: "); Serial.print(mpu6050.getAngleY(), 2);    // Prints Y-axis angle
  Serial.print(" | Z: "); Serial.print(mpu6050.getAngleZ(), 2);    // Prints Z-axis angle

  // Temperature reading
  Serial.print("   ||  Temp [°C]: ");
  Serial.println(mpu6050.getTemp(), 2);  // Prints the temperature in Celsius

  delay(500);  // Waits for 500 milliseconds before the next loop iteration
}
