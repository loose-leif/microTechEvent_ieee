/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  The circuit:
  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
  - LED
    anode (long leg) attached to digital output 13 through 220 ohm resistor
    cathode (short leg) attached to ground

  - Note: because most Arduinos have a built-in LED attached to pin 13 on the
    board, the LED is optional.

  created by David Cuartielles
  modified 30 Aug 2011
  By Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/AnalogInput
*/

#include <PWM.h>
#include <SPI.h>

int sensorPin = A7;    // select the input pin for the potentiometer
int analogOutPin = 6;

int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int outputValue = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  //InitTimersSafe();

  //SetPinFrequencySafe(analogOutPin, 1000);

  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on

  outputValue = map(sensorValue, 0, 1023, 0, 255);

  if(outputValue < 50 || outputValue > 200){

    analogWrite(analogOutPin, 125-outputValue);
  
  } else {

    analogWrite(analogOutPin, 0);
    
  }
  

  Serial.println(outputValue);
}
