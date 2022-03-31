#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from director
// this function is registered as an event, see setup()

void receiveEvent(int howMany) {
  
  while (4 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.print(x);         // print the integer
  char y = Wire.read();    // receive byte as an char
  Serial.print(y);         // print the char
  y = Wire.read();        // receive byte as an char
  Serial.print(y);         // print the char
  y = Wire.read();        // receive byte as an char
  Serial.println(y);         // print the char
}
