#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1);

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  // Laugh
  byte pattern[8] = {
    0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10111101,
    0b10011001,
    0b01000010,
    0b00111100
  };

  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, pattern[row]);
  }
}

void loop() {}
