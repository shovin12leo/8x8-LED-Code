#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1); // Pin 11=DIN, Pin 13=CLK, Pin 10=CS

// Patterns for the "heart beating" effect
byte smallHeart[8] = {
  0b00000000,
  0b00011000,
  0b00111100,
  0b01111110,
  0b01111110,
  0b00111100,
  0b00011000,
  0b00000000
};

byte largeHeart[8] = {
  0b00000000,
  0b01100110,
  0b11111111,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000
};

void setup() {
  lc.shutdown(0, false);  // Wake up the LED matrix
  lc.setIntensity(0, 8);  // Set brightness level (0-15)
  lc.clearDisplay(0);     // Clear the display
}

void displayPattern(byte pattern[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, pattern[row]);
  }
}

void loop() {
  // Display the large heart
  displayPattern(largeHeart);
  delay(500); // Wait for 500ms

  // Display the small heart
  displayPattern(smallHeart);
  delay(500); // Wait for 500ms
}
