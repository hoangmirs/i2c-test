#include <Arduino.h>
#include <Wire.h>
#include "i2c_config.h"

void receiveEvent(int howMany);
void requestEvent();

void setup()
{
  Wire.begin(I2C_SLAVE_ADDR);   // Join I2C bus as slave with address 0x04
  Wire.onReceive(receiveEvent); // Register receive handler
  Wire.onRequest(requestEvent); // Register request handler
  Serial.begin(9600);           // Start serial for debugging
  delay(1000);                  // Wait for serial to initialize
  Serial.println("Uno I2C Slave started");
}

void loop()
{
  delay(100); // Nothing to do in loop for a slave
}

void receiveEvent(int howMany)
{
  while (Wire.available())
  {
    char c = Wire.read(); // Read incoming data
    Serial.print(c);      // Print it to Serial Monitor
  }
}

void requestEvent()
{
  Wire.write("Hello from Uno"); // Send response to master
}
