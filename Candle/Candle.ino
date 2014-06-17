//#include <SoftwareSerial.h>

//SoftwareSerial serial(0, 1);

void setup()
{
//  serial.begin(9600);
  pinMode(0, OUTPUT);
}

void loop()
{
  long val, minval = 1023, maxval = 0;
  
  for (int i = 0; i < 10; i++) {
    val = analogRead(3);
    if (val > maxval) maxval = val;
    if (val < minval) minval = val;
  }
  
  analogWrite(0, 255 - constrain(map(maxval - minval, 100, 1023, 0, 255), 0, 255));

//  serial.print(maxval - minval); serial.print("\t");
//  serial.print(minval); serial.print("\t");
//  serial.print(maxval); serial.print("\t");
//  serial.println();
}
