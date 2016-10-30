/* 
 * File:   wifi.h
 * Author: Kyle
 *
 * Created on October 30, 2016, 8:31 AM
 */

#ifndef WIFI_H
#define	WIFI_H
#include "General.h"
#include <p18f45k20.h>
#ifdef	__cplusplus
extern "C" {
#endif
    
//extern int hashBit = 0;
//extern int lightBit = 0;
//extern int mesErrBit = 0;

void initSerial(void);
void CWMODE(void);
void CIPMUX(void);
int CIPMODE(void);
int CIPSTART(void);
int CIPSEND(void);
void ENDSEND(void);
void CIPCLOSE(void);
void ENDCMD(void);
void transmit_char(char ch);


#ifdef	__cplusplus
}
#endif

#endif	/* WIFI_H */

