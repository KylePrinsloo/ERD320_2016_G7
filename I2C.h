/* 
 * File:   I2C.h
 * Author: Alistair Yan
 *
 * Created on 08 September 2016, 6:47 PM
 */

#ifndef I2C_H
#define	I2C_H
#include <p18f45k20.h>

void trans(unsigned int);
void wait_I2C(void);
unsigned int readWheel(unsigned int, unsigned int);
unsigned int calculate_degrees(unsigned int, unsigned int);
void write(unsigned int controlByte, unsigned int address, unsigned int data);

/*
void proxLED(unsigned int);
void wheelLED(unsigned int);
*/

#endif	/* I2C_H */

