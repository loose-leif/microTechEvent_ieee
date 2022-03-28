//SPI SLAVE (ARDUINO)
//SPI COMMUNICATION BETWEEN TWO ARDUINO 
//CIRCUIT DIGEST
//Pramoth.T

#include<SPI.h>
#define buttonpin 2
volatile boolean received;
volatile byte support_recv;
int x;

void setup()

{
  Serial.begin(115200);
  pinMode(MISO,OUTPUT);                   //Sets MISO as OUTPUT (Have to Send data to Master IN 

  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  received = false;

  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
  
}

ISR (SPI_STC_vect)                        //Inerrrput routine function 
{
  support_recv = SPDR;         // Value received from master if store in variable slavereceived
  received = true;                        //Sets received as True 
}

void loop()
{ if(received)                            //Logic to SET LED ON OR OFF depending upon the value recerived from master
   {
      if (support_recv) 
      {
        analogWrite(6,support_recv);        //Sets pin 7 as HIGH LED ON
        Serial.println("play");
      }else
      {
        analogWrite(6,support_recv);          //Sets pin 7 as LOW LED OFF
        Serial.println("halt");
      }
                                  
  //SPDR = ;                          //Sends the x value to director via SPDR 
  delay(1000);
}
}
