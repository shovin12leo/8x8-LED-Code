#include <LedControl.h>

// Create an instance of LedControl
// Parameters: DIN pin, CLK pin, CS pin, number of MAX7219 ICs
LedControl lc = LedControl(11, 13, 10, 1);

void setup() {
  // Initialize the matrix
  lc.shutdown(0, false);       // Wake up the MAX7219
  lc.setIntensity(0, 8);       // Set brightness (0-15)
  lc.clearDisplay(0);          // Clear the display

  // Display a smiley face
  lc.setRow(0, 0, 0b00111100); // Row 0
  lc.setRow(0, 1, 0b01000010); // Row 1
  lc.setRow(0, 2, 0b10100101); // Row 2 (eyes)
  lc.setRow(0, 3, 0b10000001); // Row 3
  lc.setRow(0, 4, 0b10100101); // Row 4
  lc.setRow(0, 5, 0b10011001); // Row 5 (mouth curve)
  lc.setRow(0, 6, 0b01000010); // Row 6
  lc.setRow(0, 7, 0b00111100); // Row 7
}

void loop() {
  // Nothing to do in loop
}
