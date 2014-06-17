#include <SoftwareSerial.h>

const int NUM = 100;
SoftwareSerial serial(0, 1);
int samples[NUM];

void setup()
{
  serial.begin(9600);
}

void loop()
{
  for (int i = 0; i < NUM; i++) {
    samples[i] = analogRead(3);
  }
  
  long total = 0, minval = 1023, maxval = 0;
  
  for (int i = 0; i < NUM; i++) {
    total += samples[i];
    if (samples[i] > maxval) maxval = samples[i];
    if (samples[i] < minval) minval = samples[i];
  }
  
  long mean = total / NUM, variance = 0;
  for (int i = 0; i < NUM; i++) {
    variance += (samples[i] - mean) * (samples[i] - mean);
  }
  variance /= NUM;
  
//  for (int i = 0; i < NUM; i++) {
//    serial.print(samples[i]);
//    serial.print("\t");
//  }

  serial.print(maxval - minval); serial.print("\t");
  serial.print(minval); serial.print("\t");
  serial.print(maxval); serial.print("\t");
  serial.print(mean); serial.print("\t");
  serial.print(variance); serial.print("\t");  
  serial.println();
}
