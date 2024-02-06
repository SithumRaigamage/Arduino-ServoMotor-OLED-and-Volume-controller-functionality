#include <Wire.h>               // Include the Wire library for I2C communication
#include <Adafruit_GFX.h>       // Include the Adafruit Graphics Library
#include <Adafruit_SSD1306.h>   // Include the Adafruit SSD1306 OLED driver library
#include <Servo.h>              // Include the Servo library

#define SCREEN_WIDTH 128        // OLED display width, in pixels
#define SCREEN_HEIGHT 64        // OLED display height, in pixels

#define OLED_RESET -1           // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define POTENTIOMETER_PIN A0    // Analog pin connected to the potentiometer
#define SERVO_PIN 9             // Pin connected to the servo motor

Servo servoMotor;               // Create a servo object

void setup() {
  // Initialize the servo motor
  servoMotor.attach(SERVO_PIN);

  // Initialize the OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear the buffer
  display.clearDisplay();

  // Set text size, color, and print the initial message
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Volume Control");
  display.display();
}

void loop() {
  // Read the analog value from the potentiometer
  int sensorValue = analogRead(POTENTIOMETER_PIN);

  // Map the potentiometer value (0-1023) to the servo motor angle (0-180)
  int servoAngle = map(sensorValue, 0, 1023, 0, 180);

  // Move the servo motor to the mapped angle
  servoMotor.write(servoAngle);

  // Clear the previous content on the display
  display.clearDisplay();

  // Print the current sensor value and servo angle on the OLED display
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Sensor Value: ");
  display.println(sensorValue);
  display.print("Servo Angle: ");
  display.println(servoAngle);
  display.display();

  // Delay for stability
  delay(100);
}
