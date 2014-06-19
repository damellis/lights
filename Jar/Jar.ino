//#include <SoftwareSerial.h>

//SoftwareSerial serial(0, 1);

boolean lightOn = true;

void setup()
{
//  serial.begin(9600);
  pinMode(1, OUTPUT);
  digitalWrite(1, HIGH);
}

void loop()
{
  long val, minval = 1023, maxval = 0;
  
  for (int i = 0; i < 20; i++) {
    val = analogRead(3);
    if (val > maxval) maxval = val;
    if (val < minval) minval = val;
  }
  
  //analogWrite(0, 255 - constrain(map(maxval - minval, 100, 1023, 0, 255), 0, 255));
  
  if (maxval - minval > 100) {
    if (lightOn == true) {
      digitalWrite(1, LOW);
      lightOn = false;
    } else {
      digitalWrite(1, HIGH);
      lightOn = true;
    }
    
    delay(1000); // wait a second so as not to immediately toggle the light again
  }

//  serial.print(maxval - minval); serial.print("\t");
//  serial.print(minval); serial.print("\t");
//  serial.print(maxval); serial.print("\t");
//  serial.println();
}
