#include "I2C.h"

void wait_I2C(void)
{
    while ((SSPCON2 & 0x1F) ||  (SSPSTAT & 0x04)); 
}

void trans(unsigned int myByte)
{
    SSPBUF = myByte;
    return;
}

/*controlByte  = default I2C device; address = register to read from*/
void write(unsigned int controlByte, unsigned int address, unsigned int data)
{
    unsigned int temp;
    unsigned char address2 = controlByte;    
    
    wait_I2C();
    SSPCON2bits.SEN = 1;
    
    wait_I2C();

    address2 = address2<<1;
    
    trans(address2); /*control*/ 
    
    wait_I2C();
    trans(address); /*address*/
    
    wait_I2C();
    trans(data);
    
    wait_I2C();
    SSPCON2bits.PEN = 1; /*stop condition*/ 
}

unsigned int readWheel(unsigned int controlByte, unsigned int address)
{
    unsigned temp;
    unsigned char address2 = controlByte;    
    
    wait_I2C();
    SSPCON2bits.SEN = 1;
    
    wait_I2C();

    address2 = address2<<1;
    
    trans(address2); /*control*/ 
    
    wait_I2C();
    trans(address); /*address*/
    
    wait_I2C();
    SSPCON2bits.RSEN = 1; /*second start*/

    wait_I2C();    
    trans(address2+1); /*control byte*/

    wait_I2C();
    SSPCON2bits.RCEN = 1; /*receive enable*/

    wait_I2C();
    temp = SSPBUF; 
    SSPCON2bits.ACKDT = 0;

    wait_I2C();
    SSPCON2bits.PEN = 1; /*stop condition*/  

    return temp;
}

unsigned int calculate_degrees(unsigned int regH, unsigned int regL)
{
    /*To Be continued*/
    return 0xFF;
}

/* #############DEBUG FOR WHEEL AND PROX########################
void proxLED(unsigned int prox)
{
    if (prox < 0x50)
    {
        PORTAbits.RA2 = 0;
    }
    else
    {
        PORTAbits.RA2 = 1;
    }
    return;
}

void wheelLED(unsigned int wheel)
{
    if (wheel <180)
    {
        PORTDbits.RD5 = 1;
        PORTCbits.RC7 = 0;
    }
    else
    {
        PORTDbits.RD5 = 0;
        PORTCbits.RC7 = 1;       
    }
}
*/
