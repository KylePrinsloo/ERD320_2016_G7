#include "motor.h"
int dcDirection;//0 for forward, 1 for reverse
int speed;
int position;
int pos0, pos1, pos2, pos3;

void moveStepper(int newPos)
{
    int wheel_low, wheel_high, wheel, diff, x;
    /*wheel_low  = readWheel(0x44, 0x80);
    delay(8);
    wheel_high = readWheel(0x44, 0x81);
    wheel = wheel_low + wheel_high;*/
    
    /*
     Define position numbering in clockwise direction
     */
    /*while(position != newPos)
    {
        switch(newPos)
        {
            case 0:
            {
                
                break;
            }
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
        }*/
    for(x = 0; x < 400*(newPos);  x++)
    {
        if(newPos > position)
        {           
            //counter clockwise
            PORTDbits.RD3 = STEP_OFF;
            PORTDbits.RD0 = STEP_ON;
            PORTDbits.RD1 = STEP_OFF;
            PORTDbits.RD2 = STEP_OFF;
            
            delay_small(1);
            PORTDbits.RD0 = STEP_OFF;
            PORTDbits.RD1 = STEP_ON;
            PORTDbits.RD2 = STEP_OFF;
            PORTDbits.RD3 = STEP_OFF;
            delay_small(1);
            PORTDbits.RD0 = STEP_OFF;
            PORTDbits.RD1 = STEP_OFF;
            PORTDbits.RD2 = STEP_ON;
            PORTDbits.RD3 = STEP_OFF;
            delay_small(1);
            PORTDbits.RD0 = STEP_OFF;
            PORTDbits.RD1 = STEP_OFF;
            PORTDbits.RD2 = STEP_OFF;
            PORTDbits.RD3 = STEP_ON;
            delay_small(1);
        }
        else
        {
            //Clockwise
            PORTDbits.RD0 = STEP_OFF;
            PORTDbits.RD3 = STEP_ON;
            PORTDbits.RD2 = STEP_OFF;
            PORTDbits.RD1 = STEP_OFF;
            delay_small(1);
            PORTDbits.RD3 = STEP_OFF;
            PORTDbits.RD2 = STEP_ON;
            PORTDbits.RD1 = STEP_OFF;
            PORTDbits.RD0 = STEP_OFF;
            delay_small(1);   
            PORTDbits.RD3 = STEP_OFF;
            PORTDbits.RD2 = STEP_OFF;
            PORTDbits.RD1 = STEP_ON;
            PORTDbits.RD0 = STEP_OFF;
            delay_small(1);   
            PORTDbits.RD3 = STEP_OFF;
            PORTDbits.RD2 = STEP_OFF;
            PORTDbits.RD1 = STEP_OFF;
            PORTDbits.RD0 = STEP_ON;
            delay_small(1);
        }
        
        
        /*wheel_low  = readWheel(0x44, 0x80);
        delay(8);
        wheel_high = readWheel(0x44, 0x81);
        wheel = wheel_low + wheel_high;
        
        if(((pos0 - 5)< wheel)&&(wheel < (pos0+5)))
        {
            position = 0;
        }
        else if(((pos1 - 5) < wheel)&&(wheel < (pos1+5)))
        {
            position = 1;
        }
        else if(((pos2 - 5) < wheel)&&(wheel < (pos2+5)))
        {
            position = 2;
        }
        else if(((pos3 - 5) < wheel)&&(wheel < (pos3+5)))
        {
            position = 3;
        }*/
    }
    position = newPos;
}

void changeDCDir(int dir)
{
    if(dir != dcDirection)
    {
        dcDirection = dir;

        CCP1CONbits.DC1B0 = 0;
        CCP1CONbits.DC1B1 = 0;
        CCPR1L = 0;
        
        CCP2CONbits.DC2B0 = 0;
        CCP2CONbits.DC2B1 = 0;
        CCPR2L = 0;
        delay(1);
    }
}

