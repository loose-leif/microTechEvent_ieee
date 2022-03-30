 void setup() {
    DDRB = 0xFF;
    DDRD = 0xFF;
    PORTB = 0xFF;
    PORTD = 0xF8;
 }
 
 void loop() {
    
   delay(500);

   if(PORTB>0b11100000){

    PORTB = PORTB << 1;
    
   } else {
    
    PORTD = PORTD << 1;

    if(PORTD < 0b1111){

      PORTB = 0xFF;
      PORTD = 0xF8;
      
    }
    
   }
   
//   if(PORTB == 0b1110000){
//
//    PORTD = PORTD << 1;
//    
//   } else {
//
//    PORTB = PORTB << 1;
//    
//   }
//
//   if(PORTB == 0 && PORTD == 0){
//
//        PORTB = 0xFF;
//        PORTD = 0xFF;
//    
//   }
   
   
 }
