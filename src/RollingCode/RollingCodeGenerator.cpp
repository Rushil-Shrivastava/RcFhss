#include "RollingCodeGenerator.h"

namespace RollingCodeGenerator {
  uint32_t rollingCode = 0;

  void setup() {
    // Implement any necessary initialization here
  }

  uint32_t generate() {
    // Implement the logic to generate a new rolling code here
    // For simplicity, we'll use a basic example
    rollingCode = millis();
    return rollingCode;
  }
  
  uint32_t getCurrentCode() {
    // Return the current rolling code without generating a new one.
    return rollingCode;
  }
}

