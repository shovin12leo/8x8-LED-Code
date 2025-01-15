#include <LedControl.h>

const int DATA_IN = 11;  // Pin 11 connected to MAX7219's DIN (Data In)
const int CLK = 13;      // Pin 13 connected to MAX7219's CLK (Clock)
const int LOAD = 10;     // Pin 10 connected to MAX7219's LOAD (Chip Select)
const int MAX_DEVICES = 1;  // For a single 8x8 LED matrix

// Create LedControl object
LedControl lc = LedControl(DATA_IN, CLK, LOAD, MAX_DEVICES);

void setup() {
  // Initialize the MAX7219 matrix
  for (int i = 0; i < MAX_DEVICES; i++) {
    lc.shutdown(i, false);     // Wake up the device
    lc.setIntensity(i, 8);      // Set brightness level (0-15)
    lc.clearDisplay(i);         // Clear display on start
  }
}

void loop() {
  // Test 1: All rows at once
  testAllRows();
  delay(1000);  // Wait 1 second to visualize the test

  // Turn off all LEDs before starting next test
  clearDisplay();
  
  // Test 2: All columns at once
  testAllColumns();
  delay(1000);

  // Turn off all LEDs before starting next test
  clearDisplay();
  
  // Test 3: Light up each row sequentially
  testRowsSequentially();
  delay(1000);

  // Turn off all LEDs before starting next test
  clearDisplay();

  // Test 4: Light up each column sequentially
  testColumnsSequentially();
  delay(1000);

  // Turn off all LEDs before starting next test
  clearDisplay();

  // Test 5: Diagonal test (diagonal lines)
  testDiagonals();
  delay(1000);

  // Turn off all LEDs before restarting
  clearDisplay();
  delay(1000);  // Wait 1 second before repeating the tests
}

// Function to test all rows at once
void testAllRows() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, row, col, true); // Turn on LED at (row, col)
    }
  }
}

// Function to test all columns at once
void testAllColumns() {
  for (int col = 0; col < 8; col++) {
    for (int row = 0; row < 8; row++) {
      lc.setLed(0, row, col, true); // Turn on LED at (row, col)
    }
  }
}

// Function to light up each row sequentially
void testRowsSequentially() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, row, col, true); // Turn on LED at (row, col)
    }
    delay(200);  // Keep the current row on for 200ms
    clearDisplay(); // Turn off all LEDs before lighting up the next row
  }
}

// Function to light up each column sequentially
void testColumnsSequentially() {
  for (int col = 0; col < 8; col++) {
    for (int row = 0; row < 8; row++) {
      lc.setLed(0, row, col, true); // Turn on LED at (row, col)
    }
    delay(200);  // Keep the current column on for 200ms
    clearDisplay(); // Turn off all LEDs before lighting up the next column
  }
}

// Function to test diagonals (top-left to bottom-right and top-right to bottom-left)
void testDiagonals() {
  for (int i = 0; i < 8; i++) {
    lc.setLed(0, i, i, true); // Top-left to bottom-right diagonal
    lc.setLed(0, i, 7 - i, true); // Top-right to bottom-left diagonal
  }
  delay(1000);  // Keep the diagonals on for 1 second
}

// Function to clear the display (turn off all LEDs)
void clearDisplay() {
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, row, col, false); // Turn off all LEDs
    }
  }
}
