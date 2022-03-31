void setup(void){

  pinMode(6, OUTPUT);
  pinMode(12,INPUT);
  
}

void loop(void){

  if(digitalRead(12) == LOW){

    digitalWrite(6, HIGH);
    
  } else {

    digitalWrite(6, LOW);
    
  }
  
}
