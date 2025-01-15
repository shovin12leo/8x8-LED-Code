#include <LedControl.h>

const int DATA_IN = 11;  // Pin 11 connected to MAX7219's DIN (Data In)
const int CLK = 13;      // Pin 13 connected to MAX7219's CLK (Clock)
const int LOAD = 10;     // Pin 10 connected to MAX7219's LOAD (Chip Select)
const int MAX_DEVICES = 1;  // For a single 8x8 LED matrix

// Create LedControl object
LedControl lc = LedControl(DATA_IN, CLK, LOAD, MAX_DEVICES);

// Define arrow patterns (Up, Down, Left, Right)
byte arrowUp[8] = {
  B00011000, // Row 0
  B00111100, // Row 1
  B01111110, // Row 2
  B11111111, // Row 3
  B00011000, // Row 4
  B00011000, // Row 5
  B00011000, // Row 6
  B00000000  // Row 7
};

byte arrowDown[8] = {
  B00011000, // Row 0
  B00011000, // Row 1
  B00011000, // Row 2
  B11111111, // Row 3
  B01111110, // Row 4
  B00111100, // Row 5
  B00011000, // Row 6
  B00000000  // Row 7
};

byte arrowLeft[8] = {
  B00011000, // Row 0
  B00111000, // Row 1
  B01111000, // Row 2
  B11111000, // Row 3
  B01111000, // Row 4
  B00111000, // Row 5
  B00011000, // Row 6
  B00000000  // Row 7
};

byte arrowRight[8] = {
  B00011000, // Row 0
  B00011100, // Row 1
  B00011110, // Row 2
  B00011110, // Row 3
  B00011110, // Row 4
  B00011100, // Row 5
  B00011100, // Row 6
  B000110000  // Row 7
};

void setup() {
  // Initialize the MAX7219 matrix
  for (int i = 0; i < MAX_DEVICES; i++) {
    lc.shutdown(i, false);     // Wake up the device
    lc.setIntensity(i, 8);      // Set brightness level (0-15)
    lc.clearDisplay(i);         // Clear display on start
  }
}

void loop() {
  // Display Up arrow
  displayArrow(arrowUp);
  delay(2000);  // Show Up arrow for 2 seconds

  // Clear display before showing next arrow
  clearDisplay();

  // Display Down arrow
  displayArrow(arrowDown);
  delay(2000);  // Show Down arrow for 2 seconds

  // Clear display before showing next arrow
  clearDisplay();

  // Display Left arrow
  displayArrow(arrowLeft);
  delay(2000);  // Show Left arrow for 2 seconds

  // Clear display before showing next arrow
  clearDisplay();

  // Display Right arrow
  displayArrow(arrowRight);
  delay(2000);  // Show Right arrow for 2 seconds

  // Clear display before starting the loop again
  clearDisplay();
}

// Function to display an arrow pattern on the LED matrix
void displayArrow(byte arrow[8]) {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, arrow[row]); // Set each row of the arrow pattern
  }
}

// Function to clear the display (turn off all LEDs)
void clearDisplay() {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, 0); // Turn off all LEDs
  }
}
