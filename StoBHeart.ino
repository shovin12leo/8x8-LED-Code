#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1); // Pin 11=DIN, Pin 13=CLK, Pin 10=CS

// Heart patterns for small-to-big effect
byte heart1[8] = {
  0b00000000,
  0b00000000,
  0b00011000,
  0b00111100,
  0b00111100,
  0b00011000,
  0b00000000,
  0b00000000
};

byte heart2[8] = {
  0b00000000,
  0b00011000,
  0b00111100,
  0b01111110,
  0b01111110,
  0b00111100,
  0b00011000,
  0b00000000
};

byte heart3[8] = {
  0b00000000,
  0b00100100,
  0b01111110,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000
};

byte heart4[8] = {
  0b01100110,
  0b11111111,
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
  // Display small-to-big heart effect
  displayPattern(heart1);
  delay(300); // Wait for 300ms

  displayPattern(heart2);
  delay(300);

  displayPattern(heart3);
  delay(300);

  displayPattern(heart4);
  delay(500); // Keep the largest heart for a bit longer

  // Clear display for smooth loop restart
  lc.clearDisplay(0);
  delay(500);
}
