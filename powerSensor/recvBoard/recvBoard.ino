#include <Wire.h>

void setup() {
  // put your setup code here, to run once:

  Wire.begin(1);
  Serial.begin(9600);

}

void loop(){

  Wire.onReceive(recvEvent);
  
}

void recvEvent(int num){

  while(1<Wire.available())
  {

    char x = Wire.read();
    Serial.print(x);
    
  }

  int y = Wire.read();
  Serial.println(y);
  
}
