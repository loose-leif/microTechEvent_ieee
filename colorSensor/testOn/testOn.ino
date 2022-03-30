#include <Wire.h>

void setup() {
  // put your setup code here, to run once:

  Wire.begin();
  Serial.begin(9600);

}

byte addr = 0x29;

byte readL;
byte readH;

void loop() {
  // put your main code here, to run repeatedly:

  Wire.beginTransmission(addr);
  Wire.write(byte(0x00));
  Wire.write(byte(0x0B));
  Wire.endTransmission();

  // Wire.beginTransmission(addr);

  // Wire.write(byte(0x01));
  // Wire.write(byte(0xF6));

  // Wire.endTransmission();

  delay(10);

  Wire.beginTransmission(addr);

  Wire.write(byte(0x16));

  Wire.requestFrom(addr, 1);

  if(Wire.available() >= 1){

    readL = Wire.read();

  }

  Wire.endTransmission();

  Wire.beginTransmission(addr);

  Wire.write(byte(0x17));

  Wire.endTransmission();

  Wire.requestFrom(addr, 1);

  if(Wire.available() >= 1){

     readH = Wire.read();

  }

  Serial.print("0x");
  Serial.print(readH, HEX);
  Serial.println(readL, HEX);
  
  delay(1000);

}
