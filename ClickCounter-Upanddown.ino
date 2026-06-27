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

// Debounced, edge-detected push button (active-low with internal pull-up).
struct Button {
  uint8_t pin;
  int stable;             // last debounced state
  int lastReading;        // last raw reading
  unsigned long lastChange;
};

const unsigned long DEBOUNCE_MS = 50;

Button btnUp   = {BUTTON_UP_PIN, HIGH, HIGH, 0};
Button btnDown = {BUTTON_DOWN_PIN, HIGH, HIGH, 0};

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

// Returns true once, on the press edge (active-low), with debouncing.
bool justPressed(Button &b) {
  int reading = digitalRead(b.pin);
  if (reading != b.lastReading) {       // input changed: restart debounce timer
    b.lastChange = millis();
    b.lastReading = reading;
  }
  if ((millis() - b.lastChange) > DEBOUNCE_MS && reading != b.stable) {
    b.stable = reading;                 // accept the new stable state
    if (b.stable == LOW) return true;   // a fresh press
  }
  return false;
}

void loop() {
  // Count once per press (edge-detected) instead of repeating while held.
  if (justPressed(btnUp)) {
    count++;
    if (count > 9) count = 0;           // wrap 9 -> 0
    displayNumber(count);
  }

  if (justPressed(btnDown)) {
    count--;
    if (count < 0) count = 9;           // wrap 0 -> 9
    displayNumber(count);
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