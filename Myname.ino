#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1); // Pin 11=DIN, Pin 13=CLK, Pin 10=CS

// Patterns for letters A-Z
byte letters[26][8] = {
  {0b01111111, 0b10000000, 0b10000000, 0b01111110, 0b00000001, 0b00000001, 0b10000001, 0b01111110}, // S
  {0b10000001, 0b10000001, 0b10000001, 0b11111111, 0b10000001, 0b10000001, 0b10000001, 0b10000001}, // H
  {0b00111100, 0b01000010, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b01000010, 0b00111100}, // O
  {0b10000001, 0b10000001, 0b01000010, 0b01000010, 0b00100100, 0b00100100, 0b00011000, 0b00011000}, // V
  {0b00111100, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00111100}, // I
  {0b10000001, 0b11000001, 0b10100001, 0b10010001, 0b10001001, 0b10000101, 0b10000011, 0b10000001}, // N

};

void setup() {
  lc.shutdown(0, false);  // Wake up LED matrix
  lc.setIntensity(0, 8);  // Set brightness level (0-15)
  lc.clearDisplay(0);     // Clear the display
}

void loop() {
  for (int letter = 0; letter < 7; letter++) {
    // Display the letter pattern
    for (int row = 0; row < 8; row++) {
      lc.setRow(0, row, letters[letter][row]);
    }
    delay(1000); // Wait for 1 second before showing the next letter
  }
}
