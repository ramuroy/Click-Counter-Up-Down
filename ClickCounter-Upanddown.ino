// Pin definitions for buttons and 7-segment display
#define BUTTON_UP_PIN 2    // Pin for the "Up" button
#define BUTTON_DOWN_PIN 3  // Pin for the "Down" button
#define SEG_A 4            // Pin for segment A of 7-segment display
#define SEG_B 5            // Pin for segment B of 7-segment display
#define SEG_C 6            // Pin for segment C of 7-segment display
#define SEG_D 7            // Pin for segment D of 7-segment display
#define SEG_E 8            // Pin for segment E of 7-segment display
#define SEG_F 9            // Pin for segment F of 7-segment display
#define SEG_G 10           // Pin for segment G of 7-segment display

int count = 0;  // Initialize counter to 0

// Segment values for 7-segment display (0-9) defined with HIGH and LOW
const bool digit[10][7] = {
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW},  // 0
  {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW},      // 1
  {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH},   // 2
  {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH},   // 3
  {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH},    // 4
  {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH},   // 5
  {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH},  // 6
  {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW},     // 7
  {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // 8
  {HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH}   // 9
};

void setup() {
  // Set button pins as input with pull-up resistors
  pinMode(BUTTON_UP_PIN, INPUT_PULLUP);
  pinMode(BUTTON_DOWN_PIN, INPUT_PULLUP);

  // Set segment pins as output
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);

  // Initialize the 7-segment display
  displayNumber(count);
}

void loop() {
  // Read the button states
  if (digitalRead(BUTTON_UP_PIN) == LOW) {
    count++;
    if (count > 9) {
      count = 0;  // Reset to 0 after 9
    }
    displayNumber(count);
    delay(200);  // Debounce delay
  }

  if (digitalRead(BUTTON_DOWN_PIN) == LOW) {
    count--;
    if (count < 0) {
      count = 9;  // Reset to 9 after 0
    }
    displayNumber(count);
    delay(200);  // Debounce delay
  }
}

// Function to display a number (0-9) on the 7-segment display using HIGH/LOW
void displayNumber(int num) {
  const bool* segments = digit[num];  // Get the segment values for the number

  // Set the pins for the segments according to the values
  digitalWrite(SEG_A, segments[0]);
  digitalWrite(SEG_B, segments[1]);
  digitalWrite(SEG_C, segments[2]);
  digitalWrite(SEG_D, segments[3]);
  digitalWrite(SEG_E, segments[4]);
  digitalWrite(SEG_F, segments[5]);
  digitalWrite(SEG_G, segments[6]);
}