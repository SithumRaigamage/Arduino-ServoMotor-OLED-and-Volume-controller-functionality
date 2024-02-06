#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
Servo myservo;  // create servo object to control a servo
int potPin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int count=52;
int trigPin = 10;
int echoPin = 11;

#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the variables for duration and distance
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Start serial communication
  Serial.begin(9600);
  
  myservo.attach(9);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  // attaches the servo on pin 9 to the servo object
  // put your setup code here, to run once:
  lcd.init();
  // turn on backlight
  lcd.backlight();
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  lcd.print("MSI GPU and CPU");
  
  lcd.setCursor(2,1);
  lcd.print("Temp Display");
}

void loop() {
  val = analogRead(potPin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);    // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                 // sets the servo position according to the scaled value
  delay(15);  
  // put your main code here, to run repeatedly:
  display.clearDisplay();
 //GPU
  display.setCursor(15,0);
  display.setTextSize(1);
  display.print("GPU");
  
  //CPU
  display.setCursor(80,0);
  display.setTextSize(1);
  display.print("CPU");
  
  //GPU Value
  display.setTextSize(3);
  display.setCursor(5,9);
  display.print(val);
  
  //celsuis for GPU
  display.setTextSize(3);
  display.setCursor(40,9);
  display.print("C");
  
  //CPU Value
   display.setTextSize(3);
  display.setCursor(70,9);
  display.print(count);
  
  //Celsuis value for CPU
  display.setTextSize(3);
  display.setCursor(105,9);
  display.print("C");
  
  
  display.display();
  delay(1000);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigger pin high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distance = duration * 0.034 / 2;
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Wait for 500 milliseconds before measuring again
  delay(500);
}
