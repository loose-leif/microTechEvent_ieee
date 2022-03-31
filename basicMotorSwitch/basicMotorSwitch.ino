void setup(void){

  pinMode(6, OUTPUT); // gate control for MOSFET
  pinMode(12,INPUT); // input with physical pullUp and button
  
}

void loop(void){

  if(digitalRead(12) == LOW){

    digitalWrite(6, HIGH);
    
  } else {

    digitalWrite(6, LOW);
    
  }
  
}
