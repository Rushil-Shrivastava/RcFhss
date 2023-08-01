#include ... "FHSS.h"

namespace FHSS {
  const uint8_t channels[] = {76, 80, 83, 100, 120}; // Example channels
  uint8_t currentChannelIndex = 0;

  void setup(RF24& radio) {
    radio.setChannel(channels[currentChannelIndex]); // Set initial channel
  }

  void sendData(RF24& radio, const void* data, uint8_t size) {
    radio.stopListening(); // Disable reception while transmitting
    radio.write(data, size);
    radio.startListening(); // Enable reception again
    currentChannelIndex = (currentChannelIndex + 1) % (sizeof(channels) / sizeof(channels[0]));
    radio.setChannel(channels[currentChannelIndex]);
  }

  void receiveData(RF24& radio, void* data, uint8_t size) {
    if (radio.available()) {
      radio.read(data, size);
    }
  }
}

