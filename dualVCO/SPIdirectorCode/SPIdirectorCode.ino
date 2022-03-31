#include<SPI.h>         

int sensorPin = A7;    // select the input pin for the potentiometer
int analogOutPin = 6;

int sensorValue = 0;  // variable to store the value coming from the sensor
int outputValue = 0; 

int x;

int LED = 4;
void setup (void)

{
  Serial.begin(115200);                   //Starts Serial Communication at Baud Rate 115200 
  
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So director doesnt connnect with supports)
}

void loop(void)
{
  byte directorSend,directorRecv;          

  sensorValue = analogRead(sensorPin);

  outputValue = map(sensorValue, 0, 1023, 0, 255);

  // outputValue is now re-mapped so that it is both
  // character wise and able to be transmitted
  // within a single frame of SPI data.

  if(outputValue < 50 || outputValue > 200){

    x = outputValue; // will send the value to send if outside idle bounds
  
  } else {

    x = 0;
    
  }
  
  digitalWrite(SS, LOW);  // starts communication with Slave connected to master
  
  directorSend = x;                            
  directorRecv=SPI.transfer(directorSend); // send the directorSend value to support also receives value from support
  
  delay(1000);
  
}
