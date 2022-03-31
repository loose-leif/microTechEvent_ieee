#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219_A;
Adafruit_INA219 ina219_B(0x41);


void setup(void) 
{
  Serial.begin(115200);
  while (!Serial) {
      // will pause Zero, Leonardo, etc until serial console opens
      delay(1);
  }

  uint32_t currentFrequency;
    
  Serial.println("Hello!");
  
  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).

  ina219_A.begin();
  ina219_B.begin();
  
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  //ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  ina219_A.setCalibration_16V_400mA();
  ina219_B.setCalibration_16V_400mA();

  Serial.println("Measuring voltage and current with INA219 ...");
}

void loop(void) 
{
  float shuntvoltage1 = 0;
  float busvoltage1 = 0;
  float current_mA1 = 0;
  float loadvoltage1 = 0;
  float power_mW1 = 0;

  float shuntvoltage2 = 0;
  float busvoltage2 = 0;
  float current_mA2 = 0;
  float loadvoltage2 = 0;
  float power_mW2 = 0;

  shuntvoltage1 = ina219_A.getShuntVoltage_mV();
  busvoltage1 = ina219_A.getBusVoltage_V();
  current_mA1 = ina219_A.getCurrent_mA();
  power_mW1 = ina219_A.getPower_mW();
  loadvoltage1 = busvoltage1 + (shuntvoltage1 / 1000);

  shuntvoltage2 = ina219_B.getShuntVoltage_mV();
  busvoltage2 = ina219_B.getBusVoltage_V();
  current_mA2 = ina219_B.getCurrent_mA();
  power_mW2 = ina219_B.getPower_mW();
  loadvoltage2 = busvoltage2 + (shuntvoltage2 / 1000);
  
  Serial.print("Bus Voltage A:   "); Serial.print(busvoltage1); Serial.println(" V");
  Serial.print("Shunt Voltage A: "); Serial.print(shuntvoltage1); Serial.println(" mV");
  Serial.print("Load Voltage A:  "); Serial.print(loadvoltage1); Serial.println(" V");
  Serial.print("Current A:       "); Serial.print(current_mA1); Serial.println(" mA");
  Serial.print("Power A:         "); Serial.print(power_mW1); Serial.println(" mW");
  Serial.println("");
  Serial.print("Bus Voltage B:   "); Serial.print(busvoltage2); Serial.println(" V");
  Serial.print("Shunt Voltage B: "); Serial.print(shuntvoltage2); Serial.println(" mV");
  Serial.print("Load Voltage B:  "); Serial.print(loadvoltage2); Serial.println(" V");
  Serial.print("Current B:       "); Serial.print(current_mA2); Serial.println(" mA");
  Serial.print("Power B:         "); Serial.print(power_mW2); Serial.println(" mW");
  Serial.println("");
  Serial.println("- - - - - - - -");
  
  delay(2000);
}
