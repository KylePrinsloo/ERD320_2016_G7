/* 
 * File:   Main.c
 * Author: Alistair Yan
 *
 * Created on 02 September 2016, 5:13 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <p18f45k20.h>
#include "I2C.h"
#include "Light.h"
#include "Initialise.h"
#include "General.h"
#include "Temperature.h"

void main(void)
{
    /*main code*/
    /*initialize variables*/
    /*#######Light Stuff#######*/
    unsigned int light; //
    unsigned int lightRange;
    unsigned int lux;

    /*##########IQS624###########*/
    unsigned int WHEEL_LOW;
    unsigned int WHEEL_HIGH;

    /*##########proxsense##########*/
    unsigned int reg0; 
    unsigned int reg3; //Touch Bits Register
    unsigned int d = 8;
    //speed
    unsigned int reg_count1 = 1;
    //angle
    unsigned int reg_count2 = 1;
    unsigned int flag5 = 0;
    unsigned int flag3 = 0;
    unsigned int flag9 = 0;
    unsigned int flag11 = 0;
    
    /*####Wifi####*/
    unsigned int wifi_bool = 0;
    initialise(); /*initialise everything that needs to be on startup*/
    while(1)
    {
        reg0 = readWheel(0x64, 0x00);
        delay(d);
        reg3 = readWheel(0x64, 0x03);
        delay(d);
        
        /*determining data from wheel*/
        if ((reg3 == 11) && (flag11 == 0))
        {
            flag11 = 1;
        }
        if ((reg3 == 5) && (flag5 == 0))
        {
            flag5 = 1;
        }
        if ((reg3 != 5) && (flag5 == 1))
        {
            flag5 == 0;
        }
        if ((reg3 != 5) && (flag11 == 1))
        {
            flag11 = 0;
        }
        if ((reg3 == 9) && (flag9 == 0))
        {
            flag9 = 1;
        }
        if ((reg3 != 9) && (flag9 == 1))
        {
            flag9 = 0;
            if (flag5 == 1)
            {
                reg_count1++;
            }
            else
            {
                reg_count2++;
            }
        }
        if ((reg3 == 3) && (flag3 == 0))
        {
            flag3 = 1;
        }
        if ((reg3 != 3) && (flag3 == 1))
        {
            flag3 = 0;
            if (flag5 == 1)
            {
                reg_count1++;
            }
            else
            {
                reg_count2++;
            }
        }
       
        //direction of fan
        if (flag11 == 0)
        {
            //change direction of fan
            PORTBbits.RB0 = 0;
            PORTBbits.RB1 = 1;
        }
        else
        {
            //change direction of fan
            PORTBbits.RB0 = 0;
            PORTBbits.RB1 = 0;            
        }
        //speed control
        switch (reg_count1)
        {
            case 0:
            {
                reg_count1 = 1;
                break;
            }
            case 1:
            {
                //set fan speed
                PORTDbits.RD6 = 1;
                PORTDbits.RD7 = 1;
                break;
            }
            case 2:
            {
                //set fan speed
                PORTDbits.RD6 = 1;
                PORTDbits.RD7 = 0;
                break;
            }
            case 3:
            {
                //set fan speed
                PORTDbits.RD6 = 0;
                PORTDbits.RD7 = 1;
                break;
            }
            case 4:
            {
                //set fan speed
                PORTDbits.RD6 = 0;
                PORTDbits.RD7 = 0;
                break;
            }
            case 5:
            {
                //set fan speed
                reg_count1 = 4;
                break;
            }
        }
        
        switch (reg_count2)
        {
            case 0:
            {
                reg_count2 = 1;
                break;
            }
            case 1:
            {
                //set fan angle
                PORTDbits.RD4 = 1;
                PORTDbits.RD5 = 1;
                break;
            }
            case 2:
            {
                //set fan angle
                PORTDbits.RD4 = 1;
                PORTDbits.RD5 = 0;
                break;
            }
            case 3:
            {
                //set fan angle
                PORTDbits.RD4 = 0;
                PORTDbits.RD5 = 1;
                break;
            }
            case 4:
            {
                //set fan angle
                PORTDbits.RD4 = 0;
                PORTDbits.RD5 = 0;
                break;
            }
            case 5:
            {
                reg_count2 = 4;
                break;
            }
        }
        
        if (flag5 == 0)
        {
            //set LED
            PORTBbits.RB0 = 1;
            PORTBbits.RB1 = 1;
        }
        else
        {
            //set LED
            PORTBbits.RB0 = 1;
            PORTBbits.RB1 = 0;
        }
        
        if (wifi_bool == 1)
        {
            PORTBbits.RB3 = 0;
        }
        else
        {
            PORTBbits.RB3 = 1;
        }
        
        //reading light and calculate LUX        
        light = readLightADC();
        lightRange = set_light_range(light);
        lux = calculate_lux(light);
                
        
        //WHEEL_LOW = readWheel(0x44, 0x80);
        //delay(8);
        //WHEEL_HIGH = readWheel(0x44, 0x81);
        //delay(8);       
        
        //display_temp(1,1,1,1);
        Nop();
        Nop();
        Nop();
    }
}




 

