Arduino Servo Motor Control with OLED Display

This Arduino project allows you to control a servo motor using an analog volume controller (potentiometer) and display the sensor data on an OLED display.

Components Used

Arduino board
Servo motor
Potentiometer (analog volume controller)
OLED display (SSD1306)

Dependencies
Wire library
Adafruit GFX library
Adafruit SSD1306 library
Servo library
Make sure you have these libraries installed in your Arduino IDE before uploading the code.

Wiring Instructions
Connect the potentiometer to analog pin A0 on the Arduino board.
Connect the servo motor to pin 9 on the Arduino board.
Connect the OLED display using the I2C interface (SDA and SCL pins).
Installation and Usage
Clone or download this repository to your local machine.
Open the Arduino IDE and upload the provided sketch (servo_oled_control.ino) to your Arduino board.
Ensure all the necessary libraries are installed in your Arduino IDE.
Power up your Arduino board.
Turn the potentiometer to control the servo motor position.
The OLED display will show the current sensor value and servo angle.
