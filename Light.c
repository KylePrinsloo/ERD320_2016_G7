/* 
 * File:   Light.c
 * Author: Alistair Yan
 *
 * Created on 08 September 2016, 7:19 PM
 */
#include "Light.h"
#include "General.h"


/* reading ADC*/
unsigned int readLightADC(void)
{
    unsigned int temp;
    ADCON0 = 0b00011101; /*turn ADC on, AN7*/
    
    delay(1);
    ADCON0bits.GO = 1;
    while (ADCON0bits.DONE == 1);
    temp = ADRESH;
    return temp;
}

/*return light range*/
unsigned int set_light_range(unsigned int light)
{
    if (light < 85)
    {
        PORTAbits.RA7 = 1;
        PORTCbits.RC5 = 1;
        return 0;
    }
    else if (light < 170)
    {
        PORTAbits.RA7 = 0;
        PORTCbits.RC5 = 1;
        return 1;
    }
    else
    {
    PORTAbits.RA7 = 1;
    PORTCbits.RC5 = 0;
    return 2;
    }
}

unsigned int calculate_lux(unsigned int light)
{
    unsigned int temp;
    unsigned int scaling_factor = 1000;
    
    temp = light * scaling_factor;
    return temp;    
}