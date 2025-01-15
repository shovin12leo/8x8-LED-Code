#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1); // Pin 11=DIN, Pin 13=CLK, Pin 10=CS

// Patterns for letters S-H-O-V-I-N
byte letters[6][8] = {
  {0b01111111, 0b10000000, 0b10000000, 0b01111110, 0b00000001, 0b00000001, 0b10000001, 0b01111110}, // S
  {0b10000001, 0b10000001, 0b10000001, 0b11111111, 0b10000001, 0b10000001, 0b10000001, 0b10000001}, // H
  {0b00111100, 0b01000010, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b01000010, 0b00111100}, // O
  {0b10000001, 0b10000001, 0b01000010, 0b01000010, 0b00100100, 0b00100100, 0b00011000, 0b00011000}, // V
  {0b00111100, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00111100}, // I
  {0b10000001, 0b11000001, 0b10100001, 0b10010001, 0b10001001, 0b10000101, 0b10000011, 0b10000001}  // N
};

// Helper function to create a scrolling pattern
void createScrollingPattern(byte scrollingPattern[48][8]) {
  for (int i = 0; i < 6; i++) { // For each letter
    for (int row = 0; row < 8; row++) {
      for (int col = 0; col < 8; col++) {
        scrollingPattern[i * 8 + col][row] = (letters[i][row] >> col); // Shift right for scrolling effect
      }
    }
  }
}

void displayScrollingPattern(byte scrollingPattern[48][8], int totalFrames, int delayTime) {
  for (int frame = 0; frame < totalFrames; frame++) { // Normal left-to-right scrolling
    for (int row = 0; row < 8; row++) {
      lc.setRow(0, row, scrollingPattern[frame][row]);
    }
    delay(delayTime); // Constant delay for smooth slow scrolling
  }
}

void setup() {
  lc.shutdown(0, false);  // Wake up LED matrix
  lc.setIntensity(0, 8);  // Set brightness level (0-15)
  lc.clearDisplay(0);     // Clear the display
}

void loop() {
  // Create a scrolling pattern array
  byte scrollingPattern[48][8] = {0};
  createScrollingPattern(scrollingPattern);

  // Display the scrolling name with 48 frames (6 letters * 8 columns per letter)
  displayScrollingPattern(scrollingPattern, 48, 150); // 150ms delay for slow constant speed

  delay(1000); // Pause before restarting the animation
}
