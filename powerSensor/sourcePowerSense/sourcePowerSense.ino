#include <Wire.h>
#include <Adafruit_INA219.h>
#include <String.h>

Adafruit_INA219 ina219;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  uint32_t currentFrequency;

  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }

  ina219.setCalibration_16V_400mA();

  //Serial.println("Measuring voltage and current with INA219 ...");
  
}

byte x = 0;

void loop() {

  float shuntvoltage = 0;
  float busvoltage = 0;
  float current_mA = 0;
  float loadvoltage = 0;
  float power_mW = 0;

  String currentLabel = "";

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  current_mA = ina219.getCurrent_mA();
  power_mW = ina219.getPower_mW();
  loadvoltage = busvoltage + (shuntvoltage / 1000);
  
  Serial.print("Bus Voltage:   "); Serial.print(busvoltage); Serial.println(" V");
  Serial.print("Shunt Voltage: "); Serial.print(shuntvoltage); Serial.println(" mV");
  Serial.print("Load Voltage:  "); Serial.print(loadvoltage); Serial.println(" V");
  Serial.print("Current:       "); Serial.print(current_mA); Serial.println(" mA");
  Serial.print("Power:         "); Serial.print(power_mW); Serial.println(" mW");
  
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("Current:  ");        // sends five bytes
  Wire.write((int)current_mA); // sends one byte
  Wire.write(" mA");
  Wire.endTransmission();    // stop transmitting
  
  delay(500);
}
