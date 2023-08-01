#ifndef FHSS_H
#define FHSS_H

#include <RF24.h>

namespace FHSS {
  extern const uint8_t channels[]; // Array of available channels
  extern uint8_t currentChannelIndex; // Index of the current channel

  void setup(RF24& radio);
  void sendData(RF24& radio, const void* data, uint8_t size);
  void receiveData(RF24& radio, void* data, uint8_t size);
}

#endif // FHSS_H

