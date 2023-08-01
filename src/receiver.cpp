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

  radio.openReadingPipe(1, 0xF0F0F0F0E1LL); // Set the same unique address as the transmitter
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char dataReceived[32] = "";
    FHSS::receiveData(radio, dataReceived, 32);
    radio.read(&dataReceived, sizeof(dataReceived));

    // Decrypt received data using Rolling Code and Streaming Cipher
    uint32_t rollingCode = RollingCodeGenerator::getCurrentCode();
    StreamingCipher::decryptData(dataReceived, sizeof(dataReceived), rollingCode);

    Serial.println(dataReceived);
  }

  delay(1000); // Change frequency every 1 second (adjust as needed)
}

