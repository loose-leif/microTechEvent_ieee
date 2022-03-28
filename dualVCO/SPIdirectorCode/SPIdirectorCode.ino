#include<SPI.h>                             //Library for SPI            

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
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}

void loop(void)
{
  byte Mastersend,Mastereceive;          

  sensorValue = analogRead(sensorPin);
  // turn the ledPin on

  outputValue = map(sensorValue, 0, 1023, 0, 255);

  if(outputValue < 50 || outputValue > 200){

    x = outputValue;
  
  } else {

    x = 0;
    
  }
  
  digitalWrite(SS, LOW);                  //Starts communication with Slave connected to master
  
  Mastersend = x;                            
  Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
  
  delay(1000);
  
}
