#ifndef STREAMING_CIPHER_H
#define STREAMING_CIPHER_H

#include <cstdint>
#include <Arduino.h>

namespace StreamingCipher {
  void setup();
  void encryptData(void* data, uint8_t size, uint32_t rollingCode);
  void decryptData(void* data, uint8_t size, uint32_t rollingCode);
}

#endif // STREAMING_CIPHER_H
