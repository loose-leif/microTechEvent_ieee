/*
 * File:   AND08479_main.c
 * Author: leif
 * Created on March 18, 2021, 1:54 AM
 */

// make LCD go crazy

#include "AND08479_asmLib.h"
#include "xc.h"
    
#include "AND08479_LCD.h"
#include "AND08479_delay.h"

#pragma config ICS = PGx1          // Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config FWDTEN = OFF        // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config GWRP = OFF          // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF           // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = OFF        // JTAG Port Enable (JTAG port is disabled)

// CW2: FLASH CONFIGURATION WORD 2 (see PIC24 Family Reference Manual 24.1)
#pragma config I2C1SEL = PRI       // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = OFF       // IOLOCK Protection (IOLOCK may be changed via unlocking seq)
#pragma config OSCIOFNC = ON       // Primary Oscillator I/O Function (CLKO/RC15 functions as I/O pin)
#pragma config FCKSM = CSECME      // Clock Switching and Monitor (Clock switching is enabled, 
                                       // Fail-Safe Clock Monitor is enabled)
#pragma config FNOSC = FRCPLL      // Oscillator Select (Fast RC Oscillator with PLL module (FRCPLL))

int main(void) {
    
    lcd_init();
    
    while(1){
        
        LATBbits.LATB7 = !LATBbits.LATB7;
        
        // 0x49
        // 0x45
        // 0x45
        // 0x45
        
        lcd_cmd(0x49);
        lcd_cmd(0x45);
        lcd_cmd(0x45);
        lcd_cmd(0x45);
        
        lcd_cmd(0x5f);
        lcd_cmd(0x49);
        lcd_cmd(0x53);
        lcd_cmd(0x5f);
        
        lcd_cmd(0x5f);
        lcd_cmd(0x52);
        lcd_cmd(0x41);
        lcd_cmd(0x44);
        
        lcd_cmd(0x5f);
        lcd_cmd(0x5f);
        lcd_cmd(0x5f);
        lcd_cmd(0x5f);
        

        
        delay(1000);
        
        
    }
//    
//    setCursor(0,0);
//    
//    printChar('b');
//    
//    setCursor(1,0);
//    
//    printChar('a');
//    
//    setCursor(2,0);
//    
//    printChar('d');
//    
//    setCursor(3,1);
//    
//    printChar('g');
//    
//    setCursor(4,1);
//    
//    printChar('a');
//    
//    setCursor(5,1);
//    
//    printChar('m');
//    
//    setCursor(6,1);
//    
//    printChar('e');
    
//    lcd_printStr("Hey guys!");
//    
//    setCursor(0,1);
//    
//    lcd_printStr("Hey guys!");
    
    
    
//    loop();
    
    return 0;
    
}
