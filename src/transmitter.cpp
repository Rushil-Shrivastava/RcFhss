#include <SPI.h>
#include <RF24.h>
#include "FHSS/FHSS.h"
#include "RollingCode/RollingCodeGenerator.h"
#include "StreamingCipher/StreamingCipher.h"

RF24 radio(9, 10); // CE, CSN

void setup() {
  Serial.begin(9600);
  radio.begin();
  
  // Initialize FHSS, Rolling Code Generator, and Streaming Cipher
  FHSS::setup(radio);
  RollingCodeGenerator::setup();
  StreamingCipher::setup();
}

void loop() {
  // Generate Rolling Code and apply Streaming Cipher to the data
  uint32_t rollingCode = RollingCodeGenerator::generate();
  char dataToSend[] = "Hello from Arduino 1!";
  StreamingCipher::encryptData(dataToSend, sizeof(dataToSend), rollingCode);

  // Send encrypted data using FHSS
  FHSS::sendData(radio, dataToSend, sizeof(dataToSend));
  delay(1000); // Change frequency every 1 second (adjust as needed)
}
