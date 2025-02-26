#include <Arduino.h>
#include <Wire.h>
#include "i2c_config.h"

#define I2C_SDA 13 // SDA Connected to GPIO 13
#define I2C_SCL 12 // SCL Connected to GPIO 12

void setup()
{
  Wire.begin(I2C_SDA, I2C_SCL);          // Join I2C bus as master

  Serial.begin(115200); // Start serial for debugging
  delay(1000);          // Wait for serial to initialize
  Serial.println("ESP32 I2C Master started");
}

void loop()
{
  // Send data to slave
  Wire.beginTransmission(I2C_SLAVE_ADDR);
  const char *message = "Hi Uno";
  Wire.write((uint8_t *)message, strlen(message));
  Wire.endTransmission();

  // Request data from slave
  Wire.requestFrom(I2C_SLAVE_ADDR, 14); // Request 13 bytes ("Hello from Uno")
  while (Wire.available())
  {
    char c = Wire.read();
    Serial.print(c);
  }
  Serial.println();

  delay(1000); // Wait 1 second between transmissions
}
