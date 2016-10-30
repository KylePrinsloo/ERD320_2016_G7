#include "wifi.h"

void initSerial(void)
{
    INTCONbits.GIE      = 0;
    //Set the TX and RX pins
    TRISCbits.RC6       = 0;
    TRISCbits.RC7       = 1;
    //Enable receive interrupt
    PIE1bits.RCIE       = 1;
    
    TXSTA               = 0x0;
    //Set as asynchronous
    TXSTAbits.SYNC      = 0;
    //Set as high baud rate
    TXSTAbits.BRGH      = 1;
    //Enable the transmitter
    TXSTAbits.TXEN      = 1;
    
    RCSTA               = 0x0;
    //
    RCSTAbits.SPEN      = 1;
    //
    RCSTAbits.CREN      = 1;
    
    
    BAUDCON             = 0x0;
    //Set to 16 bit baud generator
    BAUDCONbits.BRG16   = 1;
    
    //set the baudrate with SPBRG and SPBRGH
    SPBRG               = 25;
    SPBRGH              = 0;
    
    //Clear the transmit flag
    PIR1bits.TXIF       = 0;
    
    //set the peripheral interrupt
    INTCONbits.PEIE     = 1;
    
    INTCONbits.GIE = 1;

    delay(2000);
    
    CWMODE();
    CIPMUX();
    CIPMODE();
    CIPSTART();
    delay(400);
    //CIPSEND();
    return;
}

void CWMODE(void)
{
    char cwModeStr[12] = "AT+CWMODE=1";
    
    int i;
    char c;
    for(i = 0; i < 11; i++){
        c = cwModeStr[i];
        transmit_char(c);
    }
    ENDCMD();
}

void CIPMUX(void)
{
    char mConStr[12] = "AT+CIPMUX=0";
    
    int i;
    char c;
    for(i = 0; i < 11; i++){
        c = mConStr[i];
        transmit_char(c);
    }
    
    ENDCMD();
}

int CIPMODE(void)
{
    char cipmodeStr[13] = "AT+CIPMODE=1";
    
    int i;
    char c;
    for(i = 0; i < 12; i++){
        c = cipmodeStr[i];
        transmit_char(c);
    }
    
    ENDCMD();
}

int CIPSTART(void)
{
    char cipstart[13] = "AT+CIPSTART=";
    char tcp[4] = "TCP";
    char ipaddress[12] = "192.168.4.1";
    char c;
    int i;
    
    for(i = 0; i < 12; i++)
    {
        c = cipstart[i];
        transmit_char(c);
    }
    
    transmit_char('"');
    
    for(i = 0; i < 3; i++)
    {
        c = tcp[i];
        transmit_char(c);
    }
    
    transmit_char('"');
    transmit_char(',');
    transmit_char('"');

    for(i = 0; i < 11; i++)
    {
        c = ipaddress[i];
        transmit_char(c);
    }
    
    transmit_char('"');
    transmit_char(',');
    transmit_char('8');
    
    ENDCMD();
}

int CIPSEND(void)
{
    char cipsendStr[11] = "AT+CIPSEND";
    
    int i;
    char c;
    for(i = 0; i < 10; i++){
        c = cipsendStr[i];
        transmit_char(c);
    }    
    
    ENDCMD();
}

void ENDSEND(void)
{
    char endstr[4] = "+++";
    int i;
    char c;
    for(i=0;i<3;i++)
    {
        c = endstr[i];
        transmit_char(c);
    }
}

void CIPCLOSE(void)
{
    char cipclose[12] = "AT+CIPCLOSE";
    char c;
    int i;
    
    for(i = 0; i < 11; i++)
    {
        c = cipclose[i];
        transmit_char(c);
    }
    
    ENDCMD();
}

void ENDCMD(void)
{
    transmit_char(13);
    transmit_char(10);
}

void transmit_char(char ch)
{
    TXREG=ch;
    delay(4);
    return;
}
