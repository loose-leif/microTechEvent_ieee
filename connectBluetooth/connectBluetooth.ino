/*   

HC05 - Bluetooth AT-Command mode  
https://electropeak.com/learn/ 

*/ 

#include <SoftwareSerial.h> 
//#include <String.h>

SoftwareSerial BTserial(6, 7); // RX | TX 

// Software serial allows for other ( apart from RX | TX pins 0 and 1 )
// This is done by bit banging through software instead of dedicated hardware

int flag = 0; 
int LED = 13;
bool state = 1;

void setup() 
{   
 Serial.begin(9600); 
 BTserial.begin(9600); 
 pinMode(LED, OUTPUT); 
 digitalWrite(LED,state);
 Serial.println("Ready to connect\n"); 
} 

void loop() 
{ 
    if (BTserial.available())
    {  

        char x = BTserial.read();
        
        Serial.write(x);
        if(x=='1'){
          
          state = !state;
          digitalWrite(LED,state);  
            
        }
        
    }
 
    // Keep reading from Arduino Serial Monitor and send to HC-06
    if (Serial.available())
    {
        BTserial.write(Serial.read());
    }
}  