void changeDCSpeed(int newSpeed)
{       
    if(dcDirection == 0)
    {
        if(speed != newSpeed)
        {
            speed = newSpeed;
            
            switch(speed)
            {
                case 0://off
                {  
                    CCPR1L = 0;
                    break;
                }
                case 1://slow 35%
                {
                    CCPR1L = SLOW;
                    break;
                }
                case 2://medium 65%
                {
                    CCPR1L = MEDIUM;
                    break;
                }
                case 3:///fast 95%
                {
                    CCPR1L = FAST;
                    break;
                }
            }
        }       
    }
    else
    {
        if(speed != newSpeed)
        {
            speed = newSpeed;
            
            switch(speed)
            {
                case 0://off
                {  
                    //set PWM to 100% for 
                    CCPR2L = 0;
                    break;
                }
                case 1://slow 35%
                {
                    CCPR2L = SLOW;
                    break;
                }
                case 2://medium 65%
                {
                    CCPR2L = MEDIUM;
                    break;
                }
                case 3:///fast 95%
                {
                    CCPR2L = FAST;
                    break;
                }
            }
        }
    }
}

void motorInit()
{
    //init dc dir
    dcDirection = 1;
    speed = 0;
    
    position = 0;
    
    pos0 = 0;
    pos1 = 85;
    pos2 = 170;
    pos3 = 255;
    
    //set stepper outputs to 0
    PORTDbits.RD0 = STEP_OFF;
    PORTDbits.RD1 = STEP_OFF;
    PORTDbits.RD2 = STEP_OFF;
    PORTDbits.RD3 = STEP_OFF;
    
    //Disable PWM pins
    TRISCbits.RC1 = 1;
    TRISCbits.RC2 = 1;
    
    //Clear CCP1 register
    CCP1CON = 0;
    //Set CCP1 PWM to 0
    CCP1CONbits.DC1B0 = 0;
    CCP1CONbits.DC1B1 = 0;
    CCPR1L = 0;
    //Set the CCP1 module to PWM mode
    CCP1CONbits.CCP1M0 = 0;
    CCP1CONbits.CCP1M1 = 0;
    CCP1CONbits.CCP1M2 = 1;
    CCP1CONbits.CCP1M3 = 1;
    //SET the CCP1/ECCP module to single output
    CCP1CONbits.P1M0 = 0;
    CCP1CONbits.P1M1 = 0;    
    
    //Clear CCP2 register
    CCP2CON = 0;
    //Set CCP2 PWM to 0
    CCP2CONbits.DC2B0 = 0;
    CCP2CONbits.DC2B1 = 0;
    CCPR2L = 0;
    //Set the CCP2 module to PWM mode
    CCP2CONbits.CCP2M0 = 0;
    CCP2CONbits.CCP2M1 = 0;
    CCP2CONbits.CCP2M2 = 1;
    CCP2CONbits.CCP2M3 = 1;  
    
    //Set the PWM frequency to 10KHz
    PR2 = 99;
    
    //Turn off timer 2
    T2CONbits.TMR2ON = 0;
    
    //Clear timer 2 interrupt flag
    PIR1bits.TMR2IF = 0;
    //Set Timer 2 pre scaler to 1
    T2CONbits.T2CKPS0 = 0;
    T2CONbits.T2CKPS1 = 0;
    
    //Turn Timer 2 On
    T2CONbits.TMR2ON = 1;

    while(!PIR1bits.TMR2IF);
    
    //Enable PWM pins
    TRISCbits.RC1 = 0;
    TRISCbits.RC2 = 0;
    TRISDbits.RD0 = 0;
    TRISDbits.RD1 = 0;
    TRISDbits.RD2 = 0;
    TRISDbits.RD3 = 0;
    return;
}

int getDir()
{
    return dcDirection;
}

int getPos()
{
    return position;
}

int getSpeed()
{
    return speed;
}

