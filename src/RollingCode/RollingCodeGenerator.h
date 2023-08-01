#ifndef RollingCodeGenerator_h
#define RollingCodeGenerator_h

#include <Arduino.h>

namespace RollingCodeGenerator {
  void setup();
  uint32_t generate();
  uint32_t getCurrentCode();
}

#endif

