// Board: ESP32-C6
// Analog Input Pin

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANALOG_IN_PIN A1

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int input_vol;             // Raw input in millivolts
float filtered_vol = 0;    // Filtered value as a float for precision
const float alpha = 0.1;   // Smoothing factor (0 < alpha ≤ 1)

// Define angle and RPM data
const int angleValues[] = { 20, 40, 60, 80}; // Angles in degrees
const int rpmValues[] = {2050, 2300, 2500, 2700}; // RPM values
const int numDataPoints = sizeof(angleValues) / sizeof(angleValues[0]);

// The setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600); // Baudrate is irrelevant (any number works)

  // Set A/D converter resolution to 12 bits
  analogReadResolution(12);

    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();

  // Draw a single pixel in white
  display.drawPixel(10, 10, SSD1306_WHITE);

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  delay(2000);
  // display.display() is NOT necessary after every single drawing command,


}

// The loop function runs over and over again forever
void loop() {
  // Read input value in millivolts
  input_vol = analogReadMilliVolts(ANALOG_IN_PIN);

  // Apply EMA filter
  filtered_vol = alpha * input_vol + (1 - alpha) * filtered_vol;

  // Round the filtered value to the nearest integer for output
  int rounded_filtered_vol = (int)(filtered_vol + 0.5);
  float inputAngle = map(rounded_filtered_vol, 0, 3300, 0, 270);
  
  // Find corresponding RPM using linear interpolation
  int rpm = getRPM(inputAngle);




  // Print the raw and filtered values to Serial Monitor
  Serial.print("Raw mV: ");
  Serial.print(input_vol);

  Serial.print("\tFiltered mV: ");
  Serial.print(rounded_filtered_vol);
  
  Serial.print("\tAngle: ");
  Serial.println(inputAngle);
  oledDisplay(rpm);

  delay(10); // Delay for stability
}

void oledDisplay(int _rpm) {
  display.clearDisplay();
  display.setTextSize(2);                  // 2X pixel scale
  display.setTextColor(SSD1306_WHITE);     // Draw white text
  display.setCursor(0,0);                  // Start at top-left corner
  display.print(_rpm);
  display.print(" RPM");
  display.display();
}


// Function to get RPM based on angle using linear interpolation
int getRPM(float angle) {
  for (int i = 0; i < numDataPoints - 1; i++) {
    if (angle >= angleValues[i] && angle <= angleValues[i + 1]) {
      // Interpolate between the two points
      int rpm = map(angle * 100, angleValues[i] * 100, angleValues[i + 1] * 100, rpmValues[i], rpmValues[i + 1]);
      return rpm;
    }
  }
  // If angle is out of range, return the closest boundary RPM
  if (angle < angleValues[0]) return rpmValues[0];
  if (angle > angleValues[numDataPoints - 1]) return rpmValues[numDataPoints - 1];
  return 0; // Default return in case of error
}