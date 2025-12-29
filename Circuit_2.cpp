#include <Adafruit_LiquidCrystal.h>
#include <Servo.h> // servo library

Servo s1;
int soilSensor = A0;
int soilValue = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup() {
  pinMode(soilSensor, INPUT);
  Serial.begin(9600);
  lcd_1.begin(16, 2);

  s1.attach(5);          // Servo connected to digital pin 5
  s1.write(90);          // Start servo in neutral position
}

void loop() {
  soilValue = analogRead(soilSensor);
  Serial.print("Soil Value: ");
  Serial.println(soilValue);

  lcd_1.setCursor(0, 0);
  lcd_1.print("Smart Dustbin   ");

  lcd_1.setCursor(0, 1);

  if (soilValue >= 300) {
    lcd_1.print("Wet Waste Detected ");
    Serial.println("Wet Waste Detected");
    s1.write(30);       // Move servo for wet waste
    delay(2000);
    s1.write(90);       // Return to neutral
  } 
  else {
    lcd_1.print("Dry Waste Detected ");
    Serial.println("Dry Waste Detected");
    s1.write(150);      // Move servo for dry waste
    delay(2000);
    s1.write(90);       // Return to neutral
  }

  delay(500);
}
