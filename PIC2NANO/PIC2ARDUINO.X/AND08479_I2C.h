/* 
 * File:   AND08479_LCD.h
 * Author: chase
 *
 * Created on March 30, 2021, 10:41 PM
 */

#ifndef AND08479_I2C_H
#define	AND08479_I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

void I2C_cmd(char Package);

void I2C_init(void);

void setCursor(char x, char y);

void printChar(char myChar);

void I2C_printStr(const char *s);

void shift(void);

void loop(void);


#ifdef	__cplusplus
}
#endif

#endif	/* AND08479_LCD_H */

