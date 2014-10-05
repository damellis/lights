int sensor = 3; // analog input channel (not pin number) of the light sensor
int ledPin = 1;
int val;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // turn off the led so we can measure the light in the room without it
  digitalWrite(ledPin, LOW);
  
  // need to delay a bit to let the light sensor settle
  delay(10);
  
  // now, measure the light level in the room without the light from the led
  val = analogRead(sensor);
  
  // if it's dark in the room, turn on the led
  if (val > 990) {
    analogWrite(ledPin, 128);
    delay(10000);
  }
}
