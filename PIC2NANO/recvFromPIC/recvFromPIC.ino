// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

int letterCount = 0;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {

  letterCount++;

  if(letterCount>3){
      letterCount = 0;
      Serial.println(); // account for incoming packages to fit IEEE message...
  }
  
  char controlReg = Wire.read();    // receive byte as an integer
  //Serial.print(x);         // print the integer
  char Package = Wire.read();    // receive byte as an integer
  
  Serial.print(Package);         // print the integer


}
