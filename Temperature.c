#include "Temperature.h"
#include "General.h"

void display_temp(unsigned int temp1, unsigned int temp2,unsigned int temp3,unsigned int temp4)
{
    PORTAbits.RA6 = 1;
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 1;
    PORTAbits.RA2 = 1;
    PORTBbits.RB7 = 1;
    PORTAbits.RA4 = 1;
    PORTBbits.RB5 = 1;
    PORTBbits.RB6 = 1;
    delay(150);
    PORTAbits.RA6 = 1;
    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 1;
    PORTAbits.RA2 = 0;
    PORTBbits.RB7 = 1;
    PORTAbits.RA4 = 0;
    PORTBbits.RB5 = 1;
    PORTBbits.RB6 = 0;
    delay(150);
    PORTAbits.RA6 = 0;
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 0;
    PORTAbits.RA2 = 1;
    PORTBbits.RB7 = 0;
    PORTAbits.RA4 = 1;
    PORTBbits.RB5 = 0;
    PORTBbits.RB6 = 1;
    delay(150);
    PORTAbits.RA6 = 0;
    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA2 = 0;
    PORTBbits.RB7 = 0;
    PORTAbits.RA4 = 0;
    PORTBbits.RB5 = 0;
    PORTBbits.RB6 = 0;
    delay(150);
    /*
    PORTAbits.RA2 = 0;
    PORTBbits.RB7 = 0;
    PORTAbits.RA4 = 0;
    PORTAbits.RA6 = 0;
    PORTBbits.RB6 = 0;
    PORTBbits.RB5 = 0;
    delay(100);
    /*
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 0;
    PORTAbits.RA2 = 1;
    PORTAbits.RA3 = 0;
    PORTAbits.RA4 = 1;
    PORTAbits.RA6 = 0;
    PORTBbits.RB6 = 1;
    PORTBbits.RB5 = 0;
    delay(100);
    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 1;
    PORTAbits.RA2 = 0;
    PORTAbits.RA3 = 1;
    PORTAbits.RA4 = 0;
    PORTAbits.RA6 = 1;
    PORTBbits.RB6 = 0;
    PORTBbits.RB5 = 1;
    delay(100);
    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA2 = 0;
    PORTAbits.RA3 = 0;
    PORTAbits.RA4 = 0;
    PORTAbits.RA5 = 0;
    PORTBbits.RB6 = 0;
    PORTBbits.RB5 = 0;
    delay(100);
     * */
    /*PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 1;
    PORTAbits.RA2 = 1;
    PORTAbits.RA3 = 1;
    PORTAbits.RA4 = 1;
    PORTAbits.RA5 = 1;
    PORTBbits.RB5 = 1;
    PORTBbits.RB4 = 1;    
    delay(80);
    */
    /*
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 0;
    PORTAbits.RA2 = 1;
    PORTAbits.RA3 = 0;
    PORTAbits.RA4 = 1;
    PORTAbits.RA5 = 0;
    PORTBbits.RB4 = 1;
    PORTBbits.RB5 = 0;
    delay(80);
     * PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 1;
    PORTAbits.RA2 = 0;
    PORTAbits.RA3 = 1;
    PORTAbits.RA4 = 0;
    PORTAbits.RA5 = 1;
    PORTBbits.RB4 = 0;
    PORTBbits.RB5 = 1;
    delay(80);
    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA2 = 0;
    PORTAbits.RA3 = 0;
    PORTAbits.RA4 = 0;
    PORTAbits.RA5 = 0;
    PORTBbits.RB5 = 0;
    PORTBbits.RB4 = 0;
    delay(80);*/
}