#include <SoftwareSerial.h>

SoftwareSerial serial(0, 1); // RX, TX
int sensorPin = 3;    // select the input pin for the potentiometer
int ledPin = 4;      // select the pin for the LED
int val1, val2, val3;

void setup() {
  pinMode(ledPin, OUTPUT);
//  pinMode(sensorPin, INPUT_PULLUP);
  serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  val1 = analogRead(sensorPin);
  digitalWrite(ledPin, LOW);
  delay(5); // delay(1) is about 500, delay(2) about 750, delay(3) gives about 900, delay(4) gives 1000, delay(5) gives 1018, delay(500) gives 1022.
  val2 = analogRead(sensorPin);
  delay(500);
  val3 = analogRead(sensorPin);
  serial.print(val1);
  serial.print("\t");
  serial.print(val2);
  serial.print("\t");
  serial.print(val3);
  serial.println();
  delay(1000);
}
