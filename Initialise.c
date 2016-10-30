/* 
 * File:   Initialise.c
 * Author: Alistair Yan
 *
 * Created on 08 September 2016, 7:02 PM
 */

#include "Initialise.h"

void initialise(void)
{   
    /*initialize ports*/
    ANSEL = 0;
    PORTA = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    
    LATA = 0;
    LATB = 0;
    LATC = 0;
    LATD = 0;
    LATE = 0;
    
    /*LED STUFF*/
    TRISEbits.TRISE2 = 1; /*input AN7*/
    ANSELbits.ANS7= 1; /*input AN7*/
    
    TRISAbits.RA7   = 0; /*output B0*/
    TRISCbits.RC5   = 0; /*output B1*/
    
    /*TEMPERATURE OUTPUT STUFF*/
    TRISAbits.RA0 = 0;
    TRISAbits.RA1 = 0;
    TRISAbits.RA2 = 0;
    TRISBbits.RB7 = 0;
    TRISAbits.RA4 = 0;
    TRISAbits.RA6 = 0;
    TRISBbits.RB5 = 0;
    TRISBbits.RB6 = 0;
    
    /*SPEED/ANGLE STUFF/ WIFI HMI STUFF*/
    TRISDbits.RD4 = 0;
    TRISDbits.RD5 = 0;
    TRISDbits.RD6 = 0;
    TRISDbits.RD7 = 0;
    TRISBbits.RB0 = 0;
    TRISBbits.RB1 = 0;
    TRISBbits.RB3 = 0;
    
    /*I2C STUFF*/
    TRISCbits.RC3   = 1;
    TRISCbits.RC4   = 1;
    
    /*Initialise registers*/
    
    /*Clock 4MHz*/
    OSCCONbits.IRCF = 0b101;
    
    /*Enable Interrupts*/
    INTCONbits.GIE = 1;
    
    /*I2C Registers*/
    SSPADD = 0x25;
    SSPCON1 = 0b00101000;
    SSPCON2 = 0;
    SSPSTAT = 0b10000000;
    
    /*ADC Registers*/
    ADCON1 = 0b00000000; /*Use Vss and Vdd*/
    ADCON2 = 0b00000110; /*Left Justify, 8 TAD, FOSC/64*/
}

